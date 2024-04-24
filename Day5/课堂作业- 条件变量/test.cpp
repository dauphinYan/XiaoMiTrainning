#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waiting_thread() {
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "Waiting for the condition..." << std::endl;
    cv.wait(lck, []{ return ready; });
    std::cout << "Condition satisfied. Continuing execution." << std::endl;
}

void modifying_thread() {
    {
        std::lock_guard<std::mutex> lck(mtx);
        ready = true;
    }
    cv.notify_one();
}

int main() {
    std::thread t1(waiting_thread);
    system("read -p 'Press Enter to continue...' var");
    std::thread t2(modifying_thread);

    t1.join();
    t2.join();

    return 0;
}

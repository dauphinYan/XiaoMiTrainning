#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>

const int NUM_PHILOSOPHERS = 5;

std::mutex forks[NUM_PHILOSOPHERS];
std::mt19937 rng(std::random_device{}());

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    if (id == NUM_PHILOSOPHERS - 1) {
        std::swap(left_fork, right_fork);
    }

    std::uniform_int_distribution<int> distribution(100, 1000);

    while (true) {
        int think_time = distribution(rng);
        std::cout << "Philosopher " << id << " is thinking for " << think_time << " milliseconds." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(think_time));

        forks[left_fork].lock();
        forks[right_fork].lock();

        int eat_time = distribution(rng);
        std::cout << "Philosopher " << id << " is eating for " << eat_time << " milliseconds." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(eat_time));

        forks[left_fork].unlock();
        forks[right_fork].unlock();
    }
}

int main() {
    std::thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}

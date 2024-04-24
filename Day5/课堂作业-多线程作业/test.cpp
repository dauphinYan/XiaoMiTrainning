#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
using namespace std;

atomic<int> global_counter(0);

void increase_global(int n)
{
    for (int i = 0; i < n; ++i)
    {
        ++global_counter;
    }
}

void increase_reference(atomic<int> &variable, int n)
{
    for (int i = 0; i < n; ++i)
    {
        ++variable;
    }
}

struct C
{
    atomic<int> counter{0}; 
    void increase_member(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            counter.fetch_add(1);
        }
    }
};

int main()
{
    vector<thread> threads;

    cout << "increase global counter with 10 threads...\n";
    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(thread(increase_global, 1000));
    }

    cout << "increase counter(foo) with 10 threads using reference...\n";
    atomic<int> foo(0);
    for (int i = 1; i <= 10; ++i)
    {
        threads.push_back(thread(increase_reference, ref(foo), 1000));
    }

    cout << "increase counter (bar) with 10 threads using member...\n";
    C bar;
    for (int i = 1; i <= 10; ++i)
    {
        threads.push_back(thread(&C::increase_member, ref(bar), 1000));
    }

    cout << "syschronizing all threads...\n";
    for (auto &th : threads)
    {
        th.join();
    }

    cout << "global_counter:" << global_counter << "\n";
    cout << "foo:" << foo << "\n";
    cout << "bar:" << bar.counter << "\n";

    return 0;
}

#include <iostream>
#include "../include/threadpool.hpp" // the to be written pool

ThreadPool TP(8);
int main()
{
    // function to be processed by threads
    auto square = [](const uint64_t x)
    {
        return x * x;
    };

    // more tasks than threads in the pool
    const uint64_t num_tasks = 32;
    std::vector<std::future<uint64_t>> futures;

    // enqueue the tasks in a linear fashion
    for (uint64_t task = 0; task < num_tasks; task++)
    {
        auto future = TP.enqueue(square, task);
        futures.emplace_back(std::move(future));
    }

    // wait for the results
    for (auto &future : futures)
        std::cout << future.get() << std::endl;
}
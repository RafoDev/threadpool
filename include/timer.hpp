#ifndef HPC_HELPERS_HPP
#define HPC_HELPERS_HPP

#include <chrono>

#define TIMERSTART(name) \
    auto name##_start = std::chrono::high_resolution_clock::now();

#define TIMERSTOP(name) \
    auto name##_stop = std::chrono::high_resolution_clock::now(); \
    auto name##_duration = std::chrono::duration_cast<std::chrono::microseconds>(name##_stop - name##_start); \
    std::cout << #name << " execution time: " << name##_duration.count() << " microseconds" << std::endl;

#endif // HPC_HELPERS_HPP
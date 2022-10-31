#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include <chrono>

#include <time.h>

static inline uint64_t _time_us()
{
    struct timespec ts;
    clock_gettime(0 /* CLOCK_REALTIME */, &ts);
    uint64_t res = 0;
    res += ts.tv_sec * 1000000;
    res += ts.tv_nsec / 1000;

    return res;
}

#define TIME_MEASURE_START(n) uint64_t _befus_ ## n =  _time_us()
#define TIME_MEASURE_END(n) fprintf(stderr, #n " : %luus elapsed\n", _time_us() - _befus_ ## n)

#endif
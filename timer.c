#include "timer.h"

double timer_func_single(timed_func fn)
{
    double result_time;
    TIMING_FUNCTION_CODE(fn, result_time);
    return result_time;
}

void timer_func_multi(timed_func fn, double* laps, size_t lap_count)
{
    while(lap_count--) {
        TIMING_FUNCTION_CODE(fn, *laps++);
    }
}
#ifndef FAST_HASH_TIMER_H
#define FAST_HASH_TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This macro represents an inlined, identical portion of code used to time any function.
 * This is such that different abstractions of timings are not affected by function call overhead.
 */
 #define TIMING_FUNCTION_CODE(fn, result) do { \
    clock_t start, end; \
    start = clock(); \
    (fn)(); \
    end = clock(); \
    (result) = ((double) (end - start)) / CLOCKS_PER_SEC; \
    } while(0)

/**
 * For consistency, a timeable function should not return or accept anything
 */
typedef void (*timed_func)(void);

/**
 * Used to measure different functions against each other.
 */
typedef struct {
    timed_func fn;
    double timed;
} func_time_slot;

double timer_func_single(timed_func fn);

void timer_func_multi(timed_func fn, double* laps, size_t lap_count);

void timer_funcs_multi(func_time_slot* fns, size_t pair_count);

#endif // FAST_HASH_TIMER_H

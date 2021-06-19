#ifndef BENCHMARK_BENCHMARK_GENERAL_H
#define BENCHMARK_BENCHMARK_GENERAL_H

#include <cstdint>

#define KEY_TYPE       uint8_t
#define MAP_KEY        uint8_t
#define RETURN_VOID    return
#define RETURN_ZERO    return 0
#define RETURN_TIME(T) return T

#define DEFAULT_ARG = 0
#define ARG_REPLACE

#define START_TIMER             DLL void    CALL StartTimer           (KEY_TYPE n DEFAULT_ARG)
#define STOP_TIMER              DLL void    CALL StopTimer            (KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_SECONDS       DLL int64_t CALL GetTimerSeconds      (KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_MILLI_SECONDS DLL int64_t CALL GetTimerMilliSeconds (KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_MICRO_SECONDS DLL int64_t CALL GetTimerMicroSeconds (KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_NANO_SECONDS  DLL int64_t CALL GetTimerNanoSeconds  (KEY_TYPE n DEFAULT_ARG)
#define DESTROY_TIMER           DLL void    CALL DestroyTimer         (KEY_TYPE n DEFAULT_ARG)

START_TIMER;
STOP_TIMER;
GET_TIMER_SECONDS;
GET_TIMER_MILLI_SECONDS;
GET_TIMER_MICRO_SECONDS;
GET_TIMER_NANO_SECONDS;
DESTROY_TIMER;

#endif //BENCHMARK_BENCHMARK_GENERAL_H

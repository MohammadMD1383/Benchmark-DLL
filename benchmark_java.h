#ifndef BENCHMARK_BENCHMARK_JAVA_H
#define BENCHMARK_BENCHMARK_JAVA_H

#include <jni.h>

#define KEY_TYPE       jbyte
#define MAP_KEY        jbyte
#define RETURN_VOID    return
#define RETURN_ZERO    return 0
#define RETURN_TIME(T) return T

#define DEFAULT_ARG = 0
#define ARG_REPLACE

#define START_TIMER             DLL void  CALL Java_ir_mmd_benchmark_Benchmark_startTimer           (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)
#define STOP_TIMER              DLL void  CALL Java_ir_mmd_benchmark_Benchmark_stopTimer            (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_SECONDS       DLL jlong CALL Java_ir_mmd_benchmark_Benchmark_getTimerSeconds      (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_MILLI_SECONDS DLL jlong CALL Java_ir_mmd_benchmark_Benchmark_getTimerMilliSeconds (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_MICRO_SECONDS DLL jlong CALL Java_ir_mmd_benchmark_Benchmark_getTimerMicroSeconds (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)
#define GET_TIMER_NANO_SECONDS  DLL jlong CALL Java_ir_mmd_benchmark_Benchmark_getTimerNanoSeconds  (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)
#define DESTROY_TIMER           DLL void  CALL Java_ir_mmd_benchmark_Benchmark_destroyTimer         (JNIEnv*, jclass, KEY_TYPE n DEFAULT_ARG)

START_TIMER;
STOP_TIMER;
GET_TIMER_SECONDS;
GET_TIMER_MILLI_SECONDS;
GET_TIMER_MICRO_SECONDS;
GET_TIMER_NANO_SECONDS;
DESTROY_TIMER;

#endif //BENCHMARK_BENCHMARK_JAVA_H

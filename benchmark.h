#ifndef BENCHMARK_BENCHMARK_H
#define BENCHMARK_BENCHMARK_H

#ifdef Benchmark_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#define CALL __stdcall

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GENERAL__
#include "benchmark_general.h"
#endif

#ifdef __JAVA__
#include "benchmark_java.h"
#endif

#ifdef __PYTHON__
#include "benchmark_python.h"
#endif

#ifdef __cplusplus
}
#endif

#endif //BENCHMARK_BENCHMARK_H

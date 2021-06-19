#ifndef BENCHMARK_BENCHMARK_PYTHON_H
#define BENCHMARK_BENCHMARK_PYTHON_H

#include <Python.h>

#define KEY_TYPE       PyObject*
#define MAP_KEY        char
#define RETURN_VOID    Py_RETURN_NONE
#define RETURN_ZERO    Py_RETURN_NONE
#define RETURN_TIME(T) return PyLong_FromLongLong(T)

#define DEFAULT_ARG
#define ARG_REPLACE              \
MAP_KEY n = 0;                   \
PyArg_ParseTuple(pyo, "|b", &n);

#define START_TIMER             KEY_TYPE start_timer             (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)
#define STOP_TIMER              KEY_TYPE stop_timer              (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)
#define GET_TIMER_SECONDS       KEY_TYPE get_timer_seconds       (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)
#define GET_TIMER_MILLI_SECONDS KEY_TYPE get_timer_milli_seconds (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)
#define GET_TIMER_MICRO_SECONDS KEY_TYPE get_timer_micro_seconds (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)
#define GET_TIMER_NANO_SECONDS  KEY_TYPE get_timer_nano_seconds  (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)
#define DESTROY_TIMER           KEY_TYPE destroy_timer           (KEY_TYPE, KEY_TYPE pyo DEFAULT_ARG)

START_TIMER;
STOP_TIMER;
GET_TIMER_SECONDS;
GET_TIMER_MILLI_SECONDS;
GET_TIMER_MICRO_SECONDS;
GET_TIMER_NANO_SECONDS;
DESTROY_TIMER;

static PyMethodDef methods[] = {
	{"start_timer",             (PyCFunction) start_timer,             METH_VARARGS, nullptr},
	{"stop_timer",              (PyCFunction) stop_timer,              METH_VARARGS, nullptr},
	{"get_timer_seconds",       (PyCFunction) get_timer_seconds,       METH_VARARGS, nullptr},
	{"get_timer_milli_seconds", (PyCFunction) get_timer_milli_seconds, METH_VARARGS, nullptr},
	{"get_timer_micro_seconds", (PyCFunction) get_timer_micro_seconds, METH_VARARGS, nullptr},
	{"get_timer_nano_seconds",  (PyCFunction) get_timer_nano_seconds,  METH_VARARGS, nullptr},
	{"destroy_timer",           (PyCFunction) destroy_timer,           METH_VARARGS, nullptr},
};

static PyModuleDef moduleDef = {
	PyModuleDef_HEAD_INIT,
	"Benchmark",
	nullptr,
	0,
	methods
};

PyMODINIT_FUNC PyInit_Benchmark() { return PyModule_Create(&moduleDef); }

#endif //BENCHMARK_BENCHMARK_PYTHON_H

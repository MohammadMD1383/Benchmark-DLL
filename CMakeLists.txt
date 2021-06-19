cmake_minimum_required(VERSION 3.19)

project(Benchmark)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} SHARED benchmark.cpp benchmark.h)

if (R__GENERAL__)
	target_compile_definitions(${PROJECT_NAME} PUBLIC -D__GENERAL__)
elseif (R__JAVA__)
	target_compile_definitions(${PROJECT_NAME} PUBLIC -D__JAVA__)
	target_include_directories(${PROJECT_NAME} PUBLIC "C:/Users/Mohammad/.jdks/corretto-1.8.0_292/include/")
	target_include_directories(${PROJECT_NAME} PUBLIC "C:/Users/Mohammad/.jdks/corretto-1.8.0_292/include/win32/")
elseif (R__PYTHON__)
	target_compile_definitions(${PROJECT_NAME} PUBLIC -D__PYTHON__)
	target_include_directories(${PROJECT_NAME} PUBLIC "C:/Program Files/WindowsApps/PythonSoftwareFoundation.Python.3.9_3.9.1520.0_x64__qbz5n2kfra8p0/include/")
	target_link_directories(${PROJECT_NAME} PUBLIC "C:/Program Files/WindowsApps/PythonSoftwareFoundation.Python.3.9_3.9.1520.0_x64__qbz5n2kfra8p0/libs/")
	set(CMAKE_SHARED_LIBRARY_SUFFIX .pyd)
endif ()

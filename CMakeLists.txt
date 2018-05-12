cmake_minimum_required(VERSION 3.5.1)
project(tomasulo_algorithm)

set( CMAKE_BUILD_TYPE Debug )
project( tomasulo_algorithm )

SET( GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -lm -fopenmp" )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
add_executable(
    TOMASULO_ALGORITHM
    src/main.cpp)

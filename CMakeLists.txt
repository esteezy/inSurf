cmake_minimum_required(VERSION 3.27)
project(inSurf)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Werror -pedantic")

include_directories(.)

add_executable(inSurf
        InSurf.cpp
        InSurf.h
        main.cpp
)

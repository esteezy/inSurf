cmake_minimum_required(VERSION 3.14)
project(inSurf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

include_directories(src/)

add_executable(inSurf
        src/InSurf.h
        src/InSurf.cpp
        src/main.cpp
)
include_directories(/usr/local/include)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(inSurf sfml-system sfml-window sfml-graphics sfml-audio sfml-network)



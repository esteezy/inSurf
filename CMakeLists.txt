cmake_minimum_required(VERSION 3.14)
project(HelloSFML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES ./src/main.cpp)

add_executable(
        inSurf
       ./src/InSurf.cpp
       ./src/InSurf.h
       ./src/main.cpp
       ./src/GameSupport.cpp
       ./src/GameSupport.h
       ./src/GameSupport.h
)
include_directories(/usr/local/include)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(inSurf sfml-system sfml-window sfml-graphics sfml-audio sfml-network)



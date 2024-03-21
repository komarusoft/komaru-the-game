cmake_minimum_required(VERSION 3.0)
project(komaru_the_game)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

set(CMAKE_C_COMPILER "clang")  
set(CMAKE_CXX_COMPILER "clang++")  

set(SOURCE src/main.cpp)
add_executable(komaru_the_game ${SOURCE})

target_link_libraries(komaru_the_game sfml-graphics sfml-window sfml-system)
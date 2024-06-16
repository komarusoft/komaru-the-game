cmake_minimum_required(VERSION 3.0)
project(komaru_the_game)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_subdirectory(json)
include_directories(${CMAKE_SOURCE_DIR}/json)


set(CMAKE_C_COMPILER "clang")  
set(CMAKE_CXX_COMPILER "clang++") 
 
option(DEBUG "Debug version?" OFF)
if(DEBUG)
    # Set Debug - for debug
    # Set Release - for release
    set(CMAKE_BUILD_TYPE Debug)
    add_compile_definitions(DEBUG)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCE 
    src/main.cpp
    src/MainMenu.cpp
    src/SettingsMenu.cpp
    )
add_executable(komaru_the_game ${SOURCE})

target_link_libraries(komaru_the_game PUBLIC sfml-graphics sfml-window sfml-system)
target_link_libraries(komaru_the_game PRIVATE nlohmann_json::nlohmann_json)
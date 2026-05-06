cmake_minimum_required(VERSION 3.10)
project(Hangman VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hangman hangman.cpp)

if(MSVC)
    target_compile_options(hangman PRIVATE /W4)
else()
    target_compile_options(hangman PRIVATE -Wall -Wextra -O2)
endif()

cmake_minimum_required(VERSION 3.17)
project(corewar C)

set(CMAKE_C_STANDARD 99)

add_definitions(-Wall -Wextra)

add_executable(corewar main.c corewar.h)
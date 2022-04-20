cmake_minimum_required(VERSION 3.22)
project(C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C
        array.c
        hello.c
        main.c string.c memory.c)

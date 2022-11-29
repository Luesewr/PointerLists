cmake_minimum_required(VERSION 3.21)
project(pointerList C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_HEADERS
        library/pointerList.h library/intList.h)

set(PROJECT_SOURCES
        main.c
        library/pointerList.c library/intList.c)

add_executable(main ${PROJECT_SOURCES} ${PROJECT_HEADERS})
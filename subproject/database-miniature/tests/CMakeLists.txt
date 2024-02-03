cmake_minimum_required(VERSION 3.27)
project(database-miniature-tests C)

set(CMAKE_C_STANDARD 11)

include_directories(../include)

add_executable(database-miniature-tests test1.c)
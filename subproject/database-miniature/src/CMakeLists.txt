cmake_minimum_required(VERSION 3.27)
project(database-system-sample C)

set(CMAKE_C_STANDARD 11)

add_executable(database-system-sample main.c)

include_directories(../include ../../../include ../../logger/include)

add_library(database-system database.c)
add_library(logger-system ../../logger/src/logger.c)

target_link_libraries(database-system-sample database-system logger-system)


cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

add_executable(SIMS main.c)

include_directories(../include)

add_library(datamanager components/datamanager.c)

target_link_libraries(SIMS datamanager)
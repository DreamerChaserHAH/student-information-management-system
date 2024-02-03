cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

add_executable(SIMS main.c)

include_directories(../include ../subproject/database-miniature/include)

add_library(database-miniature ../subproject/database-miniature/src/database.c)

target_link_libraries(SIMS database-miniature)
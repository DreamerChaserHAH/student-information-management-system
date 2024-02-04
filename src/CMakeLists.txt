cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

add_executable(SIMS main.c)

include_directories(../include ../subproject/database-miniature/include)

add_library(database-miniature ../subproject/database-miniature/src/database.c)
add_library(user-management components/login.c)
add_library(user-menu components/user-menu.c)
add_library(student-management components/menus/student-system.c)
add_library(color-printf components/utils/color-printf.c)

target_link_libraries(SIMS database-miniature user-management user-menu student-management color-printf)
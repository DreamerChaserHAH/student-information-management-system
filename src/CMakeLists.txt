cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

add_executable(SIMS main.c)

include_directories(../include ../subproject/database-miniature/include)

add_library(database-miniature ../subproject/database-miniature/src/database.c)
add_library(user-interface components/menus/user-interface.c)
add_library(test-functions components/utils/test-functions.c)
add_library(common-functions components/utils/common-functions.c)
add_library(student-system components/systems/student-system.c)
add_library(login components/login.c)

target_link_libraries(SIMS database-miniature user-interface test-functions common-functions student-system login)
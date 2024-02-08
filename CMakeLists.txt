cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(SIMS src/main.c)

add_executable(tests-file-interaction "tests/src/data management system/file-interaction-api-tests.c")
add_executable(tests-csv-processor "tests/src/data management system/csv-processor-api-tests.c")
add_executable(tests-user-data-api "tests/src/data management system/user-data-api-tests.c")
add_executable(tests-student-record-data-api "tests/src/data management system/student-record-data-api-tests.c")
add_executable(tests-programme-data-api "tests/src/data management system/programme-data-api-tests.c")
add_executable(tests-course-data-api "tests/src/data management system/course-data-api-tests.c")

include(CTest)

add_library(user-management src/components/login.c)
add_library(user-menu src/components/user-menu.c)
add_library(student-management src/components/menus/student-system.c)
add_library(color-printf src/components/utils/color-printf.c)

target_link_libraries(SIMS user-management user-menu student-management color-printf)

enable_testing()

add_test(file-interaction-tests tests-file-interaction)
add_test(csv-processor-tests tests-csv-processor)
add_test(user-data-api-tests tests-user-data-api)
add_test(student-record-data-api tests-student-record-data-api)
add_test(programme-data-api-tests tests-programme-data-api)
add_test(course-data-api-tests tests-course-data-api)

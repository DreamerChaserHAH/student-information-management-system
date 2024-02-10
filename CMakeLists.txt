cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(SIMS src/main.c)

add_library(datamanager-utilities "src/components/data management system/datamanager-utilities.c")
add_library(file-interaction-api "src/components/data management system/file-interaction-api.c")
add_library(csv-processor-api "src/components/data management system/csv-processor-api.c")
add_library(datamanager "src/components/data management system/datamanager.c")

add_executable(tests-datamanager-utilities "tests/src/data management system/datamanager-utilities-test.c")
add_executable(tests-file-interaction "tests/src/data management system/file-interaction-api-tests.c")
add_executable(tests-csv-processor-api "tests/src/data management system/csv-processor-api-tests.c")
add_executable(tests-user-data-api "tests/src/data management system/user-data-api-tests.c")
add_executable(tests-student-record-data-api "tests/src/data management system/student-record-data-api-tests.c")
add_executable(tests-programme-data-api "tests/src/data management system/programme-data-api-tests.c")
add_executable(tests-course-data-api "tests/src/data management system/course-data-api-tests.c")

include(CTest)

add_library(user-management src/components/login.c)
add_library(student-management src/components/systems/student-system.c)

target_link_libraries(SIMS user-management datamanager-utilities file-interaction-api csv-processor-api student-management)

target_link_libraries(tests-datamanager-utilities datamanager-utilities)
target_link_libraries(tests-file-interaction file-interaction-api datamanager-utilities  )
target_link_libraries(tests-csv-processor-api csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-user-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-student-record-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-programme-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-course-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)

enable_testing()

add_test(datamanager-utilities-tests tests-datamanager-utilities)
add_test(file-interaction-tests tests-file-interaction)
add_test(csv-processor-api-tests tests-csv-processor-api)
add_test(user-data-api-tests tests-user-data-api)
add_test(student-record-data-api tests-student-record-data-api)
add_test(programme-data-api-tests tests-programme-data-api)
add_test(course-data-api-tests tests-course-data-api)

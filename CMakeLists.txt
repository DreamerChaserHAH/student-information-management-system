set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
cmake_minimum_required(VERSION 3.27)
project(SIMS C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(SIMS src/main.c)

add_library(datamanager-utilities "src/components/data management system/datamanager-utilities.c")
add_library(file-interaction-api "src/components/data management system/file-interaction-api.c")
add_library(csv-processor-api "src/components/data management system/csv-processor-api.c"
        "include/user management system/user-management.h")
add_library(datamanager "src/components/data management system/datamanager.c")
add_library(main-interface "src/components/menus/main-interface.c")

add_library(student-options "src/components/menus/student-options.c")
add_library(user-management "src/components/user management system/user-management.c")
add_library(student-management "src/components/student management system/student-management.c")
add_library(login "src/components/user management system/login.c")
add_library(menu-utils src/components/menus/menu-utils.c)

target_link_libraries(SIMS main-interface student-options user-management student-management datamanager csv-processor-api file-interaction-api datamanager-utilities login menu-utils)

include(CTest)

add_executable(tests-datamanager-utilities "tests/src/data management system/datamanager-utilities-test.c")
set_target_properties(tests-datamanager-utilities PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-datamanager-utilities)

add_executable(tests-file-interaction "tests/src/data management system/file-interaction-api-tests.c")
set_target_properties(tests-file-interaction PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-file-interaction)

add_executable(tests-csv-processor-api "tests/src/data management system/csv-processor-api-tests.c")
set_target_properties(tests-csv-processor-api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-csv-processor-api)

add_executable(tests-user-data-api "tests/src/data management system/user-data-api-tests.c")
set_target_properties(tests-user-data-api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-user-data-api)

add_executable(tests-student-record-data-api "tests/src/data management system/student-record-data-api-tests.c")
set_target_properties(tests-student-record-data-api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-student-record-data-api)

add_executable(tests-programme-data-api "tests/src/data management system/programme-data-api-tests.c")
set_target_properties(tests-programme-data-api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-programme-data-api)

add_executable(tests-course-data-api "tests/src/data management system/course-data-api-tests.c")
set_target_properties(tests-course-data-api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-course-data-api)

add_executable(tests-add-user "tests/src/user management system/add-user-tests.c")
set_target_properties(tests-add-user PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-add-user)

#add_executable(tests-login "tests/src/user management system/login-tests.c")
# set_target_properties(tests-login PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests-login)


target_link_libraries(tests-datamanager-utilities datamanager-utilities)
target_link_libraries(tests-file-interaction file-interaction-api datamanager-utilities  )
target_link_libraries(tests-csv-processor-api csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-user-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-student-record-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-programme-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-course-data-api datamanager csv-processor-api file-interaction-api datamanager-utilities)
target_link_libraries(tests-add-user user-management login datamanager csv-processor-api file-interaction-api datamanager-utilities)
#target_link_libraries(tests-login user-management login datamanager csv-processor-api file-interaction-api datamanager-utilities)

enable_testing()

add_test(datamanager-utilities-tests ${CMAKE_BINARY_DIR}/tests-datamanager-utilities/tests-datamanager-utilities)
add_test(file-interaction-tests ${CMAKE_BINARY_DIR}/tests-file-interaction/tests-file-interaction)
add_test(csv-processor-api-tests ${CMAKE_BINARY_DIR}/tests-csv-processor-api/tests-csv-processor-api)
add_test(user-data-api-tests ${CMAKE_BINARY_DIR}/tests-user-data-api/tests-user-data-api)
add_test(student-record-data-api ${CMAKE_BINARY_DIR}/tests-student-record-data-api/tests-student-record-data-api)
add_test(programme-data-api-tests ${CMAKE_BINARY_DIR}/tests-programme-data-api/tests-programme-data-api)
add_test(course-data-api-tests ${CMAKE_BINARY_DIR}/tests-course-data-api/tests-course-data-api)
add_test(add-user-tests ${CMAKE_BINARY_DIR}/tests-add-user/tests-add-user)
#add_test(login-tests ${CMAKE_BINARY_DIR}/tests-login/tests-login)

#include <stdio.h>
#include <data management system/datamanager.h>
#include "common-functions.h"

void view_student_info(struct User *user);
void add_student();
struct StudentRecord *student_info(int student_id);

// ! Needs to be changed with database code
struct StudentRecord students[100] = {
        {74166, 1, 86, 100},
        {74141, 1, 98, 100},
};



// ! TEMPORARY FUNCTION
/// @brief Returns the student record for the given student ID
/// @param student_id The ID of the student
struct StudentRecord *student_info(int student_id) {
    for (int i = 0; i < 100; i++) {
        if (students[i].user_id == student_id) {
            return &students[i];
        }
    }
    return NULL;
}

void add_student() {
    printf("Add Student Function\n");
    // Call the function to add student here
}
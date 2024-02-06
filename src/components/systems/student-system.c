#include <stdio.h>
#include <datamanager.h>

void view_student_info(struct User *user);
void add_student();


/// @brief The student info
/// @param user The user object
void view_student_info(struct User *user) {
    printf("View Student Info Function\n");
    /// @brief View the student info
    // ! Here it needs to be changed with a function to check database for student info
    int student_id = user->user_id;
    char *student_name = user->displayname;
    printf("Student ID: %d\n", student_id);
    printf("Student Name: %s\n", student_name);
}

void add_student() {
    printf("Add Student Function\n");
    // Call the function to add student here
}
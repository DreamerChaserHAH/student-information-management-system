#include <stdio.h>
#include "menus/menu-utils.h"
#include "data management system/datamanager.h"
#include <student management system/student-management.h>

///@brief Student Info Options
void view_student_info(struct User *user, int student_id) {
    struct StudentRecord *student_info = get_student_record(student_id);
    if(student_info == NULL) {
        printf("No student record found for this user.\n");
        student_info_menu(user, 0);
    } else {
        printf("Attandace: %d", student_info->attendance);
    }
}

void view_student_enrolled_courses(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student Enrolled Courses\n");
    } else {
        printf("View Student Enrolled Courses for student id: %d\n", student_id);

    }
}

void view_student_course_score(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student Course Score\n");
    } else {
        printf("View Student Course Score for student: %d\n", student_id);
    }
}

void view_student_cgpa(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student CGPA\n");
    } else {
        printf("View Student CGPA for student: %d\n", student_id);
    }
}

void view_student_attendance_record(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student Attendance Record\n");
    } else {
        printf("View Student Attendance Record for student: %d\n", student_id);
    }
}


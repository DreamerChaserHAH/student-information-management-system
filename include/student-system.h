//
// Created by Administrator on 2/6/2024.
//

#ifndef SIMS_STUDENT_SYSTEM_H
#define SIMS_STUDENT_SYSTEM_H

/// @brief View the student information
/// @param user The user to be viewed
void view_student_info(struct User *user);

/// @brief Student information for the given student ID
/// @param student_id The ID of the student
struct StudentRecord *student_info(int student_id);


#endif //SIMS_STUDENT_SYSTEM_H

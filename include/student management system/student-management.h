#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

struct StudentRecord* get_student_record(int user_id);

bool is_user_student(char* username);

#endif // !STUDENT_MANAGEMENT_H
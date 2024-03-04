#ifndef STUDENT_INTERFACE_H
#define STUDENT_INTERFACE_H

void view_student_info(struct User *user, int student_id);
void view_student_enrolled_courses(struct User *user, int student_id);
void view_student_course_score(struct User *user, int student_id);
void view_student_cgpa(struct User *user, int student_id);
void view_student_attendance_record(struct User *user, int student_id);

#endif // STUDENT_INTERFACE_H

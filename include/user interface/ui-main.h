#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <data management system/datamanager.h>

void welcome_menu();
void logout_menu(struct User *user);

void login_menu();
void main_menu(struct User *user);
void student_info_menu(struct User *user, int student_id);
void student_management_menu(struct User *user, int student_id);
void user_management_menu(struct User *user);

// Options
void view_student_info(struct User *user);
void view_student_enrolled_courses(struct User *user, int student_id);

void add_user_option(struct User *user);
void remove_user_options(struct User *user);
void view_all_user_option(struct User *user);

#endif // UI_MAIN_H
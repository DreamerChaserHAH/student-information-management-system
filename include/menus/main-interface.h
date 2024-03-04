#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

/// @brief All the strings used in the main interface

// Titles
#define WELCOME_MENU_TITLE "Welcome Menu"
#define STUDENT_INFO_MENU_TITLE_STUDENT "%s's Info Menu"
#define STUDENT_INFO_MENU_TITLE "Student Info Menu"
#define USER_MANAGEMENT_MENU_TITLE "User Management Menu"
#define MENU_WELCOME "Welcome Menu Alt"
// #define

// Prompts
#define ROLE_PROMPT "Enter role (0,1,2,3):"
#define USERNAME_PROMPT "Enter username:"
#define PASSWORD_PROMPT "Enter password:"
#define STUDENT_ID_PROMPT "Enter student id:"
#define DISPLAY_NAME_PROMPT "Enter display name:"
#define ENTER_OPTION_PROMPT "Enter your option:"
#define REMOVE_USER_PROMPT "Are you sure you want to remove this user? (yes/no)"

// Validation Messages
#define VALID_USERNAME_MSG "Please enter a valid username."
#define VALID_PASSWORD_MSG "Please enter a valid password."
#define VALID_STUDENT_ID_MSG "Please enter a valid student id."
#define VALID_DISPLAY_NAME_MSG "Please enter a valid display name."

// Info Messages
#define WELCOME_MSG "Welcome to the system. Please create a user to continue."
#define LOGIN_SUCCESS_MSG "Welcome to the system %s!"
#define USER_ADDED_SUCCESS_MSG "User added successfully!"
#define USER_REMOVED_SUCCESS_MSG "User removed successfully!"
#define VIEW_ALL_USERS_MSG "View All Users"

// Error Messages
#define INVALID_LOGIN_MSG "Invalid username or password. Please try again."
#define USER_EXISTS_ERROR_MSG "User already exists!"
#define USER_NOT_EXIST_MSG "User does not exist!"
#define USER_NOT_REMOVED_ERROR_MSG "User not removed! [Internal Error]"
#define USER_NOT_REMOVED_MSG "User not removed!"
#define CANNOT_REMOVE_SELF_MSG "You cannot remove yourself!"

// Other
#define STUDENT_MANAGEMENT_MSG "Student Management"


/// @brief Options for the main interface
#define LOGIN_OPTION "Login"
#define EXIT_OPTION "Exit"
#define STUDENT_INFO_OPTION "Student Info"
#define STUDENT_MANAGEMENT_OPTION "Student Management"
#define USER_MANAGEMENT_OPTION "User Management"
#define LOGOUT_OPTION "Logout"
#define VIEW_INFO_OPTION_STUDENT "View Info"
#define VIEW_INFO_OPTION "View Student Info"
#define ENROLLED_COURSES_OPTION "Enrolled Courses"
#define RETURN_MAIN_MENU_OPTION "Return to Main Menu"
#define ADD_USER_OPTION "Add User"
#define REMOVE_USER_OPTION "Remove User"
#define VIEW_ALL_USERS_OPTION "View All Users"

/// ? END OF OPTIONS


void login_menu();
void main_menu(struct User *user);
void student_info_menu(struct User *user, int student_id);
void student_management_menu(struct User *user, int student_id);
void user_management_menu(struct User *user);

#endif // MAIN_INTERFACE_H

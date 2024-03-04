#include <stdio.h>
#include "menus/menu-utils.h"
#include "user management system/login.h"
#include <student management system/student-management.h>
#include <user management system/user-management.h>
#include <stdbool.h>
#include <time.h>

/// !!! Really considering making all the strings be in the header file and just be called from there

// I used itself, to make itself
#include "menus/main-interface.h"
// Options
#include "menus/student-options.h"

// ! Needs to be moved to a better place
void add_user_option(struct User *user);
void remove_user_options(struct User *user);
void view_all_user_option(struct User *user);

void welcome_menu() {

    int users = get_number_of_users();

    if(users == 0) {
        box_info(WELCOME_MSG, "menu");
        add_user_option(NULL);
    }

    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, LOGIN_OPTION, login_menu);
    add_option(&menu, LOGOUT_OPTION, exit_message);

    box_menu(&menu, WELCOME_MENU_TITLE);

    int option = option_input(ENTER_OPTION_PROMPT, &menu);
    option_handler(&menu, option, NULL);
}

void login_menu() {
    char *username = loop_input(USERNAME_PROMPT,VALID_USERNAME_MSG);
    char *password = loop_input(PASSWORD_PROMPT, VALID_PASSWORD_MSG);
    struct User *user = login(username, password);

    if(!user) {
        box_info_back(INVALID_LOGIN_MSG, "error", WELCOME_MENU_TITLE);
        welcome_menu();
    } else {
        char login_success[100];
        sprintf(login_success, LOGIN_SUCCESS_MSG, user->display_name);
        box_info(login_success, "success");
        main_menu(user);
    }
}


void main_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;
    int const user_role = user->role;

    if (user_role >= 0 && user_role <= 3) {
        // All Roles
        // * Working on this
        add_option(&menu, STUDENT_INFO_OPTION, student_info_menu);
    }
    if (user_role >= 1 && user_role <= 3) {
        // 1, 2, 3
        add_option(&menu, STUDENT_MANAGEMENT_OPTION, student_management_menu);
    }
    if (user_role >= 2 && user_role <= 3) {
        // 2, 3
    }
    if (user_role == 3) {
        // 3
        add_option(&menu, USER_MANAGEMENT_OPTION, user_management_menu);
    }

    add_option(&menu, LOGOUT_OPTION, logout);
    box_menu(&menu, RETURN_MAIN_MENU_OPTION);

    int option = option_input(ENTER_OPTION_PROMPT, &menu);
    option_handler(&menu, option, user);
}

void student_info_menu(struct User *user, int student_id) {
    enum Role user_role = user->role;
    student_id = 0;
    char *student_name;
    if (student_id == 0 && user_role == 0) {
        student_id = user->user_id;
        student_name = user->display_name;
    } else {
        char *student_username = loop_input(STUDENT_ID_PROMPT, VALID_STUDENT_ID_MSG);
        bool is_student = is_user_student(student_username);
        if(is_student) {
            printf("The user is a student");
            return;
        } else {
            printf("The user is NOT a student");
            return;
        }
    }
    
    struct Menu menu;
    menu.num_options = 0;
    
    char menu_name[100]; // Declare menu_name as an array of characters with sufficient memory

    if(user_role == 0) {
        sprintf(menu_name, STUDENT_INFO_MENU_TITLE_STUDENT, student_name);
    } else {
        sprintf(menu_name, STUDENT_INFO_MENU_TITLE);
    }

    char *info_option_text;
    if(user_role == 0) {
        info_option_text = VIEW_INFO_OPTION_STUDENT;
    } else {
        info_option_text = VIEW_INFO_OPTION;
    }
    add_option(&menu, info_option_text, view_student_info);
    add_option(&menu, ENROLLED_COURSES_OPTION, view_student_enrolled_courses);
    add_option(&menu, RETURN_MAIN_MENU_OPTION, main_menu);

    box_menu(&menu, (char*)menu_name);

    int option = option_input(ENTER_OPTION_PROMPT, &menu);
    option_handler(&menu, option, user);
}


void user_management_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "Add User", add_user_option);
    add_option(&menu, "Remove User", remove_user_options);
    add_option(&menu, "View All Users", view_all_user_option);
    add_option(&menu, "Return to Main Menu", main_menu);

    box_menu(&menu, "User Management Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, user);
}

void student_management_menu(struct User *user, int student_id) {
    printf("Student Management\n");
}

// ! Leave this be i will handle these kind of functions - Mahmood
// ! Moving to a better place

///@brief User Management Options

void add_user_option(struct User *user) {
    char *username = loop_input(USERNAME_PROMPT, VALID_USERNAME_MSG);
    char *display_name = loop_input(DISPLAY_NAME_PROMPT, VALID_DISPLAY_NAME_MSG);
    char *password = loop_input(PASSWORD_PROMPT, VALID_PASSWORD_MSG);
    enum Role role = role_input(ROLE_PROMPT);
    bool user_added = add_user(username, display_name, password, role);

    if(user == NULL) {
        box_info_back(USER_ADDED_SUCCESS_MSG, "success", WELCOME_MENU_TITLE);
        welcome_menu();
    }

    if(user_added) {
        box_info_back(USER_ADDED_SUCCESS_MSG, "success", USER_MANAGEMENT_MENU_TITLE);
        user_management_menu(user);
    } else {
        box_info_back(USER_EXISTS_ERROR_MSG, "error", USER_MANAGEMENT_MENU_TITLE);
        user_management_menu(user);
    }
}

void view_all_user_option(struct User *user) {
    printf("View All Users\n");
    user_management_menu(user);
}

void remove_user_options(struct User *user) {
    char *username = loop_input(USERNAME_PROMPT, VALID_USERNAME_MSG);
    if(strcmp(user->username, username) == 0) {
        box_info_back(CANNOT_REMOVE_SELF_MSG, "error", USER_MANAGEMENT_MENU_TITLE);
        user_management_menu(user);
    }
    bool userFound = is_user_exist(username);
    if(!userFound) {
        box_info_back(USER_NOT_EXIST_MSG, "error", USER_MANAGEMENT_MENU_TITLE);
        user_management_menu(user);
    }
    bool safety = are_you_sure(REMOVE_USER_PROMPT);
    if (safety) {
        bool user_removed = remove_user(username);
        if(user_removed) {
            box_info_back(USER_REMOVED_SUCCESS_MSG, "success", USER_MANAGEMENT_MENU_TITLE);
        } else {
            box_info_back(USER_NOT_REMOVED_ERROR_MSG, "error", USER_MANAGEMENT_MENU_TITLE);
        }
    } else {
        box_info_back(USER_NOT_REMOVED_MSG, "no", USER_MANAGEMENT_MENU_TITLE);
    }
    user_management_menu(user);
}


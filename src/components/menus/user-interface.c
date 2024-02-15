#include <stdio.h>
#include <common-functions.h>
#include "login.h"
#include "systems/student-system.h"
#include <student management system/student-management.h>
#include "systems/user-system.h"
#include <stdbool.h>

void login_menu();
void main_menu(struct User *user);
void student_info_menu(struct User *user);
void student_management_menu(struct User *user);
void user_management_menu(struct User *user);

// Options
void view_student_info(struct User *user);
void add_user_option(struct User *user);
void remove_user_options(struct User *user);
void view_all_user_option(struct User *user);

void welcome_menu() {
    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "Login", login_menu);
    add_option(&menu, "Exit", exit_message);

    box_menu(&menu, "Welcome Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, NULL);
}


void login_menu() {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");

    struct User *user = login(username, password);

    if(!user) {
        printf("Invalid username or password. Please try again.\n");
        welcome_menu();
    } else {
        printf("Login successful!\n");
        main_menu(user);
    }
}


void main_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;
    int const user_role = user->role;


    if (user_role >= 0 && user_role <= 3) {
    add_option(&menu, "Student Info", student_info_menu);
    }
    if (user_role >= 1 && user_role <= 3) {
        add_option(&menu, "Student Management", student_management_menu);
    }
    if (user_role >= 2 && user_role <= 3) {
        // Add options for Programme Leader and System Admin here
    }
    if (user_role == 3) {
        add_option(&menu, "User Management", user_management_menu);
    }


    add_option(&menu, "Logout", logout);

    box_menu(&menu, "Main Menu");


    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, user);
}

void student_info_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "View Student Info", view_student_info);
    add_option(&menu, "Return to Main Menu", main_menu);

    box_menu(&menu, "Student Info Menu");

    int option = option_input("Enter your option:", &menu);
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

// ! Leave this be i will handle these kind of functions - Mahmood
void add_user_option(struct User *user) {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *display_name = loop_input("Enter display name:", "Please enter a valid display name.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");
    enum Role role = role_input("Enter role (0,1,2,3):");
    bool user_added = add_user(username, display_name, password, role);

    // Handle the user add
    if(user_added) {
        printf("User added successfully!\n");
        user_management_menu(user);
    } else {
        printf("User already exists!\n");
        user_management_menu(user);
    }
}

void view_all_user_option(struct User *user) {
    printf("View All Users\n");
    user_management_menu(user);
}

void remove_user_options(struct User *user) {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    bool user_removed = remove_user(username);
    // Handle the user remove
    if(user_removed) {
        printf("User removed successfully!\n");
    } else {
        printf("User does not exist!\n");
    }
    user_management_menu(user);
}

void view_student_info(struct User *user) {
    struct StudentRecord *student_info = get_student_record(user->user_id);
    printf("%d", student_info->attendance);
}

void student_management_menu(struct User *user) {
    printf("Student Management\n");
}
#include <stdio.h>
#include <common-functions.h>
#include "login.h"
#include "systems/student-system.h"
#include "systems/user-system.h"
#include <stdbool.h>

void login_menu();
void main_menu(struct User *user);
void student_info_menu(struct User *user);
void student_management_menu(struct User *user);
void user_management_menu(struct User *user);
void add_user_option();

// Options
void view_student_info(struct User *user);


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
    } else {
        printf("Login successful!\n");
        main_menu(user);
    }
}


void main_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;
    int const user_role = user->role;

    add_option(&menu, "Student Info", student_info_menu);
    add_option(&menu, "Student Management", student_management_menu);
    add_option(&menu, "User Management", user_management_menu);
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

void view_student_info(struct User *user) {
    printf("Student Info\n");
    // Add the student info here
}

void student_management_menu(struct User *user) {
    printf("Student Management\n");
}

void user_management_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "Add User", add_user_option);
    add_option(&menu, "Return to Main Menu", main_menu);

    box_menu(&menu, "User Management Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, user);
}

void add_user_option() {
    // Get the values from the user with get_input
    bool user_added = add_user("jacke", "Jack", "pass", STUDENT);
    // Handle the user add
    if(user_added) {
        printf("User added successfully!\n");
    } else {
        printf("User already exists!\n");
    }
}

void remove_user_options() {
    // Get the values from the user with get_input
    bool user_removed = remove_user("jack");
    // Handle the user remove
    if(user_removed) {
        printf("User removed successfully!\n");
    } else {
        printf("User does not exist!\n");
    }
}
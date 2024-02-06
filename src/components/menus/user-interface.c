#include <stdio.h>
#include <common-functions.h>
#include "login.h"
#include "student-system.h"

void login_menu();
void main_menu(struct User *user);
void student_info_menu(struct User *user);
void student_management_menu(struct User *user);


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
        printf("User ID: %d\n", user->user_id);
        main_menu(user);
    }
}



void main_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;

    if (user->role == 0) {
        add_option(&menu, "Student Info", student_info_menu);
        add_option(&menu, "Logout", logout);
    } else if (user->role == 1) {
        add_option(&menu, "Student Info", student_info_menu);
        add_option(&menu, "Student Management", student_management_menu);
        add_option(&menu, "Logout", logout);
    }

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

void student_management_menu(struct User *user) {
    printf("Student Management Menu\n");
    // Add the student management menu here
}
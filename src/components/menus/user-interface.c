#include <stdio.h>
#include <string.h>
#include <common-functions.h>
#include "login.h"
#include "student-system.h"

void login_menu();
void main_menu(struct User *user);
void student_info_menu(struct User *user);
void student_management_menu(struct User *user);

// Define the function pointer type
typedef void (*MenuOptionFunction)(struct User *);;

void welcome_menu() {
    struct Menu menu;
    menu.num_options = 0;
    MenuOptionFunction menu_functions[MAX_MENU_OPTIONS];

    add_option(&menu, "Login");
    menu_functions[0] = login_menu;
    add_option(&menu, "Exit");
    menu_functions[1] = exit_message;

    box_menu(&menu, "Welcome Menu");

    int option = option_input("Enter your option:", 2);
    if (option >= 1 && option <= menu.num_options) {
        menu_functions[option - 1](NULL);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}


void login_menu() {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");

    struct User *user = login(username, password);

    // * The UserInfo will be available here on out and should be used for any other menu here

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
    MenuOptionFunction menu_functions[MAX_MENU_OPTIONS];

    if (user->role == 0) {
        add_option(&menu, "Student Info");
        menu_functions[0] = student_info_menu;
        add_option(&menu, "Logout");
        menu_functions[1] = logout;
    } else if (user->role == 1) {
        add_option(&menu, "Student Info");
        menu_functions[0] = student_info_menu;
        add_option(&menu, "Student Management");
        menu_functions[1] = student_management_menu;
        add_option(&menu, "Logout");
        menu_functions[2] = logout;
    }

    box_menu(&menu, "Main Menu");

    int option = option_input("Enter your option:", menu.num_options);

    // Call the function from the array based on the selected option
    if (option >= 1 && option <= menu.num_options) {
        menu_functions[option - 1](user);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}
void student_info_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;

    // Define the array of function pointers
    MenuOptionFunction menu_functions[MAX_MENU_OPTIONS];

    add_option(&menu, "View Student Info");
    menu_functions[0] = view_student_info;
    add_option(&menu, "Return to Main Menu");
    menu_functions[1] = main_menu;
    add_option(&menu, "Logout");
    menu_functions[2] = logout;

    box_menu(&menu, "Student Info Menu");

    int option = option_input("Enter your option:", menu.num_options);
    // Call the function from the array based on the selected option
    if (option >= 1 && option <= menu.num_options) {
        menu_functions[option - 1](user);
    } else {
        printf("Invalid option. Please try again.\n");
    }

}

void student_management_menu(struct User *user) {
    printf("Student Management Menu\n");
    // Add the student management menu here
}
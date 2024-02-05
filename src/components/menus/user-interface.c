#include <stdio.h>
#include <common-functions.h>
#include "login.h"


void login_menu();

void welcome_menu() {
    printf("Welcome to the System!\n");
    printf("1. Login\n");
    printf("2. Exit\n");
    int option = option_input("Enter your option:", 2);
    switch(option) {
        case 1:
            printf("Login Function\n");
            login_menu();
        case 2:
            return;
        default:
            printf("Invalid option. Please try again.\n");
    }
}


void login_menu() {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");

    struct User *user = login(username, password);

    // * The UserInfo will be available here on out and should be used for any other menu here
    printf("%d", user->user_id);
}

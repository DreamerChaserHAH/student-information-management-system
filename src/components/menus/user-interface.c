// * Please add All the student related systems here!

#include <stdio.h>
#include <login.h>
#include <string.h>
#include <stdlib.h>
#include <common-functions.h>

//function(username, password)
void login_menu();

void welcome_menu() {
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


void login_menu(){
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");

    printf("%s, %s", username, password); // Debug
}

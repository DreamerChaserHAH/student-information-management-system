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
    printf("Enter your option:");

    int option = get_int();

    if (option == 1) {
        printf("Login Function\n");
        login_menu();
    } else if (option == 2) {
        return;
    } else {
        printf("Invalid option. Please try again.\n");  // * Handle invalid input
    }
}


void login_menu(){
    char *username = input("string", "Enter username:");

    // ? Looping till user input username
    while (strlen(username) == 0) {
        username = input("string", "Enter username:");

        if (strlen(username) == 0) {  // Check for empty input
            printf("Please enter a valid username.\n"); // This kicks in if the username still inputs an empty username
        }
    }

    char *password = input("string", "Enter password:");

    // ? Looping till user input password
    while (strlen(password) == 0) {
        password = input("string", "Enter password:");

        if (strlen(password) == 0) {  // Check for empty input
            printf("Please enter a valid password.\n"); // This kicks in if the password still inputs an empty password
        }
    }

    printf("%s, %s", username, password); // Debug
}

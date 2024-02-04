// * Please add All the student related systems here!

#include <stdio.h>
#include <login.h>
#include <string.h>
#include <stdlib.h>

//function(username, password)
void login_menu();

void welcome_menu() {
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("Enter your option:");

    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    int option = atoi(buffer); // * Convert string to integer

    if (option == 1) {
        printf("LoginFunction\n");
        login_menu();
    } else if (option == 2) {
        return;
    } else {
        printf("Invalid option. Please try again.\n");  // * Handle invalid input
    }
}


void login_menu(){
    char username[50];
    char password[50];
    printf("Enter username:");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    // ? Looping till user input username
    while (strlen(username) == 0) {
        printf("Enter username:");

        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';  // Remove newline

        if (strlen(username) == 0) {  // Check for empty input
            printf("Please enter a valid username.\n"); // This kicks in if the username still inputs an empty username
        }
    }

    printf("Enter password:");
    fgets(password, sizeof(password), stdin); // ! fgets
    password[strcspn(password, "\n")] = '\0';  // Remove checking newline, for when pressing enter. This depends on fgets, I think

    // ? Looping till user input password
    while (strlen(password) == 0) {
        printf("Enter password: ");

        fgets(password, sizeof(password), stdin); // ! fgets
        password[strcspn(password, "\n")] = '\0';  // Remove newline

        if (strlen(password) == 0) {  // Check for empty input
            printf("Please enter a valid password.\n"); // This kicks in if the password still inputs an empty password
        }
    }

    printf("%s, %s", username, password); // Debug
}

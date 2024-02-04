// ? Author : Mahmood
/// <summary>
/// The main login function. Returns UserInfo as per the login succession. This whole thing assumes that we are allowed to use fgets!
/// </summary>


#include <stdio.h>
#include <string.h>
#include <datamanager.h>

// ? Idk if this will work with txt files


// ! This really assumes we can structure the txt files
// * This should be how all the user data is shown when asked for:
// ? {id, username, displayname, password, role}

struct User users[100] = {  // Array to store user data
        {1, "user", "User", "pass", 0}, // Since its login the whole userinfo will be sent back
        {2, "mahmood", "Mahmood", "pass", 0},
};

// Number of users currently stored
int numUsers = 2; // * This should be a builtin function in the database, for convince so we can call it like total_users() # OUTPUT: 1

struct User *login() {
    char username[50], password[50];
    printf("Enter username:");
    fgets(username, sizeof(username), stdin); // ! Had to painfully learn how bad scanf is so will use fgets for now unless teacher says we cant
    username[strcspn(username, "\n")] = '\0';  // Remove checking newline, for when pressing enter. This depends on fgets, I think, haven't touched scanf;

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

    // * Was going to do so that when the user is inputted it checks for the users existence before continuing. But this is easier.
    for (int i = 0; i < numUsers; i++) {
        // ! fgets, probably
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return &users[i];  // Return the pointer to the matching UserInfo
        }
    }
    return NULL;  // Indicate unsuccessful login
}

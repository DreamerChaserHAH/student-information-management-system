// ? Author : Mahmood
/// <summary>
/// The main login function. Returns true or false as per the login succession. This whole thing assumes that we are allowed to use fgets!
/// </summary>

#include <database.h>
#include <stdio.h>
#include <string.h>

// ? Idk if thic will work with txt files
struct UserInfo {
    char username[50];
    char password[50];
    int role;
};

// ! This really assumes we can do struct for txt files
// * Or we can use a function to struct the UserInfo here

struct UserInfo users[100] = {  // Array to store user data
        {"user", "pass", 0}, // * Since its login the whole userinfo will be sent back
};
int numUsers = 1;  // Number of users currently stored

struct UserInfo *login() {
    char username[50], password[50];
    printf("Enter username:");
    fgets(username, sizeof(username), stdin); // ! Had to painfully learn how bad scanf is so will use fgets for now unless teacher says we cant
    username[strcspn(username, "\n")] = '\0';  // Remove checking newline, for when pressing enter. This depends on fgets, I think

    // ? Looping till username input username
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

    // ? Looping till password input password
    while (strlen(password) == 0) {
        printf("Enter password:");

        fgets(password, sizeof(password), stdin); // ! fgets
        password[strcspn(password, "\n")] = '\0';  // Remove newline

        if (strlen(password) == 0) {  // Check for empty input
            printf("Please enter a valid password.\n"); // This kicks in if the password still inputs an empty password
        }
    }
    for (int i = 0; i < numUsers; i++) {
        // ! This will need to be changed too, cause fgets
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return &users[i];  // Return the pointer to the matching UserInfo
        }
    }
    return NULL;  // Indicate unsuccessful login
}

// ? Old function that i worked on for about 2 hours but only gives true or false value

/*
bool login() {
    // ! SINCE IDK HOW TO READ WRITE DATA TO THE DATABASE I WILL CREATE THESE AS DEFAULT AND WORK WITH THAT
    char username[] = "user";
    char password[] = "pass";
    int role = 0;
    // ? ^ These will need to be changed and some other things in the code itself that i will highlight.
    char user[50];
    char pass[50];

    printf("Enter username:"); // Get input for user

    fgets(user, sizeof(user), stdin); // ! Had to painfully learn how bad scanf is so will use fgets for now unless teacher says we cant
    user[strcspn(user, "\n")] = '\0';  // Remove checking newline, for when pressing enter. This depends on fgets, I think

    // ? Looping till user input username
    while (strlen(user) == 0) {
        printf("Enter username:");

        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';  // Remove newline

        if (strlen(user) == 0) {  // Check for empty input
            printf("Please enter a valid username.\n"); // This kicks in if the user still inputs an empty username
        }
    }

    // * This if statement will need to be changed accordingly
    if (strcmp(username, user) != 0) {  // Compare the usernames using strcmp. Also depends on fgets, haven't tried with scanf
        return false;
    } else {
        printf("Enter password:");
        fgets(pass, sizeof(pass), stdin); // ! Same as user
        pass[strcspn(pass, "\n")] = '\0'; // scanf probably doesn't even know what this is

        // ? Same looping till user inputs password
        while (strlen(pass) == 0) {  // Loop until a non-empty password is entered
            printf("Enter password:");

            fgets(pass, sizeof(pass), stdin);
            pass[strcspn(pass, "\n")] = '\0';  // Remove newline

            if (strlen(pass) == 0) {  // Check for empty input
                printf("Please enter a password.\n"); // This kicks in if the user still inputs an empty username
            }
        }

        // * This if statement to check password needs to be changed as well!
        if(strcmp(password, pass) != 0) {
            return false;
        } else {
            return true;
        }
    }
}
 */
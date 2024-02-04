// ? Author : Mahmood
/// <summary>
/// The main login function. Returns UserInfo as per the login succession. This whole thing assumes that we are allowed to use fgets!
/// Over commented because somethings need to be clarified
/// </summary>


#include <stdio.h>
#include <string.h>
#include <datamanager.h>

// ! Needs to be changed with database code
struct User users[100] = {  // Array to store user data
        {1, "user", "User", "pass", 0},
        {2, "mahmood", "Mahmood", "pass", 1},
};

// ! Needs to be changed with database code
int numUsers = 2;

struct User *login(const char *username, const char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return &users[i];  // Return the pointer to the matching UserInfo
        }
    }
    return NULL;
}

// ? Author : Mahmood
/// <summary>
/// The main login function. Returns UserInfo as per the login succession. This whole thing assumes that we are allowed to use fgets!
/// Over commented because somethings need to be clarified
/// </summary>


#include <stdio.h>
#include <string.h>
#include <datamanager.h>
#include <user-interface.h>
#include "common-functions.h"

// ! Needs to be changed with database code
struct User users[100] = {
        /// @brief Array to store user data
        {1, "user", "User", "pass", 0},
        {2, "teacher", "Teacher", "pass", 1},
};

// ! Needs to be changed with database code
int numOFUsers = 2;

struct User *login(const char *username, const char *password) {
    for (int i = 0; i < numOFUsers; i++) {
        if (strcmp(username, users[i].username) == 0) {
            if(strcmp(password, users[i].password) == 0) {
                return &users[i];
            } else {
                // * Ask for password one more time.
                password = get_input("Incorrect password try again:");
                if(strcmp(password, users[i].password) == 0) {
                    return &users[i];
                }
            }
        }
    }
    return NULL;
}

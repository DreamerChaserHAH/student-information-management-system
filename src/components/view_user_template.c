#include <stdio.h>
#include <string.h>
#include <datamanager.h>

// ! Still a predefined struct waiting on database
struct User usersF[100] = {
        {1, "user", "User", "pass", 0},
        {2, "mahmood", "Mahmood", "pass", 0},
};

void user_info(const char *userName) {
    char UserInfo[50];
    for (int i = 0; i < 2; i++) {
        if (strcmp(userName, usersF[i].username) == 0) {
            // ? If someone knows how to add the info into a new array thn use or return that array pls replace this with that
            printf("Display Name:%s\n", usersF[i].displayname);
            printf("Username:%s\n", usersF[i].username);
            printf("Id:%d\n", usersF[i].user_id);

            break;
        }
    }
}
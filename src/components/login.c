// ? Author : Mahmood
/// <summary>
/// The main login function. Returns UserInfo as per the login succession. This whole thing assumes that we are allowed to use fgets!
/// Over commented because somethings need to be clarified
/// </summary>


#include <stdio.h>
#include <string.h>
#include <data management system/datamanager.h>
#include <user interface/ui-main.h>


struct User *login(char* username, char* password) {
    if(!is_user_exist(username)) {
        return NULL;
    } else {
        struct User *user = read_user_record(username);
        if (strcmp(user->password, password) == 0) {
            return user;
        } else {
            return NULL;
        }
    }
}

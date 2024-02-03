#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>

struct UserInfo {
    char username[50];
    char password[50];
    int role;
};

struct UserInfo *login();
// bool login()
#endif

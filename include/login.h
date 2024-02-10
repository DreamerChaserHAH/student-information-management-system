#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>

/// @brief Logs the user into the system and returns the User object
/// @param username The username provided by the user
/// @param password The password provided by the user
struct User *login(const char *username, const char *password);

#endif

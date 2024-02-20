//
// Created by imLifeline on 10/02/2024.
//

#ifndef SIMS_USER_SYSTEM_H
#define SIMS_USER_SYSTEM_H
#include <data management system/datamanager.h>
#include <stdbool.h>

/// @brief Add a new user to the system
/// @param username The username of the user
/// @param display_name The display name of the user
/// @param password The password of the user
/// @param role The role of the user
/// @return true if the user is added successfully, false otherwise
bool add_user(char* username, char* display_name, char* password, enum Role role);

/// @brief Remove a user from the system
/// @param username The username of the user
/// @return true if the user is removed successfully, false otherwise
bool remove_user(char* username);

#endif //SIMS_USER_SYSTEM_H

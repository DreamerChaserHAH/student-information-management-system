//
// Created by Administrator on 2/5/2024.
//

#ifndef SIMS_COMMON_FUNCTIONS_H
#define SIMS_COMMON_FUNCTIONS_H
#include <data management system/datamanager.h>

/// @brief The maximum number of options in the menu
#define MAX_MENU_OPTIONS 10
#define MAX_ROLE_LENGTH 10
#define MAX_OPTION_LENGTH 50
#define MAX_OPTIONS 10
/// @brief Function pointer for menu options
typedef void (*MenuOptionFunction)();

/// @brief Menu structure
struct Menu {
    char options[MAX_OPTIONS][MAX_OPTION_LENGTH];
    char roles[MAX_OPTIONS][MAX_ROLE_LENGTH];
    MenuOptionFunction functions[MAX_OPTIONS];
    MenuOptionFunction shown_functions[MAX_OPTIONS];
    int num_options;
    int num_shown_options;
};


/// @brief To add the option to the menu
/// @param menu The menu to add the option to
/// @param option The option to add
/// @param function The function to be called when the option is selected
void add_option(struct Menu *menu, const char *option, MenuOptionFunction function);

/// @brief To display the menu
/// @param menu The menu to be displayed
/// @param menu_name The name of the menu
void box_menu(struct Menu *menu, char *menu_name);

/// @breif Option handler
/// @param menu The menu to be handled
/// @param option The option to be handled
/// @param user The user to be handled
void option_handler(struct Menu *menu, int option, struct User *user);

/// @brief Create a box
/// @param title The title of the box
void create_box(char *title);

/// @brief Add info to the box
/// @param info The info to be added
void add_info(char *info);

/// @brief Close the box
void close_box();

void box_info(char *info);

/// @brief To display the exit message
void exit_message();

#endif //SIMS_COMMON_FUNCTIONS_H

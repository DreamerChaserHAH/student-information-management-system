//
// Created by Administrator on 2/5/2024.
//

#ifndef SIMS_COMMON_FUNCTIONS_H
#define SIMS_COMMON_FUNCTIONS_H

/// @brief Get string input from the user.
/// @param text The text to view when asking for input.
char *get_input(char *text);

/// @brief Get int input from the user.
/// @param text The text to view when asking for a number.
int number_input(char *text);

/// @brief Loop the input prompt
/// @param text The text to view when asking for a input
/// @param invalid_text The text to view when the user still haven't inputted
char *loop_input(char *text, char *invalid_text);

/// @brief Loop the number input prompt
/// @param text The text to view when asking for a number
/// @param invalid_text The text to view when the user still haven't inputted the number
int loop_number_input(char *text, char *invalid_text);

/// @brief To get the input for options
/// @param text The text to view when asking for a option
/// @param options The total number of options
int option_input(char *text, int options);

#define MAX_MENU_OPTIONS 10
#define MAX_OPTION_LENGTH 20

/// @brief Menu structure
struct Menu {
    char options[MAX_MENU_OPTIONS][MAX_OPTION_LENGTH];
    int num_options;
};

/// @brief To add the option to the menu
/// @param menu The menu to be added
/// @param option The option to be added
void add_option(struct Menu *menu, const char *option);

/// @brief To display the menu
/// @param menu The menu to be displayed
void box_menu(struct Menu *menu, char *menu_name);



/// @brief Logout the user
void logout();

/// @brief To display the exit message
void exit_message();

#endif //SIMS_COMMON_FUNCTIONS_H

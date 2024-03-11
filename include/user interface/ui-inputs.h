#ifndef UI_INPUTS_H
#define UI_INPUTS_H

#include <data management system/datamanager.h>

/// @brief Get string input from the user.
/// @param text The text to view when asking for input.
char *get_input(char *text);

/// @brief Get int input from the user.
/// @param text The text to view when asking for a number.
int number_input(char *text, char *invalid_text);

enum Role role_input(char *text);


/// @brief Loop the input prompt
/// @param text The text to view when asking for a input
/// @param invalid_text The text to view when the user still haven't inputted
char *loop_input(char *text, char *invalid_text);

/// @brief Loop the number input prompt
/// @param text The text to view when asking for a number
/// @param invalid_text The text to view when the user still haven't inputted the number
int loop_number_input(char *text, char *invalid_text);

/// @brief Loop the option input prompt
/// @param text The text to view when asking for a option
/// @param menu The menu in which the option is selected
int option_input(char *text, struct Menu *menu);


#endif // UI_INPUTS_H
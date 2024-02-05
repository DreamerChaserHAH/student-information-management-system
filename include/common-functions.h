//
// Created by Administrator on 2/5/2024.
//

#ifndef SIMS_COMMON_FUNCTIONS_H
#define SIMS_COMMON_FUNCTIONS_H

/// @brief Get string input from the user.
/// @param text The text to view when asking for input.
char *input(char *text);

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

#endif //SIMS_COMMON_FUNCTIONS_H

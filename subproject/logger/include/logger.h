/// Author : Htet Aung Hlaing
/// <summary>
/// to give more fine tuned control over whether if logging should be enabled or not
/// albeit not as flexible, it is usable
/// </summary>

#ifndef CUSTOM_LOGGER
#define CUSTOM_LOGGER

#include <stdio.h>

/// @brief message type log that displays (in whatever case)
/// @param message the message that will be logged and displayed
void log_message(char* message);

/// @brief message type log that displays only in debug builds
/// @param message the message that will be logged and displayed
void debug_log_message(char* message);

/// @brief error type log that displays with Prefix "Fatal Error"
/// @param message the message that will be logged and displayed
void log_error_message(char* message);

/// @brief error type log that displays with prefix "Fatal Error" only in debug builds
/// @param message the message that will be logged and displayed
void debug_log_error_message(char* message);

#endif //CUSTOM_LOGGER
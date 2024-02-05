#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number_input(char *text) {
    printf("%s", text);

    // ? Handle the input of the user
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // * Handle new line for fgets

    int value = atoi(buffer); // * Convert string to integer

    return value;
}

int loop_number_input(char *text, char *invalid_text) {
    printf("%s", text);

    // ? Handle the input of the user
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // * Handle new line for fgets

    int value = atoi(buffer); // * Convert string to integer

    // ? Looping till user inputs
    while (!value) {
        value = number_input(text);

        if (!value) {
            printf("%s\n", invalid_text);
        }
    }

    return value;
}

char *input(char *text) {
    // User input buffer size
    const int BUFFER_SIZE = 100;

    // Char array to store input
    char buffer[BUFFER_SIZE];

    // Prompt the user
    printf("%s", text);

    // Read the input
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        return NULL; // Handle error or end of file
    }

    // Remove potential trailing newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // Allocate memory for the return string
    char *result = malloc(strlen(buffer) + 1); // Allocate space for string and null terminator

    // Copy the buffer to the return string
    strcpy(result, buffer);

    // Return the string
    return result;
}

char *loop_input(char *text, char *invalid_text) {
    // Prompt the user
    printf("%s", text);

    // User input buffer size
    const int BUFFER_SIZE = 100;

    // Char array to store input
    char buffer[BUFFER_SIZE];

    // Read the input
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        return NULL; // Handle error or end of file
    }

    // Remove potential trailing newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // Allocate memory for the return string
    char *result = malloc(strlen(buffer) + 1); // Allocate space for string and null terminator

    // Copy the buffer to the return string
    strcpy(result, buffer);

    // ? Looping till user inputs
    while (strlen(result) == 0) {
        result = input(text);

        if (strlen(result) == 0) {  // Check for empty input
            printf("%s\n", invalid_text); // This kicks in if the username still inputs an empty username
        }
    }

    return result;
}

int option_input(char *text, char *invalid_text, const int *options) {
    int value = number_input(text);

    // ? Looping till user inputs
    while (!value || value > options) {
        printf("%s Available options: %d\n", invalid_text, options);
        value = number_input(text);
    }

    return value;
}
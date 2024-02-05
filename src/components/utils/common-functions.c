#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_int() {
    // ? Handle the input of the user
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // * Handle new line for fgets

    int value = atoi(buffer); // * Convert string to integer
    return value;
}

char *input(char *type, char *text) {
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
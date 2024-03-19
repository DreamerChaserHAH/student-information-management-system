#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Interface Files
#include <user interface/ui-utils.h>
#include <user interface/ui-inputs.h>
// Include Files End
#include <data management system/datamanager.h>

int number_input(char *text, char *invalid_text) {
    char buffer[10];
    char *string;
    long value;

    do {
        printf("%s", text);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        value = strtol(buffer, &string, 10);

        if (string == buffer || *string != '\0') {
            printf("%s\n", invalid_text);
            value = 0;
        }
    } while (!value);

    return value;
}

int loop_number_input(char *text, char *invalid_text) {
    int value = 0;

    do {
        value = number_input(text, invalid_text);
        if (!value) {
            printf("%s\n", invalid_text);
        }
    } while (!value);

    return value;
}

enum Role role_input(char *text) {
    char buffer[10];
    char *string;
    long value;
    enum Role role;

    do {
        printf("%s", text);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        value = strtol(buffer, &string, 10);

        if (string == buffer || *string != '\0' || value < STUDENT || value > SYSTEM_ADMIN) {
            printf("Please enter a valid role (0-3).\n");
            value = -1;
        } else {
            role = (enum Role)value;
        }
    } while (value == -1);

    return role;
}

char *get_input(char *text) {
    const int BUFFER_SIZE = 100;
    char buffer[100];

    printf("%s", text);

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    char *result = strdup(buffer);

    return result;
}

char *loop_input(char *text, char *invalid_text) {
    char *result;
    do {
        result = get_input(text);
        if (strlen(result) == 0) {
            printf("%s\n", invalid_text);
        }
    } while (strlen(result) == 0);

    return result;
}

int option_input(char *text, struct Menu *menu) {
    int value;
    do {
        value = number_input(text, "Please enter a valid option.");
        if (value < 1 || value > menu->num_options) {
            printf("Total available options: %d\n", menu->num_options);
            value = 0;
        }
    } while (!value);

    return value;
}
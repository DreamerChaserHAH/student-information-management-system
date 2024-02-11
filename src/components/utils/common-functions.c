#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common-functions.h"
#include "user-interface.h"
#define DEFAULT_WIDTH 30

int number_input(char *text) {
    char buffer[10];
    char *string;
    long value;

    do {
        printf("%s", text);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        value = strtol(buffer, &string, 10);

        if (string == buffer || *string != '\0') {
            printf("Please enter a numeric value.\n");
            value = 0;
        }
    } while (!value);

    return value;
}

int loop_number_input(char *text, char *invalid_text) {
    int value = 0;

    do {
        value = number_input(text);
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
    char buffer[BUFFER_SIZE];

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
        value = number_input(text);
        if (value < 1 || value > menu->num_options) {
            printf("Please choose a valid option! Available options: %d\n", menu->num_options);
            value = 0;
        }
    } while (!value);

    return value;
}

void logout() {
    welcome_menu();
}

void exit_message() {
    printf("Exiting the system. Goodbye!\n");
    exit(0);
};

void add_option(struct Menu *menu, const char *option, MenuOptionFunction function) {
    strncpy(menu->options[menu->num_options], option, MAX_OPTION_LENGTH);
    menu->functions[menu->num_options] = function;
    menu->num_options++;
}

int get_max_length(struct Menu *menu, char *menu_name) {
    int max_length = strlen(menu_name);
    for (int i = 0; i < menu->num_options; i++) {
        int length = strlen(menu->options[i]);
        if (length > max_length) {
            max_length = length;
        }
    }
    return max_length;
}

void print_line(int length) {
    printf("+");
    for (int i = 0; i < length; i++) {
        printf("-"); // The character used to draw the line
    }
    printf("+\n");
}

void box_menu(struct Menu *menu, char *menu_name) {
    int max_length = DEFAULT_WIDTH;
    print_line(max_length); // Print top divider for menu name

    // Calculate the number of spaces needed to center the menu name
    int padding = (max_length - strlen(menu_name)) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", menu_name); // Print menu name

    print_line(max_length); // Print top border for options
    for (int i = 0; i < menu->num_options; i++) {
        printf("| %d. %s", i + 1, menu->options[i]);
        int spaces = max_length - strlen(menu->options[i]) - 4; // Subtract 4 for the '|', '.', and ' ' characters
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf(" |\n");
    }
    print_line(max_length); // Print bottom border for options
}

void create_box(char *title) {
    int max_length = DEFAULT_WIDTH;
    print_line(max_length); // Print top divider for title

    // Calculate the number of spaces needed to center the title
    int padding = (max_length - strlen(title)) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", title); // Print title

    print_line(max_length - 3); // Print top border for info
}
void add_info(char *info) {
    printf("| %s", info); // Print info
    int spaces = DEFAULT_WIDTH - strlen(info) - 3; // Subtract 3 for the '|', and ' ' characters
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("|\n");
}
void close_box() {
    int max_length = DEFAULT_WIDTH;
    print_line(max_length - 3); // Print bottom border for info
}
void option_handler(struct Menu *menu, int option, struct User *user) {
    if (option >= 1 && option <= menu->num_options) {
        menu->functions[option - 1](user);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}
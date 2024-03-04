#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <unistd.h>
#include "menus/menu-utils.h"
#include "user-interface.h"
#define DEFAULT_WIDTH 30

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
    char buffer[100];

    printf("%s", text);

    if (fgets(buffer, 100, stdin) == NULL) {
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

void print_line(int length, char *type) {
    char *line;
    if(strcmp(type, "menu") == 0) {
        line = "-";
    } else if(strcmp(type, "info") == 0) {
        line = "=";
    } else if (strcmp(type, "error") == 0) {
        line = "#";
    } else if (strcmp(type, "success") == 0){
        line = "~";
    } else if (strcmp(type, "yes") == 0){
        line = "~";
    } else if (strcmp(type, "no") == 0){
        line = "*";
    } else {
        line = "-";
    }
    printf("+");
    for (int i = 0; i < length; i++) {
        printf("%s", line); // The character used to draw the line
    }
    printf("+\n");
}

void box_menu(struct Menu *menu, char *menu_name) {
    int max_length = DEFAULT_WIDTH;
    print_line(max_length, "menu"); // Print top divider for menu name

    // Calculate the number of spaces needed to center the menu name
    int padding = (max_length - strlen(menu_name)) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", menu_name); // Print menu name

    print_line(max_length, "menu"); // Print top border for options
    for (int i = 0; i < menu->num_options; i++) {
        printf("| %d. %s", i + 1, menu->options[i]);
        int spaces = max_length - strlen(menu->options[i]) - 4; // Subtract 4 for the '|', '.', and ' ' characters
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    print_line(max_length, "menu"); // Print bottom border for options
}

void box_info(char *info, char *type) {
    int max_length = strlen(info) + 4;
    print_line(max_length, type); 
    printf("| %s", info);
    int spaces = max_length - strlen(info) - 1;
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("|\n");
    print_line(max_length, type);
}

void box_info_back(char *info, char *type, char *backto) {
    int max_length = strlen(info) + 4;
    print_line(max_length, type); 
    printf("| %s", info);
    int spaces = max_length - strlen(info) - 1;
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("|\n");
    print_line(max_length, type);
    printf("Going back to the %s", backto);
    int dot = 0;
    while(dot < 4) {
        printf(".");
        fflush(stdout);
        //usleep(500000); // Sleep for 0.5 seconds
        dot++;
    }
    printf("\n");
}


void option_handler(struct Menu *menu, int option, struct User *user) {
    if (option >= 1 && option <= menu->num_options) {
        menu->functions[option - 1](user);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}

bool are_you_sure(char *text) {
    char *input;
    do {
        input = loop_input(text, "Please enter 'yes' or 'no'.");
        if (strcmp(input, "yes") == 0) {
            return true;
        } else if (strcmp(input, "no") == 0) {
            return false;
        } else {
            printf("Please enter 'yes' or 'no'.\n");
        }
    } while (true);
}

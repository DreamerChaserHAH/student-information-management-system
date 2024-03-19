#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Interface Files
#include <user interface/ui-main.h>
#include <user interface/ui-utils.h>
#include <user interface/ui-inputs.h>
// Include Files End
#define DEFAULT_WIDTH 30


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
        printf("|\n");
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

void box_info(char *info) {
    int max_length = strlen(info) + 4;
    print_line(max_length); 
    printf("| %s", info);
    int spaces = max_length - strlen(info) - 1;
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("|\n");
    print_line(max_length);
}

void option_handler(struct Menu *menu, int option, struct User *user) {
    if (option >= 1 && option <= menu->num_options) {
        menu->functions[option - 1](user);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}
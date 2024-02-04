// ? Author : Mahmood
/// <summary>
/// The Menu interface function. This will hold the menus viewed by the different users.
/// </summary>

#include <stdio.h>
#include <student-system.h>
#include <color-printf.h>

void user_menu(const int role) {

    // ? Basic stuff
    printf_color("[y]User Menu Test[/y]\n");

    switch (role) {
        case 0:
            // * This should replace the menu
            printf_color("[y]Student:[/y] [b]%d[/b]\n", role);

            view_student(); // Debug
            break;
        case 1:
            // * This should replace the menu
            printf_color("[y]Teacher[/y]");
            break;
        // And so on
        default:
            break;
    }

}

#include <stdio.h>



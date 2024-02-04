#include <common.h>
#include <database.h>
#include <login.h>
#include <user-menu.h>
#include <color-printf.h>
#include <user-interface.h>

 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_database_environment();
    welcome_menu();

    char username[50] = "user";
    char password[50] = "pass";

    struct User *user = login(username, password);

    // * If the user is not found or wrong password
    if(!user) {
        printf_color("[r]Invalid username or password.[/r]\n");
        return 0;
    }

    // * If the user is found and logged in successfully
    printf_color("[g]Welcome back, %s[/g]\n", user->displayname);

    int userRole = user->role;
    // * Example Menu
    user_menu(userRole);

    return 0;
}

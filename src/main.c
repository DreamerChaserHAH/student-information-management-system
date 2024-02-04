#include <common.h>
#include <database.h>
#include <login.h>
#include <user-menu.h>
#include <view-user-template.h>
#include <color-printf.h>

 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_database_environment();

    struct User *user = login();
    // * If the user is not found or wrong password
    if(!user) {
        printf_color("[r]Invalid username or password.[/r]\n");
        return 0;
    }
    // * If the user is found and logged in successfully
    printf_color("[g]Welcome back, %s[/g]\n", user->displayname);

    // * Rest of the system goes here
    // They will have access to User and role and any other details needed.
    // This is where we add the system where the display menu works according to roles.

     int userRole = user->role;
     // * This is to be an example
     user_menu(userRole);

    return 0;
}

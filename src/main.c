#include <common.h>
#include <database.h>
#include <login.h>


 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_database_environment();

    struct User *user = login();
    // * If the user is not found or wrong password
    if(!user) {
        printf("Invalid username or password.\n");
        return 0;
    }
    // * If the user is found and logged in successfully
    printf("Welcome back, %s!\n", user->displayname);

    // * Rest of the system goes here
    // They will have access to User and role and any other details needed.
    // This is where we add the system where the display menu works according to roles.

    return 0;
}

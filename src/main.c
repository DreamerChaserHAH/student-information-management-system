#include <common.h>
#include <database.h>
#include <login.h>
#include <user-menu.h>
#include <user-interface.h>
#include <test-functions.h>

 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_database_environment();
    // create_user();
    welcome_menu();

    return 0;
}

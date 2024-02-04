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

    return 0;
}

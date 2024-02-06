#include <common.h>
#include <database.h>
#include <user-interface.h>

 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_database_environment();
    welcome_menu();

    return 0;
}

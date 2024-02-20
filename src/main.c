#include <common.h>
#include <login.h>
#include <data management system/datamanager.h>
#include <user-interface.h>

 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_data_environment();
    welcome_menu();

    return 0;
}

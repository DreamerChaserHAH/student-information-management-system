#include <common.h>
#include <database.h>
#include <login.h>
#include <create_user.h>

 /// @brief The entry point to the application that contains surface level logic
 int main() {
    setup_database_environment();
    create_user(); // Placeholder cause I wanted to create test user
    struct UserInfo *user = login();

    if (user) {
        printf("Welcome back, %s! Role: %d\n", user->username, user->role);
    } else {
        printf("Invalid username or password.\n");
    }

     return 0;
}

#include <stdbool.h>
#include <data management system/datamanager.h>
#include <assert.h>
#include <login.h>


bool add_user(char *username, char *display_name, char *password, enum Role role) {

    assert(strcmp(username, "teacher") == 0);
    assert(strcmp(display_name, "Teacher") == 0);
    assert(strcmp(password, "pass") == 0);
    assert(role == STUDENT);

    if(is_user_exist(username)){
        return false;
    }
    return create_user_record(username, display_name, password, role);
}

int main() {
    setup_data_environment();
    char *username = "teacher";
    char *password = "pass";
    struct User *user = login(username, password);
    assert(add_user("teacher", "Teacher", "pass", STUDENT) == 1); // add user successfully
    return 0;
}
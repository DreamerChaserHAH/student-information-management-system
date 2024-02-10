/// Author: Mahmood
#include <data management system/datamanager.h>
#include <stdbool.h>

bool add_user(char *username, char *display_name, char *password, enum Role role) {
    if(is_user_exist(username)){
        return false;
    }
    return create_user_record(username, display_name, password, role);
}

bool remove_user(char *username) {
    if(!is_user_exist(username)){
        return false;
    }
    delete_user_record(username);
    return true;
}

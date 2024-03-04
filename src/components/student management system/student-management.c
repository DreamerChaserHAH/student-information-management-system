#include <data management system/datamanager.h>
#include "menus/menu-utils.h"


struct StudentRecord* get_student_record(int user_id) {
    if(!is_student_record_exist(user_id)){
        return NULL;
    }
    return read_student_record(user_id);
}

bool is_user_student(char *username) {
    bool user_exist_std = is_user_exist(username);
    if(!user_exist_std) {
        return false;
    }
    struct User *found_user_record_std = read_user_record(username);
    int found_user_record_std_role = found_user_record_std->role;
    if(found_user_record_std_role != 0) {
        return false;
    }
    return true;
}
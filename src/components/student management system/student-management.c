#include <data management system/datamanager.h>

struct StudentRecord* get_student_record(int user_id) {
    if(!is_student_record_exist(user_id)){
        return NULL;
    }
    return read_student_record(user_id);
}
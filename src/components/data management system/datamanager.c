#include <data management system/datamanager.h>

static enum Role integer_to_user_role(int role_number);

/// @brief get the file path of the user file
/// @return the string
static char* get_user_file_path(){
    #ifdef INTERNAL_TESTING
        return "TESTING_USER.txt";
    #else
        return "USER.txt";
    #endif
}

/// @brief get the file path of the student record file
/// @return the string
static char* get_student_record_file_path(){
    #ifdef INTERNAL_TESTING
        return "TESTING_STUDENT_RECORD.txt";
    #else
        return "STUDENT_RECORD.txt";
    #endif
}

static char* get_course_file_path(){
    #ifdef INTERNAL_TESTING
        return "TESTING_COURSE.txt";
    #else
        return "COURSE.txt";
    #endif
}

/// @brief get the file path of the programme file
/// @return the string
static char* get_programme_file_path(){
    #ifdef INTERNAL_TESTING
        return "TESTING_PRGRAMME.txt";
    #else
        return "PROGRAMME.txt";
    #endif
}

void array_to_user(char** user_information_array, struct User* user_information){
    user_information->user_id = atoi(user_information_array[0]);
    user_information->username = user_information_array[1];
    user_information->display_name = user_information_array[2];
    user_information->password = user_information_array[3];
    user_information->role = integer_to_user_role(atoi(user_information_array[4]));
}

/// @brief turn Role enum to integer
/// @return role as string
static char* user_role_to_char(enum Role role){
    switch(role){
        case STUDENT: return "0";
        case LECTURER: return "1";
        case PROGRAMME_LEADER: return "2";
        case SYSTEM_ADMIN : return "3";
    }
}

/// @brief turn Role from integer to enum
static enum Role integer_to_user_role(int role_number){
    switch(role_number){
        case 0: return STUDENT;
        case 1: return LECTURER;
        case 2: return PROGRAMME_LEADER;
        case 3: return SYSTEM_ADMIN;
    }
}

void setup_data_environment(){
    if(!is_file_here(get_user_file_path())) { create_file(get_user_file_path()); }
    if(!is_file_here(get_student_record_file_path())) { create_file(get_student_record_file_path()); }
    if(!is_file_here(get_course_file_path())){ create_file(get_course_file_path()); }
    if(!is_file_here(get_programme_file_path())) { create_file(get_programme_file_path()); }
}

void delete_data_environment(){
    if(is_file_here(get_user_file_path())) { delete_file(get_user_file_path()); }
    if(is_file_here(get_student_record_file_path())) { delete_file(get_student_record_file_path()); }
    if(is_file_here(get_course_file_path())){ delete_file(get_course_file_path()); }
    if(is_file_here(get_programme_file_path())) { delete_file(get_programme_file_path()); }
}

bool create_user_record(char* username, char* display_name, char* password, enum Role role){
    /// !!! retrieve whether if the user with the same username exist or not (DONE)
    /// !!! retrieve the latest id of the last user (so the users can be unique of each other) (DONE)
    /// !!! create an array that contains all the data that we want to add (DONE)
    /// !!! return whether if the record has been created successfully (DONE)

    if(!is_user_exist(username)){

        char** last_user_information = calloc(5, sizeof(char*));
        int last_line_number = get_number_of_records(get_user_file_path());
        get_all_available_columns(read_line(get_user_file_path(), last_line_number), last_user_information);
        char* new_user_id = calloc(3, sizeof(char));
        sprintf(new_user_id, "%d", last_user_information[0] != NULL? atoi(last_user_information[0]) + 1 : 1);


        char** content_array = calloc(5, sizeof(char*));
        content_array[0] = new_user_id;
        content_array[1] = username;
        content_array[2] = display_name;
        content_array[3] = password;
        content_array[4] = user_role_to_char(role);

        return create_record(get_user_file_path(), 5, content_array) == 0? true : false;
    }
    return false;
}

bool is_user_exist(char* username){
    return is_record_exist(get_user_file_path(), 1, username, 5);
}

struct User* read_user_record(char* username, struct User* user_information){
    char** user_information_array = calloc(5, sizeof(char*));

    read_record(get_user_file_path(), 1, username, user_information_array);

    if(user_information_array[0] != NULL) {
        array_to_user(user_information_array, user_information);
    }else{
        user_information = NULL;
    }
}

bool update_user_record(char* username, char* display_name, char* password, enum Role role){
    struct User* old_user_information = malloc(sizeof(struct User));
    read_user_record(username, old_user_information);

    if(old_user_information != NULL) {
        char **new_user_content = calloc(5, sizeof(char *));

        new_user_content[0] = calloc(3, sizeof(char));
        sprintf(new_user_content[0], "%d", old_user_information->user_id);
        new_user_content[1] = username;
        new_user_content[2] = display_name;
        new_user_content[3] = password;
        new_user_content[4] = user_role_to_char(role);

        return update_record(get_user_file_path(), 1, username, new_user_content) == 0 ? true : false;
    }
    return false;
}

bool delete_user_record(char* username){
    return (delete_record(get_user_file_path(), 1, username) == 0)? true: false;
}

int get_number_of_users(){
    return get_number_of_records(get_user_file_path());
}

void get_all_users(struct User* user[]){
    char** user_record_strings = malloc(get_number_of_records(get_user_file_path()) * sizeof(char*));
    get_all_available_records(read_file(get_user_file_path()), user_record_strings);
}

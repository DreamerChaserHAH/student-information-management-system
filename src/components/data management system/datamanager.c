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

static struct User* array_to_user(char** user_information_array){
    return create_user_object(atoi(user_information_array[0]),
                                user_information_array[1],
                                user_information_array[2],
                                user_information_array[3],
                                atoi(user_information_array[4]));
}

static struct StudentRecord* array_to_student_record(char** student_record_information_array){
    return create_student_record_object(atoi(student_record_information_array[0]),
                                            atoi(student_record_information_array[1]),
                                            atoi(student_record_information_array[2]),
                                            atoi(student_record_information_array[3]));
}

static struct Course* array_to_course_record(char** course_record_information_array){
    return create_course_object(atoi(course_record_information_array[0]), 
                                atoi(course_record_information_array[1]),
                                course_record_information_array[2],
                                atoi(course_record_information_array[3]));
}

static struct Programme* array_to_programme_record(char** programme_record_information_array){
    return create_programme_object(atoi(programme_record_information_array[0]),
                                    programme_record_information_array[1],
                                    atoi(programme_record_information_array[2]));
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

struct User* create_user_object(int user_id, char* username, char* display_name, char* password, enum Role role){
    struct User* user_object = malloc(sizeof(struct User));
    user_object->user_id = user_id;
    user_object->username = username;
    user_object->display_name = display_name;
    user_object->password = password;
    user_object->role = role;
    return user_object;
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

struct User* read_user_record(char* username){
    if(is_user_exist(username)){
        char** user_information_array = calloc(5, sizeof(char*));

        read_record(get_user_file_path(), 1, username, user_information_array, 0);

        if(user_information_array[0] != NULL) {
            return array_to_user(user_information_array);
        }
    }
    return NULL;
}

bool update_user_record(char* username, char* display_name, char* password, enum Role role){
    struct User* old_user_information = read_user_record(username);

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

struct StudentRecord* create_student_record_object(int user_id, int course_id, int attendance, int score){
    struct StudentRecord* record = malloc(sizeof(struct StudentRecord));
    record->user_id = user_id;
    record->course_id = course_id;
    record->attendance = attendance;
    record->score = score;
    return record;
}

bool create_student_record(struct StudentRecord* record){
    /// !!! retrieve whether if the record with the same username exist or not (DONE)
    /// !!! create an array that contains all the data that we want to add (DONE)
    /// !!! return whether if the record has been created successfully (DONE)

    if(!is_student_record_exist(record->user_id)){
        char** content_array = calloc(4, sizeof(char*));
        content_array[0] = integer_to_string(record->user_id);
        content_array[1] = integer_to_string(record->course_id);
        content_array[2] = integer_to_string(record->attendance);
        content_array[3] = integer_to_string(record->score);

        return create_record(get_student_record_file_path(), 4, content_array) == 0? true : false;
    }
    return false;
}

bool is_student_record_exist(int user_id){
    char* user_id_string = calloc(3, sizeof(char));
    sprintf(user_id_string, "%d", user_id);
    return is_record_exist(get_student_record_file_path(), 0, user_id_string, 4);
}

struct StudentRecord** read_student_record(int user_id){

    if(is_student_record_exist(user_id)) {
        int* student_record_indexes = get_all_records_with_criteria(get_student_record_file_path(), 0, integer_to_string(user_id));

        int total_count = 0;
        while(student_record_indexes[total_count] != -1){
            total_count++;
        }

        struct StudentRecord** result = malloc(sizeof(struct StudentRecord) * (total_count + 1));
        int current_index = 0;
        while(student_record_indexes[current_index] != -1){
            char *student_record_information = read_line(get_student_record_file_path(), student_record_indexes[current_index] + 1);
            char** student_record_information_array = calloc(4, sizeof(char*));
            get_all_available_columns(student_record_information, student_record_information_array);
            result[current_index] = array_to_student_record(student_record_information_array);
            current_index++;
        }  
        result[current_index] = NULL;
        return result;
    }
    return NULL;
}

struct StudentRecord* read_student_record_with_specific_course(int user_id, int course_id){
    struct StudentRecord** all_records_of_a_particular_student = read_student_record(user_id);
    int current_index = 0;
    while(all_records_of_a_particular_student[current_index] != NULL){
        if(all_records_of_a_particular_student[current_index]->course_id == course_id){
            return all_records_of_a_particular_student[current_index];
        }
        current_index++;
    }
    return NULL;
}

struct Course** get_all_student_courses(int user_id){
    struct StudentRecord** student_records = read_student_record(user_id);

    int total_count = 0;
    while(student_records[total_count] != NULL){
        total_count++;
    }

    struct Course** result = malloc(sizeof(struct Course) * (total_count + 1));
    int current_index = 0;
    while(student_records[current_index] != NULL){
        result[current_index] = read_course_record(student_records[current_index]->course_id);
        current_index++;
    }
    result[current_index] = NULL;
    return result;
}

struct StudentRecord **get_all_student_records_with_specific_course(int course_id)
{
    int *student_record_indexes = get_all_records_with_criteria(get_student_record_file_path(), 1, integer_to_string(course_id));

    int total_count = 0;
    while (student_record_indexes[total_count] != -1)
    {
        total_count++;
    }

    struct StudentRecord **result = malloc(sizeof(struct StudentRecord) * (total_count + 1));
    int current_index = 0;
    while (student_record_indexes[current_index] != -1)
    {
        char *student_record_information = read_line(get_student_record_file_path(), student_record_indexes[current_index] + 1);
        char **student_record_information_array = calloc(4, sizeof(char *));
        get_all_available_columns(student_record_information, student_record_information_array);
        result[current_index] = array_to_student_record(student_record_information_array);
        current_index++;
    }
    result[current_index] = NULL;
    return result;
}

bool update_student_record(struct StudentRecord* record){
    struct StudentRecord* old_student_record_information = read_student_record(record->user_id);

    if(old_student_record_information != NULL) {
        char **new_record_content = calloc(4, sizeof(char *));

        new_record_content[0] = integer_to_string(record->user_id);
        new_record_content[1] = integer_to_string(record->course_id);
        new_record_content[2] = integer_to_string(record->attendance);
        new_record_content[3] = integer_to_string(record->score);

        return update_record(get_student_record_file_path(), 0, new_record_content[0], new_record_content) == 0 ? true : false;
    }
    return false;
}

bool delete_student_record(int user_id){
    return (delete_record(get_student_record_file_path(), 0, integer_to_string(user_id)) == 0)? true: false;
}

int get_number_of_student_records(){
    return get_number_of_records(get_student_record_file_path());
}

struct StudentRecord* get_all_student_records(){

}

struct Course* create_course_object(int course_id, int programme_id, char* course_name, int lecturer_id){
    struct Course* record = malloc(sizeof(struct Course));
    record->course_id = course_id;
    record->programme_id = programme_id;
    record->course_name = course_name;
    record->lecturer_id = lecturer_id;
    return record;
}

bool is_course_exist(int course_id){
    char* course_id_string = calloc(3, sizeof(char));
    sprintf(course_id_string, "%d", course_id);
    return is_record_exist(get_course_file_path(), 0, course_id_string, 4);
}

bool create_course_record(int programme_id, char* course_name, int lecturer_id){
    /// !!! check what is the id we have to supply to the course (DONE)
    /// !!! create an array that contains all the data that we want to add (DONE)
    /// !!! return whether if the record has been created successfully (DONE)
    
    char** last_course_information = calloc(4, sizeof(char*));
    int last_line_number = get_number_of_records(get_course_file_path());
    get_all_available_columns(read_line(get_course_file_path(), last_line_number), last_course_information);
    char* new_course_id = calloc(3, sizeof(char));
    sprintf(new_course_id, "%d", last_course_information[0] != NULL? atoi(last_course_information[0]) + 1 : 1);
        
    char** content_array = calloc(4, sizeof(char*));
    content_array[0] = new_course_id;
    content_array[1] = integer_to_string(programme_id);
    content_array[2] = course_name;
    content_array[3] = integer_to_string(lecturer_id);

    return create_record(get_course_file_path(), 4, content_array) == 0? true : false;
}

struct Course* read_course_record(int course_id){
    if(is_course_exist(course_id)) {
        char **course_information_array = calloc(4, sizeof(char *));

        read_record(get_course_file_path(), 0, integer_to_string(course_id), course_information_array, 0);

        if (course_information_array[0] != NULL) {
            return array_to_course_record(course_information_array);
        }
    }
    return NULL;
}

bool update_course_record(int course_id, int programme_id, char* course_name, int lecturer_id){
    if(is_course_exist(course_id)) {

        char **new_record_content = calloc(4, sizeof(char *));

        new_record_content[0] = integer_to_string(course_id);
        new_record_content[1] = integer_to_string(programme_id);
        new_record_content[2] = course_name;
        new_record_content[3] = integer_to_string(lecturer_id);

        return update_record(get_course_file_path(), 0, new_record_content[0], new_record_content) == 0 ? true : false;
    }
    return false;
}

bool delete_course_record(int course_id){
    if(is_course_exist(course_id)){
        return delete_record(get_course_file_path(), 0, integer_to_string(course_id)) == 0? true: false;
    }
    return false;
}

int get_number_of_courses(){
    return get_number_of_records(get_course_file_path());
}

struct Course* get_all_course_records(){

}

struct Programme* create_programme_object(int programme_id, char* programme_name, int leader_id){
    struct Programme* record = malloc(sizeof(struct Programme));
    record->programme_id = programme_id;
    record->programme_name = programme_name;
    record->leader_id = leader_id;
    return record;
}

bool is_programme_exist(int programme_id){
    char* programme_id_string = calloc(3, sizeof(char));
    sprintf(programme_id_string, "%d", programme_id);
    return is_record_exist(get_programme_file_path(), 0, programme_id_string, 3);
}

bool create_programme_record(char* programme_name, int leader_id){
        /// !!! check what is the id we have to supply to the course (DONE)
    /// !!! create an array that contains all the data that we want to add (DONE)
    /// !!! return whether if the record has been created successfully (DONE)
    
    char** last_programme_information = calloc(3, sizeof(char*));
    int last_line_number = get_number_of_records(get_programme_file_path());
    get_all_available_columns(read_line(get_programme_file_path(), last_line_number), last_programme_information);
    char* new_programme_id_string = calloc(3, sizeof(char));
    sprintf(new_programme_id_string, "%d", last_programme_information[0] != NULL? atoi(last_programme_information[0]) + 1 : 1);
        
    char** content_array = calloc(4, sizeof(char*));
    content_array[0] = new_programme_id_string;
    content_array[1] = programme_name;
    content_array[2] = integer_to_string(leader_id);

    return create_record(get_programme_file_path(), 3, content_array) == 0? true : false;
}

struct Programme* read_programme_record(int programme_id){
    if(is_programme_exist(programme_id)) {
        char **programme_information_array = calloc(3, sizeof(char *));

        read_record(get_programme_file_path(), 0, integer_to_string(programme_id), programme_information_array, 0);

        if (programme_information_array[0] != NULL) {
            return array_to_programme_record(programme_information_array);
        }
    }
    return NULL;
}

bool update_programme_record(int programme_id, char* programme_name, int leader_id){
    if(is_programme_exist(programme_id)) {

        char **new_record_content = calloc(3, sizeof(char *));

        new_record_content[0] = integer_to_string(programme_id);
        new_record_content[1] = programme_name;
        new_record_content[2] = integer_to_string(leader_id);

        return update_record(get_programme_file_path(), 0, new_record_content[0], new_record_content) == 0 ? true : false;
    }
    return false;
}

bool delete_programme_record(int programme_id){
    if(is_programme_exist(programme_id)){
        return delete_record(get_programme_file_path(), 0, integer_to_string(programme_id)) == 0? true: false;
    }
    return false;
}

int get_number_of_programme(){
    return get_number_of_records(get_programme_file_path());
}

struct Programme* get_all_programme_records(){

}
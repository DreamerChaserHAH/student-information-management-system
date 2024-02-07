/// Author : Htet Aung Hlaing

#include <database.h>
#include <string.h>

#if defined(__MINGW32__) || defined(__MINGW64__)
#define COMPILER_MINGW
#elif defined(__GNUC__)
#define COMPILER_GCC
#endif

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/// @brief function to easily generate formatted path
/// @param path1 the first part of the formatted string
/// @param path2 the second part of the formatted string
/// @return the final formatted string
static char* format_path(char path1[], char path2[]);

/// @brief function to easily generate .txt filename
/// @param filename filename without .txt
/// @return formatted filename
static char* get_file_name(char* filename);

/// @brief abstraction layer function so that making directory becomes platform-agnostic
/// @param directory_name the name of the directory we are going to create
/// @param permission the permission settings for the directory
/// @return status code
static int make_directory(char* directory_name, int permission);

/// @brief abstraction layer function so that deleting directory becomes platform-agnostic
/// @param directory_name the name of the directory we are going to delete
/// @return status code
static int delete_directory(char* directory_name);

/// @brief get the size of the file in char size
/// @param file_path the file that we want to check the size of
/// @return get the length of the file in integer
static long get_file_size(char* file_path);

/// @brief abstraction layer function to create the file (platform-agnostic)
/// @param file_path the file in which any data we want to add will house
/// @return status code
static int create_file(char* file_path);

/// @brief abstraction layer function to delete the file (platform-agnostic)
/// @param file_path the path of the file we want to delete
/// @return status code
static int delete_file(char* file_path);

/// @brief abstraction layer function to read the file (platform-agnostic)
/// @param file_path the path of the file which we want to read
/// @return the content of the file
static char* read_file(char* file_path);

/// @brief abstraction layer function to write to a specific file (platform-agnostic)
/// @param file_path the path of the file which we want to write to
/// @param content the content inside the file
/// @return the status code
static int write_file(char* file_path, char* content);

/// @brief abstraction layer function to append to a specific file (platform-agnostic)
/// @param file_path the path of the file which we want to append to
/// @param content the content inside the file
/// @return the status code
static int append_file(char* file_path, char* content);

/// @brief base function that counts how many individual element can be formed after splitting
/// @param content the original string content
/// @param delimiter character used to split the string
/// @return actual number of value
static int get_number_of_value(char* content, char* delimiter);

/// @brief get all the elements inside the splittable string that we pass in
/// @param content the original string content
/// @param array_size the size of the array so that we can allocated without wasting space
/// @param delimiter character used to split the string
/// @param *target_array the pointer of the array in which we are going to paste the content;
static void get_values_in_array(char* content, int array_size, char* delimiter, char* target_array[]);

/// @brief get all the total numbers of horizontal records available in any csv file
/// @param content what we find inside the csv file
/// @return the number of horizontal records
static int get_number_of_record(char* content);

/// @brief get all the records inside the csv file
/// @param content what we find inside the csv file
/// @param *records the pointer of the array in which we are going to paste the content
static void get_all_records(char* content, char *records[]);

/// @brief get the total number of columns available in any particular record
/// @param content the string content of each individual row
/// @return the number of column inside the record we feed
static int get_number_of_columns(char* content);

/// @brief get all the data inside any particular record
/// @param content the string representation of the record
/// @param *data the pointer of the array that contains all the data inside that particular record
static void get_all_data_in_record(char* content, char* data[]);

/// @brief process the csv and return values to be processed
/// @param content the string content we read
/// @return the string array with all the data inside the file
static char** process_csv(char* content);

/// @brief manages the status code return by other functions
/// @param status 0 -> success, other -> failed
/// @param success_message the message to be displayed when the action executed successfully
/// @param error_message the message to be displayed when the action does not execute as expected
///* @param quit_on_failed checks whether if the program should quit when failed
static void manage_status(int status, char* success_message, char* error_message, bool quit_on_failed);

/// @brief check if a folder exists or not
/// @param folder_path the path in which the folder resides
/// @return boolean value on whether if the folder exists or not
static bool is_folder_here(char* folder_path);

/// @brief check if a file exists or not
/// @ param file_path the path in which the file of interest resides
/// @return boolean value on whether if the file exists or not
static bool is_file_here(char* file_path);

/// @brief function for convenience that relies on format_path() to generate the path to specific database's folder
/// @param database_name the name of the database from which we are going to derive the path from
/// @ return the path of the database
static char* get_database_path(char* database_name);

/// @brief function for convenience that relies on get_database_path() and format_path() to generate the path to a specific table's file
/// @param database_name the name of the database from which we are going to derive the path from
/// @param table_name the name of the table from which we are going to derive the path from
static char* get_table_path(char* database_name, char* table_name);

/// @brief get the file path of the index file that contains how the information is stored inside the tables
/// @param database_name the name of the database we are going to code inside of
/// @return the path of the index file
static char* get_index_file_path(char* database_name);

/// @brief create the index file related with the database
/// @param database the name of the database we are dealing with
/// @return status code
static int create_index_file(char* database_name);

/// @brief add the table into the index file for faster access in the future
/// @param database_name the name of the database we are going to code inside of
/// @param table_name the name of the table we are going to create inside the idnex file
/// @param entity the DatabaseEntity of interest
static int add_to_index_file(char* database_name, char* table_name, struct DatabaseEntity* entity);

static char* format_path(char path1[], char path2[]){
    char* formatted_path = malloc(100 * sizeof(char));
    snprintf(formatted_path, 100, "%s/%s", path1, path2);
    return formatted_path;
}

static char* get_file_name(char* filename){
    char* formatted_filename = malloc(100 * sizeof(char));
    sprintf(formatted_filename, "%s.txt", filename);
    return formatted_filename;
}

static int make_directory(char* directory_name, int permission) {
    #ifdef COMPILER_MINGW
        // Mingw Compiler
        return mkdir(directory_name);
    #elif defined(COMPILER_GCC)
        // GCC Compiler
        return mkdir(directory_name, permission);
    #else
        return mkdir(directory_name);
        debug_log_error_message("Compiler is neither MinGW nor GCC.\n");
    #endif

    return 0;
}

static int delete_directory(char* directory_name){
    #ifdef _WIN32
        return RemoveDirectory(directory_name);
    #else
        return rmdir(directory_name);
    #endif
}

static long get_file_size(char* file_path){
    FILE* file_pointer;
    file_pointer = fopen(file_path, "r");

    if(file_pointer == NULL){
        return 0;
    }
    fseek (file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);
    fclose(file_pointer);
    return file_size;
}

static int create_file(char* file_path){
    if(!is_file_here(file_path)){
        return write_file(file_path, "");
    }else {
        return 1;
    }
}

static int delete_file(char* file_path){
    if(is_file_here(file_path)) {
        return remove(file_path);
    }else {
        return 1;
    }
}

static char* read_file(char* file_path){
    if(is_file_here(file_path)){
        long file_size = get_file_size(file_path);

        FILE *file_pointer = fopen(file_path, "r");
        char* file_content = (char*) malloc(file_size * sizeof(char));

        if(file_content == NULL){
            fclose(file_pointer);
            return "";
        }

        fread(file_content, sizeof(char), file_size, file_pointer);
        fclose(file_pointer);
        return file_content;
    }else {
        return "";
    }
}

static int write_file(char* file_path, char* content){
    FILE *file_pointer = fopen(file_path, "w");
    fprintf(file_pointer, content);
    fclose(file_pointer);
    return 0;
}

static int append_file(char* file_path, char* content){
    if(is_file_here(file_path)){
        FILE *file_pointer = fopen(file_path, "a");
        fprintf(file_pointer, content);
        fclose(file_pointer);
        return 0;
    }else{
        return -1;
    }
}

static int get_number_of_value(char* content, char* delimiter){
    char* local_content = malloc(MAX_BUFFER_SIZE);
    strcpy(local_content, content);

    int number_of_data = 0;
    char* token = strtok(local_content, delimiter);

    while(token != NULL){
        token = strtok(NULL, delimiter);
        number_of_data++;
    }
    free(local_content);

    return number_of_data;
}

static int get_number_of_value2(char* content, char* delimiter){
    char* local_content = malloc(MAX_BUFFER_SIZE);
    strcpy(local_content, content);

    int number_of_data = 0;
    char* token = strtok(local_content, delimiter);
    printf("%s \n", token);

    while(token != NULL){
        token = strtok(NULL, delimiter);
        number_of_data++;
    }
    free(local_content);

    return number_of_data;
}

static void get_values_in_array(char* content, int array_size, char* delimiter, char* target_array[]){
    char* local_content = malloc(MAX_BUFFER_SIZE);
    strcpy(local_content, content);

    int counter = 0;
    char* token = strtok(local_content, delimiter);
    while(token != NULL){
        target_array[counter] = (char*) malloc(20& sizeof(char));
        sprintf(target_array[counter], "%s", token);
        token = strtok(NULL, delimiter);
        counter++;
    }

    free(local_content);
}

static int get_number_of_record(char* content){
    return get_number_of_value(content, "\n");
}

static int get_number_of_record2(char* content){
    return get_number_of_value2(content, "\n");
}

static void get_all_records(char* content, char *records[]){
    get_values_in_array(content, get_number_of_record(content), "\n", records);
}

static int get_number_of_columns(char* content){
    return get_number_of_value(content, ",");
}

static void get_all_data_in_record(char* content, char* data[]){
    get_values_in_array(content, get_number_of_columns(content), ",", data);
}

static char** process_csv(char* content){

    char* local_content = malloc(MAX_BUFFER_SIZE);
    strcpy(local_content, content);
    int number_of_record = get_number_of_record(content);
    char** data = (char**)malloc(number_of_record * sizeof(char*));
    for(int i = 0; i < number_of_record; i++){
        data[i] = (char*)malloc(MAX_COLUMN_COUNT * MAX_VALUE_LENGTH * sizeof(char));
        char* current_line = strtok(NULL, "\n");
    }
}

static void manage_status(int status, char* success_message, char* error_message, bool quit_on_failed){
    if(status == 0){
        log_message(success_message);
    }else{
        log_error_message(error_message);
        if(quit_on_failed){
            exit(1);
        }
    }
}

static bool is_folder_here(char* folder_path){
    struct stat folder_status;
    return stat(folder_path, &folder_status) == 0 && S_ISDIR(folder_status.st_mode);
}

static bool is_file_here(char* file_path){
    struct stat file_status;
    return stat(file_path, &file_status) == 0;
}

static char* get_database_path(char* database_name){
    return format_path("databases", database_name);
}

static char* get_table_path(char* database_name, char* table_name){
    return format_path(get_database_path(database_name), get_file_name(table_name));
}

static char* get_index_file_path(char* database_name){
    return format_path(get_database_path(database_name), get_file_name("index"));
}

static int create_index_file(char* database_name){
    char* message = malloc(100 * sizeof(char));
    sprintf(message, "Trying to create index file %s", get_index_file_path(database_name));
    log_message(message);
    return create_file(get_index_file_path(database_name));
}

static int add_to_index_file(char* database_name, char* table_name, struct DatabaseEntity* entity){
    if(is_database_here(database_name)){
        if(is_file_here(get_index_file_path(database_name))){
            manage_status(append_file(get_index_file_path(database_name), database_entity_to_string_format(entity)),
                          "Index file has been successfully appended",
                          "Cannot add to index file! Something went wrong",
                          true);
        }else{
            log_error_message("Cannot add to index file -> Database index file does not exist");
        }
    }else{
        log_error_message("Cannot add to index file -> Database does not exist");
    }
}

bool is_database_environment_setup(){
    return is_folder_here("databases");
}

void setup_database_environment(){
    if(!is_database_environment_setup()) {
        manage_status(
                make_directory("databases", 0777),
                "Database environment set up successfully",
                "Cannot set up database environment!",
                true);
    }
}

bool is_database_here(char* database_name){
    return is_folder_here(format_path("databases", database_name));
}

void create_database(char* database_name){
    if (!is_database_here(database_name)) {
        char *database_path = get_database_path(database_name);
        manage_status(
                make_directory(database_path, 0777),
                "Database has been created successfully",
                "Cannot create database!",
                true
        );
        manage_status(create_index_file(database_name),
                      "Database index file has been created successfully",
                      "Creation of database index file has failed",
                      true);
    }else{
        log_message("Database already exists");
    }
}

void delete_database(char* database_name){
    char* database_path = format_path("databases", database_name);
    manage_status(
            delete_directory(database_path),
            "Database has been deleted successfully",
            "Cannot delete database",
            false
            );

}

bool is_table_here(char* database_name, char* table_name){
    return is_file_here(get_table_path(database_name, table_name));
}

void copy_string_array(char* original[], char* destination[], int size){
    for(int i = 0; i < size; i++){
        destination[i] =  malloc(50 * sizeof(char));
        strcpy(destination[i], original[i]);
    }
}

void copy_string_array2(char* original[], char* destination[], int size){
    for(int i = 0; i < size; i++){
        destination[i] =  malloc(50 * sizeof(char));
        printf("%s \n", original[i]);
        strcpy(destination[i], original[i]);
    }
}

void get_record(char* content, int criteria_index, const char* criteria_value, char* data[], int* amount_of_data){
    int number_of_records = get_number_of_record(content);

    char *records[number_of_records];
    get_all_records(content, records);

    for(int i = 0; i < number_of_records; i++){
        char* content = malloc(MAX_BUFFER_SIZE * sizeof(char));
        sprintf(content, "%s", records[i]);
        int number_of_data = get_number_of_columns(content);

        char *datas[number_of_data];
        get_all_data_in_record(content, datas);

        if(strcmp(datas[criteria_index], criteria_value) == 0){
            copy_string_array(datas, data, number_of_data);
            if(amount_of_data != NULL) {
                *amount_of_data = number_of_data;
            }
            break;
        }
    }
}

void get_record2(char* content, int criteria_index, const char* criteria_value, char* data[], int* amount_of_data){
    int number_of_records = get_number_of_record2(content);
    printf("Number of records %d \n", number_of_records);

    char *records[number_of_records];
    get_all_records(content, records);

    for(int i = 0; i < number_of_records; i++){
        char* localcontent = malloc(MAX_BUFFER_SIZE * sizeof(char));
        sprintf(localcontent, "%s", records[i]);
        int number_of_data = get_number_of_columns(localcontent);

        char *datas[number_of_data];
        get_all_data_in_record(localcontent, datas);
        printf("comparing between %s and %s", datas[criteria_index], criteria_value);
        if(strcmp(datas[criteria_index], criteria_value) == 0){
            copy_string_array(datas, data, number_of_data);
            if(amount_of_data != NULL) {
                *amount_of_data = number_of_data;
            }
            break;
        }
    }
}

char* get_record_index_data(char* content, int criteria_index, const char* criteria_value, int target_index){
    char* data[MAX_COLUMN_COUNT];
    get_record(content, criteria_index, criteria_value, data, NULL);
    if(data[0] != NULL){
        return data[target_index];
    }
    return "";
}

char* get_table_index_data(char* database_name, const char* table_name, int index){
    char* index_file_content = read_file(get_index_file_path(database_name));
    return get_record_index_data(index_file_content, 0, table_name, index);
}

int get_table_column_index(char* database_name, const char* table_name, char* column_name){
    char* index_file_content = read_file(get_index_file_path(database_name));
    int amount_of_columns = 0;
    char* index_record_data[MAX_COLUMN_COUNT];
    get_record(index_file_content, 0, table_name, index_record_data, &amount_of_columns);
    for(int i = 0; i < amount_of_columns; i++){
        if(strcmp(index_record_data[i], column_name) == 0){
            return i - 2;
        }
    }
    return -1;
}

int get_table_column_count(char* database_name, char* table_name){
    char* index_file_content = read_file(get_index_file_path(database_name));
    char* data[MAX_COLUMN_COUNT];
    int amount_of_data;
    get_record(index_file_content, 0, table_name, data, &amount_of_data);
    return amount_of_data - 2;
}

int get_table_type(char* databasename, const char* table_name){
    char* table_type = get_table_index_data(databasename, table_name, 1);
    return atoi(table_type);
}

void create_table(char* database_name, char* table_name, struct DatabaseEntity entity){
    log_message("Creating table function");

    if(!is_table_here(database_name, table_name)) {
        char *table_path = get_table_path(database_name, table_name);

        manage_status(create_file(table_path),
                      "Table has been created successfully",
                      "Cannot create table! Something went wrong",
                      true);
        add_to_index_file(database_name, table_name, &entity);
        /// !!! Need to add more content here
    }else{
        log_error_message("Table already exists!");
    }

}

void delete_table(char* database_name, char* table_name){

    // Check if table exists or not
    if(is_table_here(database_name, table_name)) {
        char *table_path = get_table_path(database_name, table_name);
        manage_status(delete_file(table_path),
                      "Table has been deleted successfully",
                      "Cannot delete table! Check if it even exists or not :D",
                      false);
    }else{
        // if table does not exist, display error
        log_error_message("Table does not exist");
    }
}

void create_record(char* database_name, char* table_name, struct RecordEntity new_data){
    /// !!! It will first check whether if the data type is what we are expecting
    /// !!! If it is correct, we will create a new record
    /// !!! If it is not correct, we will show an error.
    if(is_table_here(database_name, table_name)){
        if(is_file_here(get_index_file_path(database_name))){
            if(new_data.data_type == get_table_type(database_name, table_name)){
                char* table_path = get_table_path(database_name, table_name);
                if(!is_record_here(database_name, table_name, 0, new_data.data[0])) {
                    append_file(table_path, record_entity_to_string_format(&new_data));
                }else{
                    log_error_message("Record already exists!");
                }
            }else{
                log_error_message("Data Type MisMatch!");
            }
        }else{
            log_error_message("Index file does not exist for database");
        }
    }else{
        log_error_message("Table does not exist!");
    }
}

bool is_record_here(char* database_name, char* table_name, int index, char* value){
    /// !!! It will check whether if a certain record with a certain id exists in the table or not
    if(is_table_here(database_name, table_name)){
        char* table_path = get_table_path(database_name, table_name);
        char* table_file_content = read_file(table_path);

        char* record_data = get_record_index_data(table_file_content, index, value, 2);
        return !strcmp(record_data, "");
    }else{
        return false;
    }
}

void read_record(char* database_name, char* table_name, char* column_name, char* criteria_value, struct RecordEntity* data){
    /// !!! It will first check whether if the receiving variable *data is what we are expecting
    /// !!! If it is correct, we will first check if the variable exists or not, and then we will read from the record and put it into the variable
    /// !!! If it is not correct, we will quit the application
    if(is_table_here(database_name, table_name)){
        char* table_path = get_table_path(database_name, table_name);

        char* table_file_content = read_file(table_path);

        char* record_data[MAX_COLUMN_COUNT];
        int number_of_data = get_table_column_count(database_name, table_name);
        int column_index = get_table_column_index(database_name, table_name, column_name);

        if(column_index != -1) {
            printf("Some many values %d", number_of_data);
            get_record(table_file_content, column_index, criteria_value, record_data, NULL);
            printf("Value inside user %s \n", record_data[0]);
            raw_to_record_entity_format(get_table_type(database_name, table_name), record_data, number_of_data, data);
            return;
        }
        data = NULL;
    }else{
        log_error_message("Record does not exist");
    }
}

void read_all_records(char* database_name, char* table_name, void* data){
    /// !!! It will first check whether if the receiving variable *data is what we are expecting
    /// !!! If it is correct, we will query through every data, and push the list into the data array variable
    /// !!! If it is not correct, we will quit the application
}

void update_record(char* database_name, char* table_name, int record_id, struct RecordEntity new_data){
    /// !!! It will first check whether if the receiving variable *data is what we are expecting
    /// !!! If it is correct, we will try to find the record on the database, if it exists, we will update it, if it does not, we will show error and exit
    /// !!! If it is not correct, we will quit the application
}

void delete_record(char* database_name, char* table_name, int record_id){
    /// !!! It will first check whether if the record exists or not
    /// !!! If it exists, we delete the record
    /// !!! If it does not exist, don't
}

char* find_record(char* database_name, char* table_name, char* column, char* value){

}



struct DatabaseEntity* create_database_entity(int data_type, char* data_name, char** new_columns, size_t num_of_columns){
    struct DatabaseEntity* entity = malloc(sizeof(struct DatabaseEntity));
    if (entity == NULL){
        return NULL;
    }

    entity -> data_type = data_type;
    entity -> data_name = data_name;
    entity->columns = malloc(num_of_columns *sizeof(char*));
    if(entity->columns == NULL){
        free(entity);
        return NULL;
    }
    entity->num_of_columns = num_of_columns;
    for(size_t i = 0; i < num_of_columns; ++i){
        entity->columns[i] = new_columns[i];
    }
    return entity;
}

char* database_entity_to_string_format(struct DatabaseEntity* entity){
    char* formatted_path = malloc(100 * sizeof(char));
    sprintf(formatted_path, "%s,%d", entity->data_name, entity->data_type);
    for(size_t index = 0; index < entity->num_of_columns; index++){
        sprintf(formatted_path, "%s,%s", formatted_path, entity->columns[index]);
    }
    return formatted_path;
}

struct RecordEntity* create_record_entity(int data_type, char** new_data, size_t num_of_columns){
    struct RecordEntity* entity = malloc(sizeof(struct RecordEntity));
    if(entity == NULL){
        return NULL;
    }

    entity -> data_type = data_type;
    entity -> data = malloc(num_of_columns * sizeof(char*));
    if(entity -> data == NULL){
        free(entity);
        return NULL;
    }

    entity -> num_of_columns = num_of_columns;
    for(size_t i = 0; i < num_of_columns; ++i){
        entity -> data[i] = new_data[i];
    }
    return entity;
}

char* record_entity_to_string_format(struct RecordEntity* entity){
    char* formatted_path = malloc(120 * sizeof(char));
    sprintf(formatted_path, "%s", entity->data[0]);
    for(size_t index = 1; index < entity -> num_of_columns; index++){
        sprintf(formatted_path, "%s,%s", formatted_path, entity->data[index]);
    }
    sprintf(formatted_path, "%s\n", formatted_path);
    return formatted_path;
}

void raw_to_record_entity_format(int data_type, char* data_array[], int number_of_columns, struct RecordEntity* entity){
    entity->data_type = data_type;
    printf("Trying to copy");
    entity->data = malloc(number_of_columns * sizeof(char*));
    copy_string_array(data_array, entity->data, number_of_columns);
}
/// Author : Htet Aung Hlaing

#include <database.h>

/// @brief check whether if the dedicated folder for databases exists
static bool is_database_environment_setup();

/// @brief manages the status code return by other functions
/// @param status 0 -> success, other -> failed
/// @param success_message the message to be displayed when the action executed successfully
/// @param error_message the message to be displayed when the action does not execute as expected
///* @param quit_on_failed checks whether if the program should quit when failed
static void manage_status(int status, char* success_message, char* error_message, bool quit_on_failed){
    if(status == 0){
        printf("%s \n", success_message);
    }else{
        printf("Fatal Error: %s \n", error_message);
        if(quit_on_failed){
            exit(1);
        }
    }
}

static void get_database_path();

bool is_database_environment_setup(){
    struct stat folder_status;
    return stat("databases", &folder_status) == 0 && S_ISDIR(folder_status.st_mode);
}

void setup_database_environment(){
    if(!is_database_environment_setup()) {
        manage_status(
                mkdir("databases"), // ? Removing the 0777 fixed it for me
                "Database environment set up successfully",
                "Cannot set up database environment!",
                true);
    }
}

bool create_database(char* database_name){
    char database_path[50];
    snprintf(database_path, sizeof(database_path), "databases/%s", database_name);
    manage_status(
            mkdir(database_path), // ? Removing the 0777 fixed it for me
            "Database has been created successfully",
            "Cannot create database!",
            true
            );
}

bool delete_database(char* database_name){
    char database_path[50];
}
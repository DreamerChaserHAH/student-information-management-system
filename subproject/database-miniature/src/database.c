/// Author : Htet Aung Hlaing

#include <database.h>

#if defined(__MINGW32__) || defined(__MINGW64__)
#define COMPILER_MINGW
#elif defined(__GNUC__)
#define COMPILER_GCC
#endif

/// @brief abstraction layer function so that making directory becomes platform-agnostic
/// @param directory_name the name of the directory we are going to create
/// @param permission the permission settings for the directory
/// @return status code
static int make_directory(char* directory_name, int permission) {
    #ifdef COMPILER_MINGW
        // Mingw Compiler
        return mkdir(directory_name);
    #elif defined(COMPILER_GCC)
        // GCC Compiler
        return mkdir(directory_name, permission);
    #else
        return mkdir(directory_name);
        printf("Compiler is neither MinGW nor GCC.\n");
    #endif

    return 0;
}


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
                make_directory("databases", 0777),
                "Database environment set up successfully",
                "Cannot set up database environment!",
                true);
    }
}

bool create_database(char* database_name){
    char database_path[50];
    snprintf(database_path, sizeof(database_path), "databases/%s", database_name);
    manage_status(
            make_directory(database_path, 0777),
            "Database has been created successfully",
            "Cannot create database!",
            true
            );
}

bool delete_database(char* database_name){
    char database_path[50];
}
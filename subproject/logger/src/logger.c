#include <logger.h>

void log_message(char* message){
    printf("Message: %s \n", message);
}

void debug_log_message(char* message){
    #ifdef DEBUG
        log_message(message);
    #endif
}

void log_error_message(char* message){
    printf("Fatal Error: %s \n", message);
}

void debug_log_error_message(char* message){
    #ifdef DEBUG
        log_error_message(message);
    #endif
}
//
// Created by User on 02/02/2024.
//

#include <common.h>
#include <datamanager.h>

typedef enum {
    USER,
    COURSE,
    ATTENDANCE
} FileType;

/// @brief the base function that reads data from the specific file
/// @param filename the filename of the file we are trying to read
/// @return (char*) content inside the file
static char* read_file(char* filename);

/// @brief the base function that writes data into the specific file.
/// @param filename the filename of the file we are trying to write into
/// @param content the actual content we are trying to write into the file
static void write_file(char* filename, char* content);

/// @brief the base function that appends data into the specific file on top of existing data
/// @param filename the filename of the file we are trying to write into
/// @param content the actual content we are trying to append into the file
static void append_file(char* filename, char* content);

static char* read_file(char* filename){
    FILE *fileptr = fopen(filename, "r");

    if (fileptr == NULL){
        printf("%s missing! Creating empty file again...", filename);
        write_file(filename, "");
        return read_file(filename);
    }

    return
}

static void write_file(char *filename, char *content){

}

static void append_file (char *filename, char *content){

}


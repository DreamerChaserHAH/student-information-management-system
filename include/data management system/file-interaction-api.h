#ifndef SIMS_FILE_INTERACTION_API_H

#include <common.h>
#include "sys/stat.h"

#define SIMS_FILE_INTERACTION_API_H

/// @brief check if a file exists or not
/// @ param file_path the path in which the file of interest resides
/// @return boolean value on whether if the file exists or not
bool is_file_here(char* file_path);

/// @brief get the size of the file in char size
/// @param file_path the file that we want to check the size of
/// @return get the length of the file in integer
long get_file_size(char* file_path);

/// @brief abstraction layer function to create the file (platform-agnostic)
/// @param file_path the file in which any data we want to add will house
/// @return status code
int create_file(char* file_path);

/// @brief abstraction layer function to delete the file (platform-agnostic)
/// @param file_path the path of the file we want to delete
/// @return status code
int delete_file(char* file_path);

/// @brief abstraction layer function to read the file (platform-agnostic)
/// @param file_path the path of the file which we want to read
/// @return the content of the file
char* read_file(char* file_path);

/// @brief abstraction layer function to write to a specific file (platform-agnostic)
/// @param file_path the path of the file which we want to write to
/// @param content the content inside the file
/// @return the status code
int write_file(char* file_path, char* content);

/// @brief abstraction layer function to append to a specific file (platform-agnostic)
/// @param file_path the path of the file which we want to append to
/// @param content the content inside the file
/// @return the status code
int append_file(char* file_path, char* content);

/// @brief abstraction layer function to read a specific line using the line number (platform-agnostic)
/// @param file_path the path of the file which we want to read from
/// @param line_number the vertical index of the file
/// @return the content of that particular line
char* read_line(char* file_path, int line_number);

/// @brief abstraction layer function to edit a specific line using the line number (platform-agnostic)
/// @param file_path the path of the file we want to write to
/// @param line_number the vertical index of the file
/// @param new_content the new line that we are going to add to the file
/// @return whether if editing was successful or not
int edit_line(char* file_path, int line_number, char* new_content);

/// @brief abstraction layer function to delete a specific line using the line number (platform-agnostic)
/// @param file_path the path of the file we want to delete from
/// @param line_number the vertical index of the file
/// @return whether if deleting was successful or not
int delete_line(char* file_path, int line_number);
#endif //SIMS_FILE_INTERACTION_API_H

#ifndef SIMS_DATAMANAGER_UTILITIES_H

#include <common.h>

#define SIMS_DATAMANAGER_UTILITIES_H

/// @brief get number of splittable values inside a string
/// @param content the string content of which we are going to split at
/// @return get the number
int get_number_of_splittable_value(char* content, char* delimiter);

/// @brief get splitted values inside a string array
/// @param content the original string content
/// @param array_size the size of the array so that we can allocated without wasting space
/// @param delimiter character used to split the string
/// @param *target_array the pointer of the array in which we are going to paste the content;
void get_splitted_values_in_array(char* content, int array_size, char* delimiter, char** target_array);

/// @brief turn the value array into a string
/// @param content_array the array that contains individual content
/// @return the formatted string
char* array_to_string(char** content_array, int array_length);

/// @brief copy strings for one array to another
/// @param original_array the original array that contains the strings of interest
/// @param destination_array the destination to which we are going to copy the value to
/// @param length the total length of the array
char* copy_array_string(char** original_array, char** destination_array, int length);

#endif //SIMS_DATAMANAGER_UTILITIES_H

#ifndef SIMS_CSV_PROCESSOR_API_H
#include <data management system/file-interaction-api.h>
#define SIMS_CSV_PROCESSOR_API_H

/// @brief get all the total numbers of horizontal records available in any csv file
/// @param content what we find inside the csv file
/// @return the number of horizontal records
int get_number_of_records(char* file_path);

/// @brief get all the records inside the csv file
/// @param content what we find inside the csv file
/// @param *records the pointer of the array in which we are going to paste the content
void get_all_available_records(char* file_path, char **records);

/// @brief get the total number of columns available in any particular record
/// @param content the string content of each individual row
/// @return the number of column inside the record we feed
int get_number_of_columns(char* record_string);

/// @brief get all the data inside any particular record
/// @param content the string representation of the record
/// @param *data the pointer of the array that contains all the data inside that particular record
void get_all_available_columns(char* record_string, char* data[]);

/// @brief append a record to the txt file of choice
/// @param file_path the target file path that we are going to write to
/// @param array_length the length of the array that we are trying to write
/// @param content_array the array that contains all the values that we need to care about
/// @return whether if adding has succeeded or not
int create_record(char* file_path, int array_length, char** content_array);

/// @brief read a record from the txt file of choice
/// @param criteria_index the column index that we are going to look at
/// @param criteria_value the value inside the column that we are going to check whether if it's the same or not
/// @param content_array where we are going to return our data into. It could be null which means didn't find any that meets criteria
void read_record(char* file_path, int criteria_index, char* criteria_value, char** content_array);

/// @brief read a record from the txt file of choice
/// @param criteria_index the column index that we are going to look at
/// @param criteria_value the value inside the column that we are going to check whether if it's the same or not
/// @param content_array the new array that will replace the existing data
int update_record(char* file_path, int criteria_index, char* criteria_value, char** content_array);

/// @brief read a record from the txt file of choice
/// @param criteria_index the column index that we are going to look at
/// @param criteria_value the value inside the column that we are going to check whether if it's the same or not
/// #return whether if the record has been successfully deleted or not
int delete_record(char* file_path, int criteria_index, char* criteria_value);

#endif //SIMS_CSV_PROCESSOR_API_H

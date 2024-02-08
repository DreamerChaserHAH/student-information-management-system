#ifndef SIMS_CSV_PROCESSOR_API_H
#include <data management system//file-interaction-api.h>
#define SIMS_CSV_PROCESSOR_API_H

/// @brief base function that counts how many individual element can be formed after splitting
/// @param content the original string content
/// @param delimiter character used to split the string
/// @return actual number of value
int get_number_of_value(char* content, char* delimiter);

/// @brief get all the elements inside the splittable string that we pass in
/// @param content the original string content
/// @param array_size the size of the array so that we can allocated without wasting space
/// @param delimiter character used to split the string
/// @param *target_array the pointer of the array in which we are going to paste the content;
void get_values_in_array(char* content, int array_size, char* delimiter, char* target_array[]);

/// @brief get all the total numbers of horizontal records available in any csv file
/// @param content what we find inside the csv file
/// @return the number of horizontal records
int get_number_of_records(char* content);

/// @brief get all the records inside the csv file
/// @param content what we find inside the csv file
/// @param *records the pointer of the array in which we are going to paste the content
void get_all_available_records(char* content, char *records[]);

/// @brief get the total number of columns available in any particular record
/// @param content the string content of each individual row
/// @return the number of column inside the record we feed
int get_number_of_columns(char* content);

/// @brief get all the data inside any particular record
/// @param content the string representation of the record
/// @param *data the pointer of the array that contains all the data inside that particular record
void get_all_available_data(char* content, char* data[]);

#endif //SIMS_CSV_PROCESSOR_API_H

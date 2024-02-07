/// Author : Htet Aung Hlaing
/// <summary>
/// The program will create a folder called databases inside the same folder as the executable
/// </summary>

#ifndef SIMS_DATABASE_H
#define SIMS_DATABASE_H

#include <common.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <database-entity.h>
#include <logger.h>

#define MAX_COLUMN_COUNT 100
#define MAX_BUFFER_SIZE 4096
#define MAX_VALUE_LENGTH 20

/// @brief check whether if the dedicated folder for databases exists
bool is_database_environment_setup();

/// @brief create a dedicated folder to store all the databases
void setup_database_environment();

/// @brief check if database is there or not
/// @param database_name the name of the database of interest
bool is_database_here(char* database_name);

/// @brief create a dedicated folder to act as a database
/// @param database_name : the name fo database we are going to create
void create_database(char* database_name);

/// @brief delete the dedicated folder that is acting as a database
/// @param database_name the name of the database we are going to create
void delete_database(char* database_name);

/// @brief check if the table is there or not
/// @param database_name the table in which we will try to find the table
/// @param table_name the table to check whether if it exists or not
bool is_table_here(char* database_name, char* table_name);

/// @brief Using the index file determine what data type is being stored
/// @param database_name the name of the database we are dealing with
/// @param table_name the table we are going to check
/// @return the integer showing us the data type
int get_table_type(char* database_name, const char* table_name);

/// @brief create another dedicated folder for a collection of specific data structure
/// @param database_name the name of the database in which we are going to create the table in
/// @param table_name the name of the table in which the data structure is going to be stored
/// @param base_struct the struct that defines the structure on how the data will be stored
void create_table(char* database_name, char* table_name, struct DatabaseEntity entity);

/// @brief delete the dedicated folder that is acting a place for a specific data structure
/// @param database_name the name of the database in which we are going to create the table in
/// @param table_name the name of the target table
void delete_table(char* database_name, char* table_name);

/// @brief insert a record into the table
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table in which we will insert
/// @param p any struct that we are going to put inside that database
void create_record(char* database_name, char* table_name, struct RecordEntity new_data);

/// @brief check if record with certain id is here or not
/// @param database_name the name of the database in which we are checking
/// @param table_name the name of the table in which we are looking at
/// @param record_id the specific record that we are trying to find
bool is_record_here(char* database_name, char* table_name, int index, char* value);

/// @brief read a record with specific key from the table (file with a specific name)
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will read the record
/// @param criteria_index the index we are going to look for hits
/// @param criteria_value the value that we are going to check at @criteria_index
/// @param data the uncasted data variable in which data is going be put into
// ! This needs to be changed to read_data or something because read is a inbuilt function i think?
// ! Thanks @Mahmood for reminding me!
void read_record(char* database_name, char* table_name, char* column_name, char* criteria_value, struct RecordEntity* data);

/// @brief read all the records from a table
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will read the record
/// @param *data the uncasted data variable in which a list of data is going to be put into
void read_all_records(char* database_name, char* table_name, void* data);

/// @brief update a record with a specific key from the table (rewrite the file with a specific name)
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table in which the record resides
/// @param record_id the id of the specific record of interest
/// @param data the new data we are going to add inside the variable
void update_record(char* database_name, char* table_name, int record_id, struct RecordEntity new_data);

/// @brief delete a record with specific key from the table (remove the file with a specific name)
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will remove the record
/// @param record_id the id of the specific data we are going to delete
void delete_record(char* database_name, char* table_name, int record_id);

/// @brief find a specific record with a specific value at the specific column
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will query the column on
/// @param column the name of the column of interest
/// @param value the value of the column that we are trying to find
/// @return the unique identifier of the record
char* find_record(char* database_name, char* table_name, char* column, char* value);

/// @brief get specific value from a specific record at the specific column
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will query the data
/// @param column the name of the column of interest
/// @return the value inside that particular column
char* get_value_from_record(char* database_name, char* table_name, char* column);

#endif //SIMS_DATABASE_H

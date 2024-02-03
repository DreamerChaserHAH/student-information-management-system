/// Author : Htet Aung Hlaing
/// <summary>
/// The program will create a folder called databases inside the same folder as the executable
/// </summary>

#ifndef SIMS_DATABASE_H
#define SIMS_DATABASE_H

#include <common.h>
#include <sys/stat.h>
#include <stdlib.h>

/// @brief create a dedicated folder to store all the databases
void setup_database_environment();

/// @brief create a dedicated folder to act as a database
/// @param database_name : the name fo database we are going to create
bool create_database(char* database_name);

/// @brief delete the dedicated folder that is acting as a database
/// @param database_name the name of the database we are going to create
bool delete_database(char* database_name);

/// @brief create another dedicated folder for a collection of specific data structure
/// @param database_name the name of the database in which we are going to create the table in
/// @param table_name the name of the table in which the data structure is going to be stored
bool create_table(char* database_name, char* table_name);

/// @brief delete the dedicated folder that is acting a place for a specific data structure
/// @param database_name the name of the database in which we are going to create the table in
/// @param table_name the name of the target table
void delete_table(char* database_name, char* table_name);

/// @brief insert a record into the table
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table in which we will insert
/// @param p any struct that we are going to put inside that database
void create(char* database_name, char* table_name, void* new_data);

/// @brief read a record with specific key from the table (file with a specific name)
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will remove the record
/// @param record_id the id of the specific data of interest
/// @param data the uncasted data variable in which data is going be put into
void read(char* database_name, char* table_name, int record_id, void* data);

/// @brief update a record with a specific key from the table (rewrite the file with a specific name)
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table in which the record resides
/// @param record_id the id of the specific record of interest
/// @param data the new data we are going to add inside the variable
void update(char* database_name, char* table_name, int record_id, void* new_data);

/// @brief delete a record with specific key from the table (remove the file with a specific name)
/// @param database_name the name of the database in which the table resides
/// @param table_name the name of the table from which we will remove the record
/// @param record_id the id of the specific data we are going to delete
void delete(char* database_name, char* table_name, int record_id);



#endif //SIMS_DATABASE_H

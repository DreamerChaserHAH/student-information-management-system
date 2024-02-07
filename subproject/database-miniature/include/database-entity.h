#ifndef DATABASE_SYSTEM_SAMPLE_DATABASE_ENTITY_H
#define DATABASE_SYSTEM_SAMPLE_DATABASE_ENTITY_H

#include <database-common.h>

/// @brief a particular entity that can be put inside the custom-made database (used to create and retrieve data)
struct DatabaseEntity{
    int data_type; /// the type of the data we are dealing with
    char* data_name; /// the name of the entity we are dealing with
    char** columns; /// pointer containing pointers to the name of each individual columns
    size_t num_of_columns; /// the amount of columns this entity has
};

/// @brief a particular record entity that can be put inside each individual .txt file to store data for the custom-made database (used to create and retrieve data)
struct RecordEntity{
    int data_type; /// the type of the data we are dealing with
    char** data; /// the content that is going to be inside the record.
    size_t num_of_columns; /// the amount of columns this entity has
};

/// @brief create an entity object to be put into database
/// @param data_type the unique type identifier that determines what data we are dealing with
/// @param data_name the name of the table we are dealing with
/// @param new_columns the list of columns that are available for this particular data type
/// @param num_of_columns the number fo columsnthat are in
struct DatabaseEntity* create_database_entity(int data_type, char* data_name, char** new_columns, size_t num_of_columns);

/// @brief convert an existing entity to string format
/// @param entity the DatabaseEntity of interest
/// @return return the string format of the entity
char* database_entity_to_string_format(struct DatabaseEntity* entity);

/// @brief create record entity to be put inside tables as values
/// @param data_type the type of the data we are dealing with
/// @param new data that is going to be put inside the document for storing
/// @param num_of_columns the number of columns inside that entity
/// @return RecordEntity object
struct RecordEntity* create_record_entity(int data_type, char** new_data, size_t num_of_columns);

/// @brief convert record entity object to string format
/// @param entity the record entity object of interest
/// @return formatted string
char* record_entity_to_string_format(struct RecordEntity* entity);

/// @brief convert array object to record entity object
/// @param data_array the string array that contains every possible value extracted from the record
/// @param entity the pointer to record entity object to which we are going to pass the data to
void raw_to_record_entity_format(int data_type, char* data_array[], int number_of_columns, struct RecordEntity* entity);

#endif //DATABASE_SYSTEM_SAMPLE_DATABASE_ENTITY_H

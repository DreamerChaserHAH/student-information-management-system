//
// Created by User on 02/02/2024.
//

#ifndef SIMS_DATAMANAGER_H
#define SIMS_DATAMANAGER_H

#include "common.h"
#include "csv-processor-api.h"

/// @brief a list of roles available inside the system
enum Role{
    STUDENT = 0,
    LECTURER = 1,
    PROGRAMME_LEADER = 2,
    SYSTEM_ADMIN = 3
};

/// @brief create all the necessary file
void setup_data_environment();

/// @brief delete all created files for the system
void delete_data_environment();

/// @brief the data structure of the user
struct User {
    int user_id; /**< The unique id of the person */
    char* username; /**< The username that we can use to log the user into the system*/
    char* display_name; /**< The name that every users can see */
    char* password; /**< The password to be used to log in into the system */
    enum Role role; /**< The specific role of the user */
};

struct User* create_user_object(int user_id, char* username, char* display_name, char* password, enum Role role);

/// @brief create a new user with certain roles (USED BY : SYSTEM ADMIN)
/// @param username the unique identifier that user is going to use to login into the application
/// @param display_name How the user would be greeted in the menu screen
/// @param password for authentication purposes
/// @param role the role of the certain user
/// @return return whether if user record has been created successfully or not
bool create_user_record(char* username, char* display_name, char* password, enum Role role);

/// @brief read a particular user with unique identifier (username)
/// @param username the unique identifer that user is going to use to login into the application
/// @return whether if user exists or not
bool is_user_exist(char* username);

/// @brief read a particular user with unique identifier (username)
/// @param username the unique identifier that user is going to use to login into the application
/// @return the user information will be returned
struct User* read_user_record(char* username);

/// @brief update a particular user (identified using their username)
/// @param username the unique identifier that user is going to use to login into the application
/// @param display_name How the user would be greeted in the menu screen
/// @param password for authentication purposes
/// @param role the role of the certain user
/// @return whether if user record has been updated successfully or not
bool update_user_record(char* username, char* display_name, char* password, enum Role role);

/// @brief delete a particular user (identified using their username)
/// @username the unique identifier that user is going to use to login into the application
/// @return whether if user has been deleted
bool delete_user_record(char* username);

/// @brief get the number of all the users in the file
/// @return integer length
int get_number_of_users();

/// @brief get all the users in the file
/// @param pointer to the
void get_all_users(struct User* user[]);

/// @brief data structure for StudentRecord.txt, this is a many-to-many relationship between student and course
struct StudentRecord{
    int user_id; /**< The id of the student related to this record */
    int course_id; /**< The id of the course related to this record */
    int attendance; /**< The attendance of a student in a specific course*/
    int score; /**< The score of a student in a specific course*/
};

struct StudentRecord* create_student_record_object(int user_id, int course_id, int attendance, int score);

/// @brief create a new record regarding with a student
/// @param record student record that contains all the data related to a student
/// @return whether if record has been created successfully or not
bool create_student_record(struct StudentRecord* record);

/// @brief check whether if a particular student record with designated user_id exists or not
/// @param user_id whose record is it?
/// @return whether if the particular record exist or not
bool is_student_record_exist(int user_id);

/// @brief read a student record using the given user_id
/// @param user_id the id of the user
/// @param result_record where the result will be pasted upon using pointers
/// @return the student record
struct StudentRecord** read_student_record(int user_id);

/// @brief read a student record with a specific course
/// @param user_id the id of the user
/// @param course_id the id of the course
/// @return the student record with a specific course
struct StudentRecord* read_student_record_with_specific_course(int user_id, int course_id);

/// @brief get all the courses of a particular student
/// @param user_id the id of the user
/// @return the courses that the student is taking
struct Course** get_all_student_courses(int user_id);

/// @brief get all the student records with a specific course
/// @param course_id the id of the course
/// @return the student records with a specific course
struct StudentRecord** get_all_student_records_with_specific_course(int course_id);

/// #brief update a student record with user_id
/// @param the entire record that we are going to replace
/// @return whether if the record has been adjusted successfully or not
bool update_student_record(struct StudentRecord* record);

/// @brief delete a particular student record
/// @param username delete the record with this particular user_id
/// @return whether if the record has been successfully deleted or not
bool delete_student_record(int user_id);

/// @brief get the number of all available student records
/// @return the number of all student records;
int get_number_of_student_records();

/// @brief get all available student records
struct StudentRecord* get_all_student_records();

struct Course{
    int course_id; /**< The unique id of the course */
    int programme_id; /**< The id of the programme related to this course record */
    char* course_name; /**< The name of this course */
    int lecturer_id; /**< The id of the lecturer related to this record */
};

struct Course* create_course_object(int course_id, int programme_id, char* course_name, int lecturer_id);

/// @brief check whether if a course exists or not
/// @param course_id the course of interest
/// @return whether if the course exists
bool is_course_exist(int course_id);

/// @brief create a record for a particular course
/// @param programme_id 
/// @param course_name 
/// @param lecturer_id 
/// @return whether if the course has been successfully created or not
bool create_course_record(int programme_id, char* course_name, int lecturer_id);

/// @brief read a particular course record
/// @param course_id the id of the specific course we are trying to read
/// @return the particular course of interest
struct Course* read_course_record(int course_id);

/// @brief update a particular course record
/// @param course_id the id of the specific course that I am trying to update
/// @param programme_id the id of the programme this course is related to
/// @param course_name the name of this particular course
/// @param lecturer_id the id of the lecturer
/// @return 
bool update_course_record(int course_id, int programme_id, char* course_name, int lecturer_id);

/// @brief delete a particular course record using the course iod
/// @param course_id the id of the specific course that i am trying to delete
/// @return whether if the course has been deleted successfully or not
bool delete_course_record(int course_id);

/// @brief get the number of courses
/// @return the number of courses
int get_number_of_courses();

struct Course* get_all_course_records();

struct Programme{
    int programme_id; /**< The unique id of the programme */
    char* programme_name; /**< The name of the programme */
    int leader_id; /**< the id of the programme leader related to this record */
};

struct Programme* create_programme_object(int programme_id, char* programme_name, int leader_id);

/// @brief checks whether if the programme exists or not
/// @param programme_id programme of interest
/// @return whether if the programme is in existence or not
bool is_programme_exist(int programme_id);

/// @brief create a specific record of a programme
/// @param programme_name the name of 
/// @param leader_id the user id of the leader 
/// @return whether if the programme has been created successfully or not
bool create_programme_record(char* programme_name, int leader_id);

/// @brief read a specific programme record
/// @param programme_id a specific programme of interest
/// @return Programme that contains all the relevant information
struct Programme* read_programme_record(int programme_id);

/// @brief update the details of a specific programme
/// @param programme_id a specific programme of interest
/// @param programme_name the name of the specific programme
/// @param leader_id the id of programme leader
/// @return whether if the programme has been updated successfully or not
bool update_programme_record(int programme_id, char* programme_name, int leader_id);

/// @brief delete a specific programme from the database
/// @param programme_id a specific programme of interest
/// @return whether if the programme has been deleted successfully or not
bool delete_programme_record(int programme_id);

/// @brief get the number of programmme available
/// @return the total amount of records inside PROGRAMME.txt file
int get_number_of_programme();

/// @brief get all available programme records
/// @return array of struct Programme
struct Programme* get_all_programme_records();

#endif //SIMS_DATAMANAGER_H

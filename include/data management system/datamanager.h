//
// Created by User on 02/02/2024.
//

#ifndef SIMS_DATAMANAGER_H
#define SIMS_DATAMANAGER_H

#include "common.h"
/// @brief a list of roles available inside the system
enum Role{
    STUDENT = 0,
    LECTURER = 1,
    PROGRAMME_LEADER = 2,
    SYSTEM_ADMIN = 3
};

/// @brief the data structure of the user
struct User {
    int user_id; /**< The unique id of the person */
    char* username; /**< The username that we can use to log the user into the system*/
    char* display_name; /**< The name that every users can see */
    char* password; /**< The password to be used to log in into the system */
    enum Role role; /**< The specific role of the user */
};

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
/// @return the User variable that contain all the data inside
struct User read_user_record(char* username);

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
/// @return struct User array with dynamic size
struct User* get_all_users();

struct StudentRecord{
    int user_id; /**< The id of the student related to this record */
    int course_id; /**< The id of the course related to this record */
    int attendance; /**< The attendance of a student in a specific course*/
    int score; /**< The score of a student in a specific course*/
};

bool create_student_record(struct StudentRecord record);
struct StudentRecord read_student_record(int user_id);
bool update_student_record(char* username, char* display_name, char* password, enum Role role);
bool delete_student_record(char* username);
int get_number_of_student_records();
struct StudentRecord* get_all_student_records();

struct Course{
    int course_id; /**< The unique id of the course */
    int programme_id; /**< The id of the programme related to this course record */
    char* course_name; /**< The name of this course */
    char* lecturer_id; /**< The id of the lecturer related to this record */
};

bool create_course_record(int programme_id, char* course_name, char* lecturer_id);
struct Course read_course_record(int course_id);
bool update_course_record(int course_id);
bool delete_course_record(int course_id);
int get_number_of_courses();
struct Course* get_all_course_records();

struct Programme{
    int programme_id; /**< The unique id of the programme */
    char* programme_name; /**< The name of the programme */
    int leader_id; /**< the id of the programme leader related to this record */
};

bool create_programme_record(char* course_name, char* lecturer_id);
struct Programme read_programme_record(int course_id);
bool update_programme_record(int programme_id);
bool delete_programme_record(int programme_id);
int get_number_of_programme();
struct Programme* get_all_programme_records();

#endif //SIMS_DATAMANAGER_H

//
// Created by User on 02/02/2024.
//

#ifndef SIMS_DATAMANAGER_H
#define SIMS_DATAMANAGER_H

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
    char* displayname; /**< The name that every users can see */
    char* password; /**< The password to be used to log in into the system */
    enum Role role; /**< The specific role of the user */
};

struct StudentRecord{
    int user_id; /**< The id of the student related to this record */
    int course_id; /**< The id of the course related to this record */
    int attendance; /**< The attendance of a student in a specific course*/
    int score; /**< The score of a student in a specific course*/
};

struct Course{
    int course_id; /**< The unique id of the course */
    int programme_id; /**< The id of the programme related to this course record */
    char* course_name; /**< The name of this course */
    char* lecturer_id; /**< The id of the lecturer related to this record */
};

struct Programme{
    int programme_id; /**< The unique id of the programme */
    char* programme_name; /**< The name of the programme */
    int leader_id; /**< the id of the programme leader related to this record */
};

#endif //SIMS_DATAMANAGER_H

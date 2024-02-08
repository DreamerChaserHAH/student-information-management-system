//
// Created by User on 02/02/2024.
//

#ifndef SIMS_DATAMANAGER_H
#define SIMS_DATAMANAGER_H

#include <database.h>

/// @brief a list of roles available inside the system
enum Role{
    STUDENT = 0,
    LECTURER = 1,
    PROGRAMME_LEADER = 2,
    SYSTEM_ADMIN = 3
};

char* role_to_string(enum Role role){
    switch(role){
        case STUDENT:
        {
            return "0";
        }
        case LECTURER:{
            return "1";
        }
        case PROGRAMME_LEADER:{
            return "2";
        }
        case SYSTEM_ADMIN:{
            return "3";
        }
    }
}

///@brief a list of all types of data to be created
enum DataType{
    USER,
    STUDENT_RECORD,
    COURSE,
    PROGRAMME
};


/// @brief the data structure of the user
struct User {
    int user_id; /**< The unique id of the person */
    char* username; /**< The username that we can use to log the user into the system*/
    char* displayname; /**< The name that every users can see */
    char* password; /**< The password to be used to log in into the system */
    enum Role role; /**< The specific role of the user */
};

/// @brief information related to a student
struct StudentRecord{
    int user_id; /**< The id of the student related to this record */
    int course_id; /**< The id of the course related to this record */
    int attendance; /**< The attendance of a student in a specific course*/
    int score; /**< The score of a student in a specific course*/
};

/// @brief information related to a course
struct Course{
    int course_id; /**< The unique id of the course */
    int programme_id; /**< The id of the programme related to this course record */
    char* course_name; /**< The name of this course */
    int user_id; /**< The id of the lecturer related to this record */
};

/// @brief information related to a programme
struct Programme{
    int programme_id; /**< The unique id of the programme */
    char* programme_name; /**< The name of the programme */
    int leader_id; /**< the id of the programme leader related to this record */
};

/// @brief union data type that encompasses all possible data struct we are going to deal with
struct Data {
    int datatype;
    union {
        struct User user;
        struct StudentRecord student_record;
        struct Course course;
        struct Programme programme;
    } payload;
};

/// @brief create data struct to be used
/// @param type the type of the data we are going to create
struct Data create_data(enum DataType type){
    struct Data data;
    switch(type){
        case USER:
        {
            data.datatype = 1;
            break;
        }
        case STUDENT_RECORD:{
            data.datatype = 2;
            break;
        }
        case COURSE : {
            data.datatype = 3;
            break;
        }
        case PROGRAMME: {
            data.datatype = 4;
            break;
        }
    }
    return data;
}

struct Data create_user_data(struct User user){
    struct Data user_data = create_data(USER);
    user_data.payload.user = user;
    return user_data;
}

struct Data create_student_record_data(struct StudentRecord student_record){
    struct Data student_record_data = create_data(STUDENT_RECORD);
    student_record_data.payload.student_record = student_record;
    return student_record_data;
}
struct Data create_course_data(struct Course course){
    struct Data course_data = create_data(COURSE);
    course_data.payload.course = course;
    return course_data;
}
struct Data create_programme_data(struct Programme programme){
    struct Data programme_data = create_data(PROGRAMME);
    programme_data.payload.programme = programme;
    return programme_data;
}
/// @brief generate metadata to be used with the custom-database system
/// @param data the Data struct that encompasses all other usable data types
/// @return DatabaseEntity object that can be put inside the database
struct DatabaseEntity* process_data(struct Data data){
    switch(data.datatype) {
        case 1: {
            char *user_columns[] = {"user_id", "username", "displayname", "password", "role"};
            return create_database_entity(1, "User", user_columns, 5);
        }
        case 2: {
            char *student_record_columns[] = {"user_id", "course_id", "attendance", "score"};
            return create_database_entity(2, "StudentRecord", student_record_columns, 4);
        }
        case 3: {
            char *course_columns[] = {"course_id", "programme_id", "course_name", "lecturer_id"};
            return create_database_entity(3, "Course", course_columns, 4);
        }
        case 4 : {
            char *programme_columns[] = {"programme_id", "programme_name", "leader_id"};
            return create_database_entity(4, "Programme", programme_columns, 3);
        }
    }
}

struct RecordEntity* process_record(struct Data data){
    switch(data.datatype){
        case 1 : {
            struct User user_value = data.payload.user;
            char* user_id = malloc(10 & sizeof(char));
            sprintf(user_id, "%d", user_value.user_id);
            char *user_columns[] = {user_id, user_value.username, user_value.displayname, user_value.password, role_to_string(user_value.role)};
            return create_record_entity(1, user_columns, 5);
        }
        case 2 : {
            struct StudentRecord studentrecord_value = data.payload.student_record;
            char* user_id;
            char* course_id;
            char* attendance;
            char* score;

            sprintf(user_id, "%d", studentrecord_value.user_id);
            sprintf(course_id, "%d", studentrecord_value.course_id);
            sprintf(attendance, "%d", studentrecord_value.attendance);
            sprintf(score, "%d", studentrecord_value.score);

            char *studentrecord_columns[] = {user_id, course_id, attendance, score};
            return create_record_entity(2, studentrecord_columns, 4);
        }
        case 3 : {
            struct Course course_value = data.payload.course;

            char* course_id;
            char* programme_id;
            char* user_id;

            sprintf(course_id, "%d", course_value.course_id);
            sprintf(programme_id, "%d", course_value.programme_id);
            sprintf(user_id, "%d", course_value.user_id);

            char* course_columns[] = {course_id, programme_id, course_value.course_name, user_id};
            return create_record_entity(3, course_columns, 4);
        }
        case 4 : {
            struct Programme programme_value = data.payload.programme;

            char* programme_id;
            char* programme_leader_id;

            sprintf(programme_id, "%d", programme_value.programme_id);
            sprintf(programme_leader_id, "%d", programme_value.leader_id);

            char* programme_columns[] = {programme_id, programme_value.programme_name, programme_leader_id};
            return create_record_entity(4, programme_columns, 3);
        }
    }
}
#endif //SIMS_DATAMANAGER_H

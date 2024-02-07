/// Author : Htet Aung Hlaing
/// <summary>
/// The file is to generally test the functionalities of database being combined with other systems
/// </summary>

#include <datamanager.h>

int main(){
    setup_database_environment();
    create_database("hello");

    struct User user;
    user.user_id = 1;
    user.role = STUDENT;
    user.displayname = "Gojo";
    user.password = "12345678";
    user.username = "asdasds";

    //struct DatabaseEntity* entity = process_data(create_user_data(user));
    struct RecordEntity* record_entity = process_record(create_user_data(user));

    //create_table("hello", "User", *entity);
    //create_record("hello", "User", *record_entity);

    struct RecordEntity* result = malloc(sizeof(struct RecordEntity));
    read_record("hello", "User", "username", "asdasds", result);
    if(result == NULL){
        printf("no value found");
    }else {
        printf("%s", result->data[1]);
    }
    return 0;
}

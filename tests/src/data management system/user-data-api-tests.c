#include <data management system/datamanager.h>
#include <assert.h>

#define INTERNAL_TESTING

void test_create_user(){
    setup_data_environment();
    assert(create_user_record("Jack", "Jackson", "12345678", STUDENT));
    assert(!create_user_record("Jack", "Jackson", "12345678", STUDENT));
    delete_data_environment();
}

void test_read_user(){
    setup_data_environment();
    assert(create_user_record("Jack", "Jackson", "12345678", STUDENT));
    struct User* user = read_user_record("Jack");

    assert(user != NULL);
    assert(strcmp(user->username, "Jack") == 0);
    assert(strcmp(user->display_name, "Jackson") == 0);
    assert(strcmp(user->password, "12345678") == 0);
    assert(user->role == STUDENT);

    delete_data_environment();
}

void test_update_user(){
    setup_data_environment();

    assert(create_user_record("Jack", "Jackson", "12345678", STUDENT));
    struct User* user = read_user_record("Jack");

    assert(user != NULL);
    assert(strcmp(user->username, "Jack") == 0);
    assert(strcmp(user->display_name, "Jackson") == 0);
    assert(strcmp(user->password, "12345678") == 0);
    assert(user->role == STUDENT);

    assert(update_user_record("Jack", "LucidDream", "2321314", LECTURER));
    /*user = read_user_record("Jack");

    assert(user != NULL);
    assert(strcmp(user->username, "Jack") == 0);
    assert(strcmp(user->display_name, "LucidDream") == 0);
    assert(strcmp(user->password, "2321314") == 0);
    assert(user->role == LECTURER);*/

    delete_data_environment();
}

void test_delete_user_record(){
    setup_data_environment();

    assert(create_user_record("Jack", "Jackson", "12345678", STUDENT));
    assert(is_user_exist("Jack"));
    assert(delete_user_record("Jack"));
    assert(!is_user_exist("Jack"));

    delete_data_environment();
}

int main(){
    test_create_user();
    test_read_user();
    test_update_user();
    test_delete_user_record();
    return 0;
}
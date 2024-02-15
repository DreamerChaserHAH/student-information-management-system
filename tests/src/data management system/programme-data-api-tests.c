#include <data management system/datamanager.h>
#include <assert.h>

#define INTERNAL_TESTING

void test_create_programme_record(){
    setup_data_environment();
    struct Programme* record = malloc(sizeof(struct Programme));
    record->programme_id = 1;
    record->programme_name = "Artificial Intellgence";
    record->leader_id = 1;
    assert(create_programme_record(record->programme_name, record->leader_id));
    delete_data_environment();
}

void test_read_programme_record(){
    setup_data_environment();
    struct Programme* record = malloc(sizeof(struct Programme));
    record->programme_id = 1;
    record->programme_name = "Artificial Intellgence";
    record->leader_id = 1;
    assert(create_programme_record(record->programme_name, record->leader_id));

    struct Programme* read_record = read_programme_record(1);
    assert(read_record != NULL);
    assert(read_record->programme_id == 1);
    assert(read_record->leader_id == 1);

    delete_data_environment();
}

void test_update_programme_record(){
    setup_data_environment();
    struct Programme* record = malloc(sizeof(struct Programme));
    record->programme_id = 1;
    record->programme_name = "Artificial Intelligence";
    record->leader_id = 1;
    assert(create_programme_record(record->programme_name, record->leader_id));

    struct Programme* read_record = read_programme_record(1);
    assert(read_record != NULL);
    assert(read_record->programme_id == 1);
    assert(strcmp(read_record->programme_name, "Artificial Intelligence") == 0);
    assert(read_record->leader_id == 1);

    record->programme_name = "Not this course";
    update_programme_record(1, record->programme_name, 2);
    read_record = read_programme_record(1);
    assert(read_record->programme_id == 1);
    assert(strcmp(read_record->programme_name, "Not this course") == 0);
    assert(read_record->leader_id == 2);

    delete_data_environment();
}

void test_delete_programme_record(){
    setup_data_environment();

    struct Programme* record = malloc(sizeof(struct Programme));
    record->programme_id = 1;
    record->programme_name = "Artificial Intelligence";
    record->leader_id = 1;
    assert(create_programme_record(record->programme_name, record->leader_id));
    assert(is_programme_exist(1));
    assert(delete_programme_record(1));
    assert(!is_programme_exist(1));

    delete_data_environment();
}

int main(){

    test_create_programme_record();
    test_read_programme_record();
    test_update_programme_record();
    test_delete_programme_record();

    return 0;
}
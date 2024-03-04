#include <data management system/datamanager.h>
#include <assert.h>

#define INTERNAL_TESTING

void test_create_student_record(){
    setup_data_environment();
    struct StudentRecord* record = create_student_record_object(1, 1, 10, 100);
    assert(create_student_record(record));
    assert(!create_student_record(record));
    delete_data_environment();
}

void test_read_student_record(){
    setup_data_environment();

    struct StudentRecord* record = create_student_record_object(1,1,5,50);

    assert(create_student_record(record));
    struct StudentRecord* read_record = read_student_record(1);

    assert(read_record != NULL);
    assert(read_record->user_id == 1);
    assert(read_record->course_id == 1);
    assert(read_record->attendance == 5);
    assert(read_record->score == 50);

    delete_data_environment();
}

void test_update_student_record(){
    setup_data_environment();

    struct StudentRecord* record = create_student_record_object(1,1,5,50);
    record->user_id = 1;
    record->course_id = 1;
    record->attendance = 5;
    record->score = 50;

    assert(create_student_record(record));
    struct StudentRecord* read_record = read_student_record(1);

    assert(read_record != NULL);
    assert(read_record->user_id == 1);
    assert(read_record->course_id == 1);
    assert(read_record->attendance == 5);
    assert(read_record->score == 50);

    record->course_id = 2;
    record->attendance = 10;
    record->score = 100;
    free(read_record);

    assert(update_student_record(record));
    read_record = read_student_record(record->user_id);

    assert(read_record != NULL);
    assert(read_record->course_id == 2);
    assert(read_record->attendance == 10);
    assert(read_record->score == 100);

    delete_data_environment();
}

void test_delete_student_record(){
    setup_data_environment();

    struct StudentRecord* record = create_student_record_object(1,1,5,50);
    record->user_id = 1;
    record->course_id = 1;
    record->attendance = 5;
    record->score = 50;

    assert(create_student_record(record));
    assert(is_student_record_exist(1));
    assert(delete_student_record(1));
    assert(!is_student_record_exist(1));

    delete_data_environment();
}

int main(){

    test_create_student_record();
    test_read_student_record();
    test_update_student_record();
    test_delete_student_record();

    return 0;
}
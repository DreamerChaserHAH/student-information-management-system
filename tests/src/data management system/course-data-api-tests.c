#include <data management system/datamanager.h>
#include <assert.h>

#define INTERNAL_TESTING

void test_create_course(){
    setup_data_environment();
    assert(create_course_record( 1, "Introduction to AI", 1));
    delete_data_environment();
}

void test_read_course(){
    setup_data_environment();
    assert(create_course_record(1 , "Introduction to AI", 1));
    struct Course* course = read_course_record(1);

    assert(course != NULL);
    assert(course->course_id == 1);
    assert(course->programme_id == 1);
    assert(strcmp(course->course_name, "Introduction to AI") == 0);
    assert(course->lecturer_id == 1);

    delete_data_environment();
}

void test_update_course(){
    setup_data_environment();

    assert(create_course_record( 1, "Introduction to AI", 1));
    struct Course* course = read_course_record(1);

    assert(course != NULL);
    assert(course->course_id == 1);
    assert(course->programme_id == 1);
    assert(strcmp(course->course_name, "Introduction to AI") == 0);
    assert(course->lecturer_id == 1);

    assert(update_course_record(1, 2, "Lucid Dreams", 3));
    struct Course* new_course = read_course_record(1);

    assert(new_course != NULL);
    assert(new_course->course_id ==  1);
    assert(strcmp(new_course->course_name, "Lucid Dreams") == 0);
    assert(new_course->programme_id == 2);
    assert(new_course->lecturer_id == 3);

    delete_data_environment();
}

void test_delete_course(){
    setup_data_environment();

    assert(create_course_record(1, "Introduction to AI", 1));
    assert(is_course_exist(1));
    assert(delete_course_record(1));
    assert(!is_course_exist(1));

    delete_data_environment();
}

int main(){
    test_create_course();
    test_read_course();
    test_update_course();
    test_delete_course();
    return 0;
}
#include <data management system/csv-processor-api.h>
#include <assert.h>
#include <stdio.h>

void test_number_of_records(char* test_file, char* test_content){
    assert(!is_file_here(test_file) && "File should not exist");
    create_file(test_file);

    assert(is_file_here(test_file) && "File should exist");
    append_file(test_file,test_content);

    assert(get_number_of_records(test_file) == 2);

    delete_file(test_file);
    assert(!is_file_here(test_file) && "File should be deleted");
}

void test_get_all_records(char* test_file, char* test_content){
    assert(!is_file_here(test_file) && "File should not exist");
    create_file(test_file);

    assert(is_file_here(test_file) && "File should exist");
    append_file(test_file,test_content);

    char** content = calloc(get_number_of_records(test_file), sizeof(char*));
    get_all_available_records(test_file, content);
    assert(strcmp(content[0], "Hello") == 0);
    assert(strcmp(content[1], "World") == 0);

    delete_file(test_file);
    assert(!is_file_here(test_file) && "File should be deleted");
}

void test_number_of_columns(){
    assert(get_number_of_columns("Hello,World") == 2);
}

void test_get_all_columns(){
    char** content = calloc(get_number_of_columns("Hello, World"), sizeof(char*));
    get_all_available_columns("Hello, World", content);
    assert(strcmp(content[0], "Hello") == 0);
    assert(strcmp(content[1], " World") == 0);
}

void test_create_record(){

    assert(!is_file_here("create_record.txt") && "File should not exist");
    create_file("create_record.txt");

    char* strings[] = {"Hi", "Hello", "Bonjour"};
    assert(create_record("create_record.txt", 3, strings) == 0);

    delete_file("create_record.txt");
}

void test_read_record(){
    assert(!is_file_here("create_record.txt") && "File should not exist");
    create_file("read_record.txt");

    char* strings[] = {"Hi", "Hello", "Bonjour"};
    assert(create_record("read_record.txt", 3, strings) == 0);

    char** elements = calloc(3, sizeof(char*));
    read_record("read_record.txt", 0, "Hi", elements, 0);
    //printf("%s Value is", elements[0]);
    assert(strcmp(elements[0], "Hi") == 0);
    assert(strcmp(elements[1], "Hello") == 0);
    assert(strcmp(elements[2], "Bonjour") == 0);

    delete_file("read_record.txt");
}

void test_update_record(){
    assert(!is_file_here("update_record.txt") && "File should not exist");
    create_file("update_record.txt");

    char* strings[] = {"Hi", "Hello", "Bonjour"};
    assert(create_record("update_record.txt", 3, strings) == 0);
    char* strings2[] = {"Jesus", "Jackma", "Hiii"};
    assert(create_record("update_record.txt", 3, strings2) == 0);

    char** elements = calloc(3, sizeof(char*));
    read_record("update_record.txt", 0, "Jesus", elements, 0);
    printf("%s Value is", elements[0]);
    if(elements[0] != NULL) {
        assert(strcmp(elements[0], "Jesus") == 0);
        assert(strcmp(elements[1], "Jackma") == 0);
        assert(strcmp(elements[2], "Hiii") == 0);
    }

    assert(update_record("update_record.txt", 0, "Jesus", strings) == 0);

    read_record("update_record.txt", 0, "Jesus", elements, 0);
    //printf("%s Value is", elements[0]);
    assert(strcmp(elements[0], "Jesus") == 0);

    delete_file("update_record.txt");
}

void test_delete_record(){
    assert(!is_file_here("delete_record.txt") && "File should not exist");
    create_file("delete_record.txt");

    char* strings[] = {"Hi", "Hello", "Bonjour"};
    assert(create_record("delete_record.txt", 3, strings) == 0);
    char* strings2[] = {"Jesus", "Jackma", "Hiii"};
    assert(create_record("delete_record.txt", 3, strings2) == 0);

    char** elements = calloc(3, sizeof(char*));
    read_record("delete_record.txt", 0, "Jesus", elements, 0);
    //printf("%s Value is", elements[0]);
    if(elements[0] != NULL) {
        assert(strcmp(elements[0], "Jesus") == 0);
        assert(strcmp(elements[1], "Jackma") == 0);
        assert(strcmp(elements[2], "Hiii") == 0);
    }

    delete_record("delete_record.txt", 0, "Jesus");
    assert(get_number_of_records("delete_record.txt") == 1);

    delete_file("delete_record.txt");
}

void test_record_exist(){
    assert(!is_file_here("record_exist.txt") && "File should not exist");
    create_file("record_exist.txt");

    assert(!is_record_exist("record_exist.txt", 0, "Hi", 3));

    char* strings[] = {"Hi", "Hello", "Bonjour"};
    assert(create_record("record_exist.txt", 3, strings) == 0);


    delete_file("record_exist.txt");
}

void test_get_all_records2(){
    create_file("record_exist.txt");

    char* strings[] = {"Hi", "Hello", "Bonjour"};
    assert(create_record("record_exist.txt", 3, strings) == 0);
    char* strings2[] = {"Hi", "GG", "Bonjour"};
    assert(create_record("record_exist.txt", 3, strings2) == 0);
    char* strings3[] = {"Hii", "GG", "Bonjour"};
    assert(create_record("record_exist.txt", 3, strings3) == 0);
    assert(create_record("record_exist.txt", 3, strings2) == 0);
    int* record_indexes = get_all_records_with_criteria("record_exist.txt", 0, "Hi");
    printf("Hiii %d \n", record_indexes[0]);
    assert(record_indexes[3] == -1);
    //assert(record_indexes[1] == 1);
    //assert(record_count == 2);
    delete_file("record_exist.txt");
}

int main(){

    delete_file("record_exist.txt");
    test_number_of_records("test_number_of_records.txt", "Hello\nWorld");
    test_number_of_columns();
    test_get_all_records("test_all_record.txt", "Hello\nWorld\nYooo");
    test_get_all_columns();
    test_create_record();
    test_read_record();
    test_update_record();
    test_delete_record();
    test_record_exist();
    test_get_all_records2();

    return 0;
}
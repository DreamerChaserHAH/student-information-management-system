#include <data management system/datamanager-utilities.h>
#include <assert.h>

void test_number_of_splittable_value(){
    assert(2 == get_number_of_splittable_value("Hello,Jackson", ","));
    assert(2 == get_number_of_splittable_value("Hello\nJackson", "\n"));
}

void test_splittable_values(){

    char* content = "Hello,Jackson Wu,Yes";
    int length = get_number_of_splittable_value(content, ",");
    char** content_array = calloc(length, sizeof(char*));

    get_splitted_values_in_array(content, length, ",", content_array);
    assert(strcmp(content_array[0], "Hello") == 0);
    assert(strcmp(content_array[1], "Jackson Wu") == 0);
    assert(strcmp(content_array[2], "Yes") == 0);
}

int main(){
    test_number_of_splittable_value();
    test_splittable_values();
    return 0;
}
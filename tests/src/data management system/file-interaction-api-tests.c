#include <data management system/file-interaction-api.h>
#include <assert.h>

void test_file_existence(){
    assert(!is_file_here("test_file_existence.txt") && "File should not exist");
    create_file("test_file_existence.txt");
    assert(is_file_here("test_file_existence.txt") && "File should exist now!");
    delete_file("test_file_existence.txt");
    assert(!is_file_here("test_file_existence.txt") && "File should be deleted");
}

void test_file_content(char* test_file, char* test_content, char* test_content2){

    assert(!is_file_here(test_file) && "File should not exist");
    create_file(test_file);

    assert(is_file_here(test_file) && "File should exist");
    append_file(test_file,test_content);

    char* content_inside = read_file(test_file);
    assert(strcmp(content_inside, test_content) == 0);

    write_file(test_file, test_content2);
    content_inside = read_file(test_file);
    assert(strcmp(content_inside, test_content2) == 0);

    char* new_content = malloc(50 * sizeof(char));
    sprintf(new_content, "%s\n%s", test_content, test_content2);
    write_file(test_file, new_content);
    content_inside = read_file(test_file);

    assert(strcmp(content_inside, new_content) == 0);

    delete_file(test_file);
    assert(!is_file_here(test_file) && "File should be deleted");
}

void test_line_content(char* test_file, char* test_content, char* test_content2){

    assert(!is_file_here(test_file) && "File should not exist");
    create_file(test_file);

    assert(is_file_here(test_file) && "File should exist");
    append_file(test_file,test_content);
    append_file(test_file, test_content2);

    char* content_inside = read_line(test_file, 2);
    assert(strcmp(content_inside, test_content2) == 0);

    edit_line(test_file, 2, "Haha");
    content_inside = read_line(test_file, 2);
    assert(strcmp(content_inside, "Haha") == 0);

    delete_line(test_file, 2);
    content_inside = read_line(test_file, 2);
    printf("%s", content_inside);
    assert(strcmp(content_inside, "") == 0);

    delete_file(test_file);
    assert(!is_file_here(test_file) && "File should be deleted");
}

int main(){
    test_file_existence();
    test_file_content("test_file_content.txt", "Hello World!", "Another Content");
    test_line_content("test_line_content.txt", "TestLine1", "TestLine2");
    return 0;
}
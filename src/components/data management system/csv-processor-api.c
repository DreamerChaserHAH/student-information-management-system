#include <data management system/csv-processor-api.h>

int get_number_of_records(char* file_path){
    return get_number_of_lines(file_path);
}

void get_all_available_records(char* file_path, char **records){
    char* content = read_file(file_path);
    return get_splitted_values_in_array(content, get_number_of_records(content), "\n", records);
}

int get_number_of_columns(char* record_string){
    return get_number_of_splittable_value(record_string, ",");
}

void get_all_available_columns(char* record_string, char* data[]){
    return get_splitted_values_in_array(record_string, get_number_of_columns(record_string), ",", data);
}

int create_record(char* file_path, int array_length, char** content_array){
    char* content_array_in_string = array_to_string(content_array, array_length);
    return append_file(file_path, content_array_in_string);
}

void read_record(char* file_path, int criteria_index, char* criteria_value, char** content_array){
    int number_of_record = get_number_of_records(file_path);
    char** list_of_records = calloc(number_of_record, sizeof(char*));
    get_all_available_records(file_path, list_of_records);

    for(int i = 0; i < number_of_record; i++){
        int number_of_columns = get_number_of_columns(list_of_records[i]);
        char** list_of_columns = calloc(number_of_columns, sizeof(char*));
        get_all_available_columns(list_of_records[i], list_of_columns);

        if(criteria_index < number_of_columns && criteria_index >= 0){
            if(strcmp(list_of_columns[criteria_index], criteria_value) == 0){
                copy_array_string(list_of_columns, content_array, number_of_columns);
            }
        }
    }
}

int update_record(char* file_path, int criteria_index, char* criteria_value, char** content_array){
    int number_of_record = get_number_of_records(file_path);
    char** list_of_records = calloc(number_of_record, sizeof(char*));
    get_all_available_records(file_path, list_of_records);

    for(int i = 0; i < number_of_record; i++){
        int number_of_columns = get_number_of_columns(list_of_records[i]);
        char** list_of_columns = calloc(number_of_columns, sizeof(char*));
        get_all_available_columns(list_of_records[i], list_of_columns);

        if(criteria_index < number_of_columns && criteria_index >= 0){
            if(strcmp(list_of_columns[criteria_index], criteria_value) == 0){
                printf("Trying to update the value at %d && %s @ line number %d", criteria_index, list_of_columns[criteria_index], i + 1);
                return edit_line(file_path, i + 1, array_to_string(content_array, number_of_columns));
            }
        }
    }
    return 1;
}

int delete_record(char* file_path, int criteria_index, char* criteria_value){
    int number_of_record = get_number_of_records(file_path);
    char** list_of_records = calloc(number_of_record, sizeof(char*));
    get_all_available_records(file_path, list_of_records);

    for(int i = 0; i < number_of_record; i++){
        int number_of_columns = get_number_of_columns(list_of_records[i]);
        char** list_of_columns = calloc(number_of_columns, sizeof(char*));
        get_all_available_columns(list_of_records[i], list_of_columns);

        if(criteria_index < number_of_columns && criteria_index >= 0){
            if(strcmp(list_of_columns[criteria_index], criteria_value) == 0){
                return delete_line(file_path, i + 1);
            }
        }
    }
    return 1;
}

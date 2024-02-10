#include <data management system/datamanager-utilities.h>

int get_number_of_splittable_value(char* content, char* delimiter){

    char* local_content = calloc(strlen(content), sizeof(char));
    strcpy(local_content, content);

    int splittable_value_count = 0;

    char* token = strtok(local_content, delimiter);
    while(token != NULL){
        token = strtok(NULL, delimiter);
        splittable_value_count++;
    }

    return splittable_value_count;
}

void get_splitted_values_in_array(char* content, int array_size, char* delimiter, char** target_array){
    char* local_content = calloc(strlen(content), sizeof(char));
    strcpy(local_content, content);

    int counter = 0;
    char* token = strtok(local_content, delimiter);
    while(token != NULL){
        target_array[counter] = (char*) calloc(strlen(token), sizeof(char));
        sprintf(target_array[counter], "%s", token);
        token = strtok(NULL, delimiter);
        counter++;
    }

    //free(local_content);
}

char* array_to_string(char** content_array, int array_length){

    size_t total_length = 0;
    for(int i = 0; i < array_length; i++){
        total_length += strlen(content_array[i]);
    }

    total_length += array_length; //(array_length > 0)? array_length - 1: 0; <- previous code, was not working
    char* formatted_string = calloc(total_length, sizeof(char));

    for(int i = 0; i < array_length; i++){
        if(i == 0){
            sprintf(formatted_string, "%s", content_array[0]);
            continue;
        }

        if(content_array[i] != NULL) {
            sprintf(formatted_string, "%s,%s", formatted_string, content_array[i]);
        }
    }
    return formatted_string;
}

char* copy_array_string(char** original_array, char** destination_array, int length){
    for(int i = 0; i < length; i++){
        destination_array[i] = calloc(strlen(original_array[i]), sizeof(char));
        strcpy(destination_array[i], original_array[i]);
    }
}

char* integer_to_string(int number){
    char* integer_string = calloc(3, sizeof(char*));
    sprintf(integer_string, "%d", number);
    return integer_string;
}
#include "data management system/file-interaction-api.h"

typedef enum {
    USER,
    COURSE,
    ATTENDANCE
} FileType;

bool is_file_here(char* file_path){
    struct stat file_status;
    return stat(file_path, &file_status) == 0;
}

long get_file_size(char* file_path){
    FILE* file_pointer;
    file_pointer = fopen(file_path, "r");

    if(file_pointer == NULL){
        return 0;
    }
    fseek (file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);
    fclose(file_pointer);
    return file_size;
}

int create_file(char* file_path){
    FILE *file_pointer = fopen(file_path, "w");
    fprintf(file_pointer, "");
    fclose(file_pointer);
    return 0;
}

int delete_file(char* file_path){
    if(is_file_here(file_path)) {
        return remove(file_path);
    }else {
        return 1;
    }
}

/// <summary>
/// There is an interesting section here in this code
/// Namely the part where the string is allocated their space
/// Instead of using malloc, calloc is nice because it init everything starting from 0
/// </summary>
char* read_file(char* file_path){
    if(is_file_here(file_path)){
        long file_size = get_file_size(file_path);

        FILE *file_pointer = fopen(file_path, "r");
        char* file_content = (char*) calloc((file_size + 1), sizeof(char));

        if(file_content == NULL){
            fclose(file_pointer);
            return "";
        }

        fread(file_content, sizeof(char), (file_size), file_pointer);
        fclose(file_pointer);
        file_content[file_size] = '\0';

        for(int i = file_size - 1; i >= 0; i--){
            if(file_content[i] == '\n'){
                file_content[i] = 0;
                break;
            }
            file_content[i] = 0;
        }
        return file_content;
    }else {
        return "";
    }
}

int write_file(char* file_path, char* content){
    FILE *file_pointer = fopen(file_path, "w");
    fprintf(file_pointer, "%s\n", content);
    fclose(file_pointer);
    return 0;
}

int append_file(char* file_path, char* content){
    if(is_file_here(file_path)){
        FILE *file_pointer = fopen(file_path, "a");
        fprintf(file_pointer, "%s\n", content);
        fclose(file_pointer);
        return 0;
    }else{
        return -1;
    }
}

///<summary>
/// Line number index start counting from 1.
/// if the token line index < line number
/// we will keep the loop going
///</summary>
char* read_line(char* file_path, int line_number){
    char* content = read_file(file_path);

    int line_number_index = 1;
    char* token = strtok(content, "\n");
    while(token != NULL && line_number_index < line_number){
        token = strtok(NULL, "\n");
        line_number_index++;
    }
    return (token != NULL)? token: "";
}

int edit_line(char* file_path, int line_number, char* new_content){

    char* content = read_file(file_path);
    create_file(file_path);

    int line_number_index = 1;
    bool has_replaced = false;

    char* token = strtok(content, "\n");
    while(token != NULL){
        if(line_number_index == line_number){
            append_file(file_path, new_content);
            has_replaced = true;
        }else {
            append_file(file_path, token);
        }
        token = strtok(NULL, "\n");
        line_number_index++;
    }

    return has_replaced? 1 : 0;
}

int delete_line(char* file_path, int line_number){
    char* content = read_file(file_path);
    create_file(file_path);

    int line_number_index = 1;
    bool has_deleted = false;

    char* token = strtok(content, "\n");
    while(token != NULL){
        if(line_number_index == line_number){
            has_deleted = true;
        }else {
            append_file(file_path, token);
        }
        token = strtok(NULL, "\n");
        line_number_index++;
    }

    return has_deleted? 1 : 0;
}

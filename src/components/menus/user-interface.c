// * Please add All the student related systems here!

#include <stdio.h>
#include <login.h>

//function(username, password)
void login_menu();

void welcome_menu() {
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("Enter your option:");
    int option;
    scanf("%d",&option);
    if(option == 1) {
        printf("LoginFunction\n");
        login_menu();
    } else if(option == 2) {
        return;
    }
}

void login_menu(){
    printf("Enter Username:");
    char username[50];
    scanf("%s", username);
    printf("Enter Password:");
    char password[50];
    scanf("%s", password);
    printf("%s %s", username, password);
}

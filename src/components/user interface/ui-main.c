#include <stdio.h>
// Interface Files
#include <user interface/ui-utils.h>
#include <user interface/ui-inputs.h>
// Include Files End
#include <systems/user-system.h>
#include <data management system/datamanager.h>
#include <student management system/student-management.h>
#include <login.h> 
#include <stdbool.h>
#include <user interface/ui-main.h>
#include <user interface/ui-strings.h>

void welcome_menu() {

    int users = get_number_of_users();

    if(users == 0) {
        box_info("Welcome to the system. Please create a user to continue.");
        add_user_option(NULL);
    }

    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "Login", login_menu);
    add_option(&menu, "Exit", exit_message);

    box_menu(&menu, "Welcome Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, NULL);
}

void login_menu() {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");

    struct User *user = login(username, password);

    if(!user) {
        printf("Invalid username or password. Please try again.\n");
        welcome_menu();
    } else {
        printf("Login successful!\n");
        main_menu(user);
    }
}

void main_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;
    int const user_role = user->role;

    if (user_role >= 0 && user_role <= 3) {
        // All Roles
        add_option(&menu, "Student Info", student_info_menu);
    }
    if (user_role >= 1 && user_role <= 3) {
        // Lecturer, System Admim and Programme Leader
        add_option(&menu, "Student Management", student_management_menu);
    }
    if (user_role >= 2 && user_role <= 3) {
        // Add options for Programme Leader and System Admin here
    }
    if (user_role == 3) {
        // Programe 
        add_option(&menu, "User Management", user_management_menu);
    }

    add_option(&menu, "Logout", logout_menu);
    box_menu(&menu, "Main Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, user);
}

void student_info_menu(struct User *user, int student_id) {
    enum Role user_role = user->role;
    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "View Student Info", view_student_info);
    add_option(&menu, "Enrolled Courses", view_student_enrolled_courses);
    add_option(&menu, "Return to Main Menu", main_menu);

    box_menu(&menu, "Student Info Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, user);
}

void user_management_menu(struct User *user) {
    struct Menu menu;
    menu.num_options = 0;

    add_option(&menu, "Add User", add_user_option);
    add_option(&menu, "Remove User", remove_user_options);
    add_option(&menu, "View All Users", view_all_user_option);
    add_option(&menu, "Return to Main Menu", main_menu);

    box_menu(&menu, "User Management Menu");

    int option = option_input("Enter your option:", &menu);
    option_handler(&menu, option, user);
}

void logout_menu(struct User *user) {
    printf("Logout successful!\n");
    user = NULL;
    welcome_menu();
}

// ! Leave this be i will handle these kind of functions - Mahmood

void add_user_option(struct User *user) {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    char *display_name = loop_input("Enter display name:", "Please enter a valid display name.");
    char *password = loop_input("Enter password:", "Please enter a valid password.");
    enum Role role = role_input("Enter role (0,1,2,3):");
    
    bool user_added = add_user(username, display_name, password, role);

    if(user == NULL) {
        printf("User added successfully!\n");
        welcome_menu();
    }

    if(user_added) {
        printf("User added successfully!\n");
        user_management_menu(user);
    } else {
        printf("User already exists!\n");
        user_management_menu(user);
    }
}

void view_all_user_option(struct User *user) {
    printf("View All Users\n");
    user_management_menu(user);
}

void remove_user_options(struct User *user) {
    char *username = loop_input("Enter username:", "Please enter a valid username.");
    if(strcmp(user->username, username) == 0) {
        printf("You cannot remove yourself!\n");
        user_management_menu(user);
    }
    bool user_removed = remove_user(username);
    if(user_removed) {
        printf("User removed successfully!\n");
    } else {
        printf("User does not exist!\n");
    }
    user_management_menu(user);
}

///@brief Student Info Options

void view_student_info(struct User *user) {
    if(user->role == 0) {
        struct StudentRecord *student_info = get_student_record(user->user_id);
        if(student_info == NULL) {
            printf("No student record found for this user.\n");
            student_info_menu(user, 0);
        } else {
            printf("Attandace: %d", student_info->attendance);
        }
    } else {
        int user_id = loop_number_input("Enter user id:", "Please enter a valid user id.");
        struct StudentRecord *student_info = get_student_record(user_id);
        if(student_info == NULL) {
            printf("No student record found for this user.\n");
            student_info_menu(user, 0);
        } else {
            printf("Attandance: %d", student_info->attendance); 
        }
    }
}

void view_student_enrolled_courses(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student Enrolled Courses\n");
    } else {
        int student_id = loop_number_input("Enter user id:", "Please enter a valid student id.");
        printf("View Student Enrolled Courses for student id: %d\n", student_id);

    }
    printf("View Student Enrolled Courses\n");	
}

void view_student_course_score(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student Course Score\n");
    } else {
        int student_id = loop_number_input("Enter student id:", "Please enter a valid student id.");
        printf("View Student Course Score for student: %d\n", student_id);
    }
}

void view_student_cgpa(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student CGPA\n");
    } else {
        int student_id = loop_number_input("Enter student id:", "Please enter a valid student id.");
        printf("View Student CGPA for student: %d\n", student_id);
    }
}

void view_student_attendance_record(struct User *user, int student_id) {
    if(user->role == 0) {
        printf("View Student Attendance Record\n");
    } else {
        int student_id = loop_number_input("Enter student id:", "Please enter a valid student id.");
        printf("View Student Attendance Record for student: %d\n", student_id);
    }
}
///@brief Student Management Options

void student_management_menu(struct User *user, int student_id) {
    printf("Student Management\n");

}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int user_id;
    char username[20];
    char password[20];
    int user_role;
} User;

User *user_list = NULL;
int total_user_number = 0;
int next_user_id = 1;

typedef struct
{
    char course_id[10];
    char course_name[100];
    int teacher_id;
    int max_number_student;
    int number_registed_student;
} Course;

Course *course_list = NULL;
int total_course_number = 0;

typedef struct
{
    int register_id;
    int user_id;
    char course_id[10];
    char status[20];
} Register;

Register *register_list = NULL;
int total_register_number = 0;
int next_register_id = 1;

User current_user;
int isLoggin = 0;

void login_menu()
{
    User user;

    printf("\t\tLogin\n");
    printf("----------------------------");
    printf("Username: ");
    scanf(" %[^\n]", user.username);

    printf("Password: ");
    scanf(" %[^\n]", user.password);

    int index = find_user_by_username(user.username);
    if (index == -1 || strcmp(user.password, user_list[index].password) != 0)
    {
        printf("Wrong username or password.Press enter to try again");
        getchar();
        system("cls");
        login_menu();
        return;
    }
    current_user = user_list[index];
    isLoggin = 1;
}

void admin_menu()
{
    int choice, flag = 1;
    printf("\t\tAdmin menu");
    printf("------------------");
    printf("1)Manage user");
    printf("2)Manage course");
    printf("3)Log out");
    printf("4)Exit program");
    printf("Pick an option: ");
    while (flag)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            admin_user_managing();
            break;
        case 2:
            admin_course_managing();
            break;
        case 3:
            logout();
            break;
        case 4:
            exit();
            break;
        default:
            break;
        }
    }
}

void teacher_menu()
{
}

void student_menu()
{
}

void initialize_admin_account()
{
    user_list = malloc(sizeof(User));
    user_list[0].user_id = 1;
    strcpy(user_list[0].username, "Admin");
    strcpy(user_list[0].password, "Admin");
    user_list[0].user_role = 1;
    total_user_number = 1;
    next_user_id = 2;
}

void free_memory()
{
}

void admin_user_managing()
{
}

void admin_course_managing()
{
}

void admin_display_account_list()
{
}

void admin_add_account()
{
}

void admin_delete_account()
{
}

void admin_add_course()
{
}

void admin_change_course()
{
}

void admin_display_course_list()
{
}

void logout()
{
}

void exit()
{
    free_memory();
    flag = 0;
    isLoggin = 0;
    current_user = (User){0, "", "", 0};
    exit(0);
}

void teacher_display_class()
{
}

void teacher_display_class_list()
{
}

void teacher_update_status()
{
}

void student_display_all_course()
{
}

void student_course_register()
{
}

void student_display_registered_course()
{
}

int find_user_by_username(char username)
{
}

void find_user_by_id()
{
}

void find_course_by_id()
{
}

void find_register()
{
}

void confirmation()
{
}

int main(int argc, char const *argv[])
{
    initialize_admin_account();
    login_menu();

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int userNumber = 0, courseNumber = 0, userID = 1;

typedef struct
{
    int role, userID;
    char *username, *password;
} User;

User *users = NULL;

typedef struct
{
    char *courseName;
    int maxNumberStudent, registeredNumberStudent, teacherID, courseID;
} Course;

Course *courses = NULL;

typedef struct
{
    char status;
    int studentID, courseID;
} Student;

Student *students = NULL;

typedef struct
{
    User user;
    int isLogin;
} CurrentUser;

CurrentUser current;

int linearUsernameSearch(char username)
{
    for (int i = 0; i < userNumber; i++)
    {
        if (username == users[i].username)
        {
            return 0;
        }
    }
    return 1;
}

int linearUserIDSearch(int id)
{
    for (int i = 0; i < userNumber; i++)
    {
        if (id == users[i].userID)
        {
            return 0;
        }
    }
    return 1;
}

int linearCourseIDSearch(int id)
{
    for (int i = 0; i < courseNumber; i++)
    {
        if (id == courses[i].courseID)
        {
            return 0;
        }
    }
    return 1;
}

void login()
{

    char username[100], password[100];

    while (1)
    {
        printf("Enter your username: ");
        scanf(" %[^\n]", username);

        printf("Enter your password: ");
        scanf(" %[^\n]", password);

        for (int i = 0; i < userNumber; i++)
        {
            if (username == users[i].username && password == users[i].password)
            {
                goto accExist;
                current = (CurrentUser){users[i], 1};
                break;
            }
        }
        printf("Invalid username or password\n");
    }
accExist:

    if (current.user.role == 1)
    {
        menuAdmin();
    }
    else if (current.user.role == 2)
    {
        menuTeacher();
    }
    else if (current.user.role == 3)
    {
        menuStudent();
    }
}

void menuAdmin()
{
    system("clear");
    int choice;
    printf("1)Account list\n2)Add account\n3)Delete account\n4)Course CRUD\n5)Logout\n6)Exit\nEnter your choice: ");
    while (1)
    {
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6)
        {
            break;
        }
        printf("Invalid choice\nRe-enter your choice: ");
    }

    if (choice == 1)
    {
        accountList();
    }
    else if (choice == 2)
    {
        addAccount();
    }
    else if (choice == 3)
    {
        deleteAccount();
    }
    else if (choice == 4)
    {
        courseCRUD();
    }
    else if (choice == 5)
    {
        current = (CurrentUser){0};
        logout();
    }
    else if (choice == 6)
    {
        exit(0);
    }
}

void accountList()
{
    system("clear");
    printf("------------------------------------------------------------\n");
    printf("|%-10s|%-30s|%-10s|%-10s|\n", "User ID", "Username", "Password", "Role");
    printf("------------------------------------------------------------");
    for (int i = 0; i < userNumber; i++)
    {
        printf("|%-10s|%-30s|%-10s|%-10s|\n", users[i].userID, users[i].username, users[i].password, users[i].role);
    }
    printf("------------------------------------------------------------\n");
}

void addAccount()
{
    char username[100], password[100];
    int role;
    system("clear");

    printf("Enter username: ");
    while (1)
    {
        scanf(" %[^\n]", username);

        if (!linearUsernameSearch(username))
        {
            break;
        }
        printf("Username already exist\nRe-enter username: ");
    }

    printf("Enter your password: ");
    while (1)
    {
        scanf(" %[^\n]", password);
        if (password != "")
        {
            break;
        }
        printf("Password cannot be empty\nRe-enter your password: ");
    }

    printf("Enter user role(1.Admin, 2.Teacher, 3.Student): ");
    while (1)
    {
        scanf("%d", &role);

        if (role >= 1 && role <= 3)
        {
            break;
        }
        printf("Invalid role\nRe-enter user role(1.Admin, 2.Teacher, 3.Student): ");
    }

    User *temp = realloc(users, (userNumber + 1) * sizeof(*users));

    if (temp != NULL)
    {
        users = temp;
        users[userNumber] = (User){role, userID + 1, username, password};
        userNumber++;
        userID++;
    }
}

void deleteAccount()
{
    int userID;
    char choice;
    int index, isTeacher = 0;
start:
    system("clear");
    printf("Enter user ID to delete: ");
    while (1)
    {
        scanf("%d", &userID);
        if (linearUserIDSearch(userID))
        {
            break;
        }

        if (userID == current.user.userID)
        {
            printf("Cannot delete yourself\n");
        }

        else if (userID == 1)
        {
            printf("Cannot delete a original admin(ID = 1)\n");
        }
        else
        {
            printf("User didnt exist\n");
        }

        printf("Re-enter user ID to delete: ");
    }

    while (1)
    {
        printf("Are you sure you want to delete this user (Y/N): ");
        scanf("%c", &choice);
        if (tolower(choice) == 'y' || tolower(choice) == 'n')
        {
            break;
        }
        printf("Invalid choice");
    }

    if (tolower(choice) == 'n')
    {
        goto start;
    }
    else if (tolower(choice) == 'y')
    {
        for (int i = 0; i < userNumber; i++)
        {
            if (userID == users[i].userID)
            {
                index = i;
                if (users[i].role == 2)
                {
                    isTeacher = 1;
                }
                break;
            }
        }

        free(users[index].username);
        free(users[index].userID);
        free(users[index].role);
        free(users[index].password);

        for (int i = index; i < userNumber - 1; i++)
        {
            users[i] = users[i + 1];
        }

        userNumber--;
        User *temp = realloc(users, userNumber * sizeof(users));

        if (temp != NULL || userNumber == 0)
        {
            users = temp;
        }

        if (isTeacher)
        {
            for (int i = 0; i < courseNumber; i++)
            {
                if (courses[i].teacherID == userID)
                {
                    courses[i].teacherID = 0;
                    break;
                }
            }
        }
    }
}

void courseCRUD()
{
    int choice;
    system("clear");
    printf("1)Add course\n2)Edit course\n3)Delete course\n4)View course list\nEnter your choice: ");
    while (1)
    {
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        printf("Invalid choice\nRe-enter your choice: ");
    }

    if (choice == 1)
    {
        addCourse();
    }
    else if (choice == 2)
    {
        editCourse();
    }
    else if (choice == 3)
    {
        deleteCourse();
    }
    else if (choice == 4)
    {
        courseList();
    }
}

void addCourse()
{
    int courseID, teacherID, maxNumberStudent;
    char courseName[100];

    printf("Enter course ID: ");
    while (1)
    {
        scanf("%d", &courseID);
        if (!linearCourseIDSearch(courseID))
        {
            break;
        }
        printf("Course ID already exist\nRe-enter course ID: ");
    }

    printf("Enter course name: ");
    while (1)
    {
        scanf(" %[^\n]", courseName);
        if (courseName != "")
        {
            break;
        }
        printf("Course name cannot be empty\nRe-enter course name: ");
    }

    printf("Enter teacher ID: ");
    while (1)
    {
        scanf("%d", &teacherID);
        for (int i = 0; i < userNumber; i++)
        {
            if (teacherID == users[i].userID && users[i].role == 2)
            {
                goto IDValidated;
                break;
            }
        }
        printf("Teacher ID dont exist\nRe-enter teacher ID: ");
    }

IDValidated:
    printf("Enter max student count: ");
    while (1)
    {
        scanf("%d", &maxNumberStudent);

        if (maxNumberStudent > 0)
        {
            break;
        }
        printf("Max student count must be positive\nRe-enter max student count: ");
    }

    Course *temp = realloc(courses, (courseNumber + 1) * sizeof(*courses));

    if (temp != NULL)
    {
        courses = temp;
        courses[courseNumber] = (Course){courseName, maxNumberStudent, 0, teacherID, courseID};
        courseNumber++;
    }
}

void editCourse()
{
    system("clear");
    int courseID, index, choice;
    printf("Enter course ID to edit: ");
    while (1)
    {
        scanf("%d", &courseID);
        if (linearCourseIDSearch(courseID))
        {
            break;
        }
        printf("Course didnt exist\nRe-enter course ID: ");
    }

    for (int i = 0; i < courseNumber; i++)
    {
        if (courseID == courses[i].courseID)
        {
            index = i;
        }
    }

    printf("------------------------------------------------------------\n");
    printf("|%-30s|%-10s|%-20s|\n", "Course name", "Teacher ID", "Maximum student count");
    printf("------------------------------------------------------------\n");
    printf("|%-30s|%-10s|%-20s|\n", courses[index].courseName, courses[index].teacherID, courses[index].maxNumberStudent);
    printf("------------------------------------------------------------\n\n");

    printf("What do you want to edit\n1)Course name\n2)Teacher ID\n3)Maximum student count\nEnter your choice: ");

    while (1)
    {
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3)
        {
            break;
        }
        printf("Invalid choice\nRe-enter your choice: ");
    }

    if (choice == 1)
    {
        char newCourseName[100];
        printf("Enter new course name: ");
        while (1)
        {
            scanf(" %[^\n]", newCourseName);

            if (newCourseName != "")
            {
                courses[index].courseName = newCourseName;
                break;
            }
            printf("Course name cannot be empty\nRe-enter course name: ");
        }
        printf("Course name change successful");
    }
    else if (choice == 2)
    {
        int newTeacherID;
        printf("Enter new teacher ID: ");
        while (1)
        {
            scanf("%d", &newTeacherID);
            for (int i = 0; i < userNumber; i++)
            {
                if (newTeacherID == users[i].userID && users[i].role == 2)
                {
                    courses[index].teacherID = newTeacherID;
                    goto IDValidated;
                    break;
                }
            }
            printf("New teacher ID dont exist\nRe-enter teacher ID: ");
        }
    IDValidated:
        printf("Teacher ID change succesful");
    }
    else if (choice == 3)
    {
        int newMaxStudent;
        printf("Enter new maximum number of student: ");
        while (1)
        {
            scanf("%d", &newMaxStudent);
            if (newMaxStudent >= courses[index].maxNumberStudent)
            {
                courses[index].maxNumberStudent = newMaxStudent;
                break;
            }
        }
        printf("Maximum student count cahnge successful");
    }
}

void deleteCourse()
{
    system("clear");
    int deleteCourseID;
    printf("Enter course ID to delete: ");
    while (1)
    {
        scanf("%d", &deleteCourseID);

        for (int i = 0; i < courseNumber; i++)
        {
            if (deleteCourseID == courses[i].courseID && courses[i].registeredNumberStudent != 0)
            {
                printf("Are you sure you want to delete this course(Y/N)");
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    users = malloc(sizeof(*users));

    users[0] = (User){1, 1, "admin", "admin"};
    userNumber++;
    userID++;

    return 0;
}

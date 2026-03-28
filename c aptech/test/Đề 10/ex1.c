#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ADMIN 1
#define TEACHER 2
#define STUDENT 3

#define LEARNING 'L'
#define COMPLETED 'C'

typedef struct
{
    int id;
    char *username;
    char *password;
    int role;
} User;

typedef struct
{
    int id;
    char *name;
    int teacherID;
    int max;
    int current;
} Course;

typedef struct
{
    int studentID;
    int courseID;
    char status;
} Enrollment;

User *users = NULL;
Course *courses = NULL;
Enrollment *enrolls = NULL;

int userCount = 0, courseCount = 0, enrollCount = 0;
int nextUserID = 1;

User current;

void clearScreen()
{
    system("clear");
}

void pauseScreen()
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;
    getchar();
}

int findUserByUsername(char *name)
{
    for (int i = 0; i < userCount; i++)
        if (strcmp(users[i].username, name) == 0)
            return i;
    return -1;
}

int findUserByID(int id)
{
    for (int i = 0; i < userCount; i++)
        if (users[i].id == id)
            return i;
    return -1;
}

int findCourseByID(int id)
{
    for (int i = 0; i < courseCount; i++)
        if (courses[i].id == id)
            return i;
    return -1;
}

int alreadyRegistered(int sid, int cid)
{
    for (int i = 0; i < enrollCount; i++)
        if (enrolls[i].studentID == sid &&
            enrolls[i].courseID == cid &&
            enrolls[i].status == LEARNING)
            return 1;
    return 0;
}

void login()
{
    char u[100], p[100];

    while (1)
    {
        clearScreen();
        printf("===== LOGIN =====\n");

        printf("Enter your username: ");
        scanf(" %[^\n]", u);

        printf("Enter your password: ");
        scanf(" %[^\n]", p);

        int i = findUserByUsername(u);

        if (i != -1 && strcmp(users[i].password, p) == 0)
        {
            current = users[i];
            printf("\nLogin successful!");
            pauseScreen();
            return;
        }

        printf("\nInvalid username or password!\nLogin again?");
        pauseScreen();
    }
}

void listAccounts()
{
    printf("----------------------------------------------------------\n");
    printf("|%-10s | %-30s | %-10s|\n", "ID", "Username", "Role");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < userCount; i++)
        printf("|%-10d | %-30s | %-10d|\n", users[i].id, users[i].username, users[i].role);
    printf("----------------------------------------------------------\n");
}

void addAccount()
{
    char u[100], p[100];
    int role;

    printf("Enter new account's username: ");
    while (1)
    {
        scanf(" %[^\n]", u);

        if (findUserByUsername(u) == -1)
        {
            break;
        }
        printf("Username exists!\nRe-enter new account's username: ");
    }

    printf("Enter new account's password: ");
    scanf(" %[^\n]", p);

    printf("Enter new account's  role (1-Admin,2-Teacher,3-Student): ");
    while (1)
    {
        scanf("%d", &role);

        if (role >= 1 && role <= 3)
        {
            break;
        }
        printf("Invalid role!\nRe-enter new account's role (1-Admin,2-Teacher,3-Student): ");
    }

    users = realloc(users, (userCount + 1) * sizeof(User));

    users[userCount++] = (User){nextUserID++, strdup(u), strdup(p), role};

    printf("Account added successfully!");
}

void deleteAccount()
{
    int id;
    printf("Enter account's ID to delete: ");
    scanf("%d", &id);

    if (id == 1 || id == current.id)
    {
        printf("Cannot delete this account!");
        return;
    }

    int i = findUserByID(id);
    if (i == -1)
    {
        printf("Account not found!");
        return;
    }

    printf("Confirm deletion (Y/N): ");
    char c;
    scanf(" %c", &c);

    if (tolower(c) != 'y')
        return;

    if (users[i].role == TEACHER)
        for (int j = 0; j < courseCount; j++)
            if (courses[j].teacherID == id)
                courses[j].teacherID = 0;

    if (users[i].role == STUDENT)
        for (int j = 0; j < enrollCount; j++)
            if (enrolls[j].studentID == id)
            {
                for (int k = j; k < enrollCount - 1; k++)
                    enrolls[k] = enrolls[k + 1];
                enrollCount--;
                j--;
            }

    free(users[i].username);
    free(users[i].password);

    for (int j = i; j < userCount - 1; j++)
        users[j] = users[j + 1];

    userCount--;
    users = realloc(users, userCount * sizeof(User));

    printf("Account deleted successfully!");
}

void sortCourses()
{
    for (int i = 0; i < courseCount - 1; i++)
        for (int j = 0; j < courseCount - i - 1; j++)
            if (courses[j].max < courses[j + 1].max)
            {
                Course t = courses[j];
                courses[j] = courses[j + 1];
                courses[j + 1] = t;
            }
}

void viewCourses()
{
    sortCourses();
    printf("----------------------------------------------------------------------------\n");
    printf("|%-10s | %-30s | %-15s | %-10s|\n", "ID", "Name", "Current/Max", "Remaining");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < courseCount; i++)
        printf("|%-10d | %-30s | %d/%-13d | %-10d|\n", courses[i].id, courses[i].name, courses[i].current, courses[i].max, courses[i].max - courses[i].current);
    printf("----------------------------------------------------------------------------\n");
}

void addCourse()
{
    int id, t, max;
    char name[100];

    printf("Enter new course's ID: ");
    while (1)
    {
        scanf("%d", &id);

        if (findCourseByID(id) == -1)
        {
            break;
        }
        printf("ID exists!\nRe-enter new course's ID: ");
    }

    printf("Enter new course's name: ");
    scanf(" %[^\n]", name);

    printf("Enter new course's teacher ID: ");
    while (1)
    {
        scanf("%d", &t);

        int idx = findUserByID(t);
        if (idx != -1 || users[idx].role == TEACHER)
        {
            break;
        }
        printf("Invalid teacher!\nRe-enter new course's teacher ID: ");
    }

    printf("Enter new course's max number of student: ");
    while (1)
    {
        scanf("%d", &max);
        if (max > 0)
        {
            break;
        }
        printf("Max number of student must be positive\nRe-enter new course's max number of student: ");
    }

    courses = realloc(courses, (courseCount + 1) * sizeof(Course));

    courses[courseCount++] = (Course){id, strdup(name), t, max, 0};

    printf("Course added successfully!");
}

void editCourse()
{
    int id;
    printf("Enter Course ID to edit: ");
    scanf("%d", &id);

    int i = findCourseByID(id);
    if (i == -1)
    {
        printf("Course not found!");
        return;
    }

    printf("\n=== CURRENT COURSE INFO ===\n");
    printf("ID: %d\n", courses[i].id);
    printf("Name: %s\n", courses[i].name);
    printf("Teacher ID: %d\n", courses[i].teacherID);
    printf("Max students: %d\n", courses[i].max);
    printf("Current students: %d\n", courses[i].current);

    int choice;
    printf("\nWhat do you want to edit?\n");
    printf("1. Course name\n");
    printf("2. Teacher ID\n");
    printf("3. Max students\n");
    printf("Enter choice: ");

    while (1)
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3)
            break;
        printf("Invalid choice\nRe-enter choice: ");
    }

    if (choice == 1)
    {
        char newName[100];
        printf("Enter new course name: ");
        scanf(" %[^\n]", newName);

        free(courses[i].name);
        courses[i].name = strdup(newName);

        printf("Course name updated successfully!");
    }

    else if (choice == 2)
    {
        int newTeacherID;

        printf("Enter new teacher ID: ");
        while (1)
        {
            scanf("%d", &newTeacherID);

            int idx = findUserByID(newTeacherID);
            if (idx != -1 && users[idx].role == TEACHER)
            {
                courses[i].teacherID = newTeacherID;
                printf("Teacher updated successfully!");
                break;
            }

            printf("Invalid teacher ID. Re-enter new teacher ID: ");
        }
    }

    else if (choice == 3)
    {
        int newMax;

        printf("Enter new max students: ");
        while (1)
        {
            scanf("%d", &newMax);

            if (newMax >= courses[i].current)
            {
                courses[i].max = newMax;
                printf("Max students updated successfully!");
                break;
            }

            printf("Must be >= current (%d). Re-enter new max students: ", courses[i].current);
        }
    }
}

void deleteCourse()
{
    int id;
    printf("Eter course's ID to delete: ");
    scanf("%d", &id);

    int i = findCourseByID(id);
    if (i == -1)
        return;

    if (courses[i].current > 0)
    {
        printf("Cannot delete this course!");
        return;
    }

    free(courses[i].name);

    for (int j = i; j < courseCount - 1; j++)
        courses[j] = courses[j + 1];

    courseCount--;
    courses = realloc(courses, courseCount * sizeof(Course));

    printf("Course deleted successfully!");
}

void registerCourse()
{
    int id;
    printf("Enter course ID: ");
    scanf("%d", &id);

    int i = findCourseByID(id);
    if (i == -1)
        return;

    if (alreadyRegistered(current.id, id))
    {
        printf("You already registered this course!");
        return;
    }

    if (courses[i].current >= courses[i].max)
    {
        printf("Course full!");
        return;
    }

    enrolls = realloc(enrolls, (enrollCount + 1) * sizeof(Enrollment));

    enrolls[enrollCount++] = (Enrollment){current.id, id, LEARNING};

    courses[i].current++;

    printf("Course registered successfully!");
}

void myCourses()
{
    printf("My Courses:\n");
    printf("--------------------------------\n");
    printf("| %-15s | %-10s |\n", "Course name", "Status");
    printf("--------------------------------\n");
    for (int i = 0; i < enrollCount; i++)
        if (enrolls[i].studentID == current.id)
        {
            int c = findCourseByID(enrolls[i].courseID);
            printf("| %-15s | %-10c |\n", courses[c].name, enrolls[i].status);
        }
    printf("--------------------------------\n");
}

void myClass()
{
    printf("-----------------------------------------------\n");
    printf("| %-10s | %-30s |\n", "ID", "Course Name");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < courseCount; i++)
        if (courses[i].teacherID == current.id)
            printf("| %-10d | %-30s |\n", courses[i].id, courses[i].name);
    printf("-----------------------------------------------\n");
}

void studentList()
{
    int id;
    printf("Course ID: ");
    scanf("%d", &id);

    printf("-----------------------------------------------\n");
    printf("| %-10s | %-30s |\n", "ID", "Username");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < enrollCount; i++)
        if (enrolls[i].courseID == id && enrolls[i].status == LEARNING)
        {
            int s = findUserByID(enrolls[i].studentID);
            printf("%d | %s\n", users[s].id, users[s].username);
        }
    printf("-----------------------------------------------\n");
}

void updateStatus()
{
    int cid, sid;
    printf("CourseID StudentID: ");
    scanf("%d %d", &cid, &sid);

    for (int i = 0; i < enrollCount; i++)
        if (enrolls[i].courseID == cid && enrolls[i].studentID == sid && enrolls[i].status == LEARNING)
            enrolls[i].status = COMPLETED;

    printf("Updated!");
}

void adminMenu()
{
    int c;
    clearScreen();
    printf("ADMIN MENU\n1.List account\n2.Add account\n3.Delete account\n4.Add course\n5.Edit course\n6.View course\n7.Del course\n8.Logout\n9.Exit\nEnter your choice: ");
    while (1)
    {
        scanf("%d", &c);

        clearScreen();
        if (c == 1)
            listAccounts();
        else if (c == 2)
            addAccount();
        else if (c == 3)
            deleteAccount();
        else if (c == 4)
            addCourse();
        else if (c == 5)
            editCourse();
        else if (c == 6)
            viewCourses();
        else if (c == 7)
            deleteCourse();
        else if (c == 8)
            return;
        else if (c == 9)
            exit(0);
        else
            printf("Invalid choice\nRe-enter choice: ");

        pauseScreen();
    }
}

void teacherMenu()
{
    int c;
    clearScreen();
    printf("TEACHER MENU\n1.My Class List\n2.Class Student List\n3.Update Status\n4.Logout\n5.Exit\nEnter your choice: ");
    while (1)
    {
        scanf("%d", &c);

        clearScreen();
        if (c == 1)
            myClass();
        else if (c == 2)
            studentList();
        else if (c == 3)
            updateStatus();
        else if (c == 4)
            return;
        else if (c == 5)
            exit(0);
        else
            printf("Invalid choice\nRe-enter choice: ");

        pauseScreen();
    }
}

void studentMenu()
{
    int c;
    clearScreen();
    printf("STUDENT MENU\n1.View Course\n2.Register Course\n3.My Course List\n4.Logout\n5.Exit\nEnter your choice");
    while (1)
    {
        scanf("%d", &c);

        clearScreen();
        if (c == 1)
            viewCourses();
        else if (c == 2)
            registerCourse();
        else if (c == 3)
            myCourses();
        else if (c == 4)
            return;
        else if (c == 5)
            exit(0);
        else
            printf("Invalid choice\nRe-enter choice: ");

        pauseScreen();
    }
}

int main(int argc, char const *argv[])
{
    users = malloc(sizeof(User));
    users[0] = (User){nextUserID++, strdup("admin"), strdup("admin"), ADMIN};
    userCount = 1;

    while (1)
    {
        login();

        if (current.role == ADMIN)
            adminMenu();
        else if (current.role == TEACHER)
            teacherMenu();
        else
            studentMenu();
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CURRENT_YEAR 2025

typedef struct
{
    char name[20];
    char country[20];
    int birthyear;
    float mark;
} Student;

void menu()
{
    printf("\t\tStudent management system\n");
    printf("1. Input students|2. Display Students|3. Save file|4. Open File|5. exit\n");
}

void input(Student *student, int *count)
{
    for (int i = 0; i < *count; i++)
    {
        printf("Enter the name of student: ");
        scanf(" %[^\n]", student[i].name);
        printf("Enter the country that student from: ");
        scanf(" %[^\n]", student[i].country);
        printf("Enter the birthyear of student: ");
        while (1)
        {
            scanf("%d", &student[i].birthyear);
            if (CURRENT_YEAR - student[i].birthyear >= 6 && CURRENT_YEAR - student[i].birthyear <= 18)
            {
                break;
            }
            printf("Student age must less than 18 years old and greater than 6 years old\n");
            printf("Re-enter the birthyear of student: ");
        }

        printf("Enter the mark of student: ");
        while (1)
        {
            scanf("%f", &student[i].mark);
            if (student[i].mark <= 10 && student[i].mark >= 0)
            {
                break;
            }
            printf("Student mark must less than 10 and greater than 0 ");
            printf("Re-enter the mark of student: ");
        }
    }
}

void display(Student student[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(student[i].name, student[j].name) > 0)
            {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Country: %s, Birthyear: %d, Mark: %f", student[i].name, student[i].country, student[i].birthyear, student[i].mark);
    }
}

void save_file(Student student[], int count)
{
    char name[20];
    FILE *f;
    printf("Enter a file name: ");
    scanf(" %[^\n]", name);

    f = fopen(name, "wb");

    if (f == NULL)
    {
        printf("Cannot open a file");
        return;
    }

    fwrite(student, sizeof(Student), count, f);

    printf("File save successfully\n");
    fclose(f);
}

void open_file()
{
    FILE *f;
    Student student;
    char name[20];
    printf("Enter the file name: ");
    scanf(" %[^\n]", name);
    f = fopen(name, "rb");

    if (f == NULL)
    {
        printf("Cannot open file");
        return;
    }

    while (fread(&student, sizeof(Student), 1, f))
    {
        printf("Name: %s, Country: %s, Birthyear: %d, Mark: %f", student.name, student.country, student.birthyear, student.mark);
    }
}

int main(int argc, char const *argv[])
{
    Student *student = NULL;
    int count, flag = 1, choice;
    menu();
    printf("Enter a choice: ");
    while (flag)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the total number of student: ");
            scanf("%d", &count);
            if (student != NULL)
            {
                free(student);
                student = NULL;
            }
            student = malloc(count * sizeof(Student));
            if (student == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }

            input(student, &count);
            break;
        case 2:
            if (student == NULL)
            {
                printf("No student found\n");
            }
            else
            {
                display(student, count);
            }

            break;
        case 3:
            if (student == NULL)
            {
                printf("No student found\n");
            }
            else
            {
                save_file(student, count);
            }
            break;
        case 4:
            open_file();
            break;
        case 5:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            printf("Re-enter a choice: ");
            break;
        }
    }
    return 0;
}

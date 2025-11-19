#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    float mark;
} Student;

void menu()
{
    printf("Menu: \n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Calculate Average Marks\n");
    printf("4. Exit\n");
}

void add(Student *std, int *count)
{
    if (*count >= 5)
    {
        printf("Student is full\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &std[*count].id);
    getchar();

    printf("Enter Student Name: ");
    scanf(" %[^\n]", std[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &std[*count].mark);
    printf("\n");

    (*count)++;
}

void display(Student std[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Name: %s, Marks: %.2f\n", std[i].id, std[i].name, std[i].mark);
    }
}

float average(Student std[], int count)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += (float)std[i].mark;
    }
    return sum / count;
}

int main(int argc, char const *argv[])
{
    Student std[5];
    int choice, count = 0, flag = 1;
    while (flag)
    {
        menu();
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(std, &count);
            break;
        case 2:
            if (count == 0)
            {
                printf("No student to display\n");
            }
            else
            {
                display(std, count);
            }
            break;
        case 3:
            if (count == 0)
            {
                printf("No student to calculate average\n");
            }
            else
            {
                printf("Average Marks: %.2f\n", average(std, count));
            }
            break;
        case 4:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

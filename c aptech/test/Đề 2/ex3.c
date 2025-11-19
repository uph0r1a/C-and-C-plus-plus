#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CURRENT_YEAR 2025

typedef struct
{
    char name[20];
    char country[20];
    int birthyear;
    float salary;
} Employee;

void menu()
{
    printf("\t\t\t\tEmployee management system\n");
    printf("1. Input  Employee|2. Display Employee Descending|3. Save file|4. Analyze |5. exit\n");
}

void input(Employee *employ, int *count)
{

    for (int i = 0; i < *count; i++)
    {
        printf("Enter the name of employee number %d: ", i + 1);
        scanf(" %[^\n]", employ[i].name);

        printf("Enter the country the employee number %d from: ", i + 1);
        scanf(" %[^\n]", employ[i].country);

        printf("Enter the birthyear of employee number %d: ", i + 1);
        while (1)
        {
            scanf("%d", &employ[i].birthyear);
            if (CURRENT_YEAR - employ[i].birthyear >= 18 && CURRENT_YEAR - employ[i].birthyear <= 60)
            {
                break;
            }
            printf("Employee age must more than 18 years old and less than 60 years old\n");
            printf("Re-enter the birthyear of employee number %d: ", i + 1);
        }

        printf("Enter the salary of employee number %d: ", i + 1);
        while (1)
        {
            scanf("%f", &employ[i].salary);
            if (employ[i].salary <= 500 && employ[i].salary >= 100)
            {
                break;
            }
            printf("Employee salary must less than 500 and greater than 100\n");
            printf("Re-enter the salary of employee number %d: ", i + 1);
        }
    }
}

void display(Employee employ[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(employ[i].name, employ[j].name) > 0)
            {
                Employee temp = employ[i];
                employ[i] = employ[j];
                employ[j] = temp;
            }
        }
    }
    printf("%-20s| %-15s| %-10s| %-10s\n", "Name", "Country", "Birthyear", "Salary");
    for (int i = 0; i < count; i++)
    {
        printf("%-20s| %-15s| %-10d| %-10.2f\n", employ[i].name, employ[i].country, employ[i].birthyear, employ[i].salary);
    }
}

void savefile(Employee employ[], int count)
{
    FILE *f;
    char name[20];
    printf("Enter a file name: ");
    scanf(" %[^\n]", name);

    f = fopen(name, "wb");

    if (f == NULL)
    {
        printf("Cannot open a file\n");
        return;
    }

    fwrite(employ, sizeof(Employee), count, f);

    printf("File saved successfully\n");
    fclose(f);
}

void analyze(Employee employ[], int count)
{
    printf("Employee count by country:\n");

    for (int i = 0; i < count; i++)
    {
        int found = 0;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(employ[i].country, employ[j].country) == 0)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int country_count = 0;
            for (int k = 0; k < count; k++)
            {
                if (strcmp(employ[i].country, employ[k].country) == 0)
                    country_count++;
            }
            printf("%s: %d\n", employ[i].country, country_count);
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice, number, flag = 1;
    Employee *employ = NULL;
    menu();

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the total number of employees: ");
            scanf("%d", &number);
            if (employ != NULL)
            {
                free(employ);
                employ = NULL;
            }
            employ = malloc(number * sizeof(Employee));

            if (employ == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }

            input(employ, &number);
            break;
        case 2:
            if (employ == NULL)
            {
                printf("No employee found\n");
            }
            else
            {
                display(employ, number);
            }

            break;
        case 3:
            if (employ == NULL)
            {
                printf("No employee found\n");
            }
            else
            {
                savefile(employ, number);
            }
            break;
        case 4:
            if (employ == NULL)
            {
                printf("No employee found\n");
            }
            else
            {
                analyze(employ, number);
            }

            break;
        case 5:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (flag);

    free(employ);
    return 0;
}
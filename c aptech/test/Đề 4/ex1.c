#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[25];
    char manufacturer[25];
    int release_year;
    float price;
} Mobile;

void menu()
{

    printf("+------------------------------------------------------------------+\n");
    printf("|\t\tMOBILE PHONE STORE MANAGEMENT PROGRAM\t\t   |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|1. Input |2. Sort |3. Analyze |4. Find |5. Save |6. Open |7. Exit |\n");
    printf("+------------------------------------------------------------------+\n");
}

void input(Mobile *mobile, int *count)
{

    for (int i = 0; i < *count; i++)
    {
        printf("Please input Mobile[%d]:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", mobile[i].name);
        printf("Manufacture: ");
        scanf(" %[^\n]", mobile[i].manufacturer);
        printf("Release Year: ");
        while (1)
        {
            scanf("%d", &mobile[i].release_year);
            while (getchar() != '\n')
                ;

            if (mobile[i].release_year >= 1999)
            {
                break;
            }
            printf("Mobile  release  year must  be greater  than or equal to 1999.\n");
            printf("Re-enter release year: ");
        }

        printf("Price: ");

        while (1)
        {
            scanf("%f", &mobile[i].price);
            while (getchar() != '\n')
                ;
            if (mobile[i].price >= 500 && mobile[i].price <= 6000)
            {
                break;
            }
            printf("Mobile price must be between 500($) and 6000($).\n");
            printf("Re-enter price: ");
        }
    }
}

void sort(Mobile mobile[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(mobile[i].name, mobile[j].name) > 0)
            {
                Mobile temp = mobile[i];
                mobile[i] = mobile[j];
                mobile[j] = temp;
            }
        }
    }
    printf("+-------------------------------------------------------+\n");
    printf("|%-20s|%-20s|%-12s|%-10s|\n", "Smartphone", "Manufacturer", "Release Year", "Price($)");
    printf("+-------------------------------------------------------+\n");
    for (int i = 0; i < count; i++)
    {
        printf("|%-20s|%-20s|%-12d|%-10.2f|\n", mobile[i].name, mobile[i].manufacturer, mobile[i].release_year, mobile[i].price);
        printf("+-------------------------------------------------------+\n");
    }
}

void analyze(Mobile mobile[], int count)
{
    printf("Statistics Result:\n");
    for (int i = 0; i < count; i++)
    {
        int found = 0;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(mobile[i].manufacturer, mobile[j].manufacturer) == 0)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int manufacturer_count = 0;
            for (int j = 0; j < count; j++)
            {
                if (strcmp(mobile[i].manufacturer, mobile[j].manufacturer) == 0)
                {
                    manufacturer_count++;
                }
            }
            printf("+ There are %d Mobile phone(s) manufactured by %s.\n", manufacturer_count, mobile[i].manufacturer);
        }
    }
}

void find(Mobile mobile[], int count)
{
    char manufacturer_find[25];
    int size = 0, capacity = 0, manufacturer_count = 0;
    float min, max;
    Mobile *suitable = NULL;
    printf("Manufacturer: ");
    scanf(" %[^\n]", manufacturer_find);
    printf("Min price($): ");
    scanf("%f", &min);
    while (getchar() != '\n')
        ;
    printf("Max price($): ");
    scanf("%f", &max);
    while (getchar() != '\n')
        ;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(manufacturer_find, mobile[i].manufacturer) == 0 && mobile[i].price >= min && mobile[i].price <= max)
        {
            if (size == capacity)
            {
                if (capacity == 0)
                {
                    capacity = 2;
                }
                else
                {
                    capacity *= 2;
                }
                Mobile *tmp = realloc(suitable, capacity * sizeof(Mobile));
                if (tmp == NULL)
                {
                    printf("Memory reallocation failed\n");
                    free(suitable);
                    return;
                }
                suitable = tmp;
            }
            suitable[size++] = mobile[i];
            manufacturer_count++;
        }
    }

    printf("Search Results: \n");
    printf("+-------------------------------------------------------+\n");
    printf("|%-20s|%-20s|%-12s|%-10s|\n", "Smartphone", "Manufacturer", "Release Year", "Price($)");
    printf("+-------------------------------------------------------+\n");
    for (int i = 0; i < size; i++)
    {
        printf("|%-20s|%-20s|%-12d|%-10.2f|\n", suitable[i].name, suitable[i].manufacturer, suitable[i].release_year, suitable[i].price);
        printf("+-------------------------------------------------------+\n");
    }
    printf("%d smartphones found.", manufacturer_count);
    free(suitable);
}

void save(Mobile mobile[], int count)
{
    FILE *f;
    char name[256];
    printf("Enter a file name: ");
    scanf(" %[^\n]", name);

    f = fopen(name, "wb");

    if (f == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    fwrite(mobile, sizeof(Mobile), count, f);

    printf("File saved successfully\n");
    fclose(f);
}

void open()
{
    FILE *f;
    Mobile temp;
    char name[256];
    printf("\tOpen file and display the list:\n");
    printf("File name: ");
    scanf(" %[^\n]", name);

    f = fopen(name, "rb");

    if (f == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    printf("+-------------------------------------------------------+\n");
    printf("|%-20s|%-20s|%-12s|%-10s|\n", "Smartphone", "Manufacturer", "Release Year", "Price($)");
    printf("+-------------------------------------------------------+\n");
    while (fread(&temp, sizeof(Mobile), 1, f))
    {
        printf("|%-20s|%-20s|%-12d|%-10.2f|\n", temp.name, temp.manufacturer, temp.release_year, temp.price);
        printf("+-------------------------------------------------------+\n");
    }
}

int main(int argc, char const *argv[])
{
    Mobile *mobile = NULL;
    int choice, flag = 1, number;
    char option;
    menu();

    do
    {
        printf("Your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            printf("Enter the total number of mobiles: ");
            scanf("%d", &number);

            mobile = malloc(number * sizeof(Mobile));

            if (mobile == NULL)
            {
                printf("Memory allocation failed");
                return 1;
            }
            input(mobile, &number);
            break;
        case 2:
            if (mobile == NULL)
            {
                printf("No mobile phone found\n");
                return 1;
            }
            else
            {
                sort(mobile, number);
            }
            break;
        case 3:
            if (mobile == NULL)
            {
                printf("No mobile phone found\n");
                return 1;
            }
            else
            {
                analyze(mobile, number);
            }
            break;
        case 4:
            if (mobile == NULL)
            {
                printf("No mobile phone found\n");
                return 1;
            }
            else
            {
                find(mobile, number);
            }
            break;
        case 5:
            if (mobile == NULL)
            {
                printf("No mobile phone found\n");
                return 1;
            }
            else
            {
                save(mobile, number);
            }
            break;
        case 6:
            if (mobile == NULL)
            {
                printf("No mobile phone found\n");
                return 1;
            }
            else
            {
                open();
            }
            break;
        case 7:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            printf("Re-enter choice: ");
            break;
        }
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
        {
            printf("Do you want to continue ?\n");
            printf("- Yes, I do. (press 'y', 'Y')\n");
            printf("- No, I don't. (press 'n', 'N')\n");
            printf("- Please clear the screen ! (press 'c', 'C')\n");
            printf("Your choice: ");
            while (flag)
            {
                scanf(" %c", &option);
                if (tolower(option) == 'y')
                {
                    menu();
                    break;
                }
                else if (tolower(option) == 'n')
                {
                    flag = 0;
                    exit(0);
                }
                else if (tolower(option) == 'c')
                {
                    system("cls");
                    menu();
                    break;
                }
                else
                {
                    printf("Invalid choice\n");
                    printf("Re-enter choice: ");
                }
            }
        }

    } while (flag);

    free(mobile);
    return 0;
}

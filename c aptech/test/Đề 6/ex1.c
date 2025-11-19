#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char phone[15];
    int age;
} Contact;

void menu()
{
    printf("1. Add Contact\n2. View All Contacts\n3. Search by Name\n4. Delete by Phone\n5. Exit\n");
}

void add(Contact *contact, int *count)
{
    int flag = 1;
    char phone_number_input[15];

    if (*count >= 10)
    {
        printf("Contact is full");
        return;
    }

    printf("Enter name: ");
    while (1)
    {
        scanf(" %[^\n]", contact[*count].name);
        if (strlen(contact[*count].name) > 0)
        {
            break;
        }
        printf("Name must not be empty\nRe-enter name: ");
    }

    printf("Enter phone number: ");
    while (flag)
    {
        scanf(" %[^\n]", phone_number_input);
        flag = 0;
        for (int i = 0; i < *count; i++)
        {
            if (strcmp(phone_number_input, contact[i].phone) == 0)
            {
                printf("Phone number must be unique\nRe-enter phone number: ");
                flag = 1;
                break;
            }
        }
    }

    strcpy(contact[*count].phone, phone_number_input);

    printf("Enter age: ");
    while (1)
    {
        scanf("%d", &contact[*count].age);
        if (contact[*count].age > 0)
        {
            break;
        }
        printf("Age must be > 0\nRe-enter age: ");
    }

    (*count)++;
}

void display(Contact contact[], int count)
{
    printf("%-20s|%-15s|%-5s\n", "Name", "Phone", "Age");
    for (int i = 0; i < count; i++)
    {
        printf("%-20s|%-15s|%-5d\n", contact[i].name, contact[i].phone, contact[i].age);
    }
}

void search(Contact contact[], int count)
{
    char name_input[50];
    int found = 0;

    printf("Enter a name: ");
    scanf(" %[^\n]", name_input);

    for (int i = 0; i < count; i++)
    {
        char *str = contact[i].name;
        int n = strlen(str);
        int m = strlen(name_input);

        for (int j = 0; j <= n - m; j++)
        {
            int match = 1;

            for (int k = 0; k < m; k++)
            {
                if (tolower((unsigned char)str[j + k]) != tolower((unsigned char)name_input[k]))
                {
                    match = 0;
                    break;
                }
            }

            if (match)
            {
                printf("Match Found: %s | %s | %d\n",
                       contact[i].name,
                       contact[i].phone,
                       contact[i].age);
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("No contacts matched your search.\n");
    }
}

void delete(Contact contact[], int *count)
{
    char phone_input[15];
    int found = 0;

    printf("Enter the phone number to delete: ");
    scanf(" %[^\n]", phone_input);

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(phone_input, contact[i].phone) == 0)
        {
            found = 1;
            for (int j = i; j < (*count) - 1; j++)
            {
                contact[j] = contact[j + 1];
            }
            printf("Contact removed\n");
            (*count)--;
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found\n");
    }
}

int main(int argc, char const *argv[])
{
    int choice, flag = 1, count = 0;
    Contact contact[10];

    while (flag)
    {
        menu();
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(contact, &count);
            break;
        case 2:
            display(contact, count);
            break;
        case 3:
            search(contact, count);
            break;
        case 4:
            delete(contact, &count);
            break;
        case 5:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        system("cls");
    }

    return 0;
}

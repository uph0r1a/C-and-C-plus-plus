#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void menu()
{
    printf("Menu:\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
}

void add(Product *product, int *count)
{
    if (*count >= 5)
    {
        printf("Products is full\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &product[*count].id);
    printf("Enter Product Name: ");
    while (1)
    {
        scanf(" %[^\n]", product[*count].name);
        if (strlen(product[*count].name) > 0)
        {
            break;
        }
        printf("Name cannot be empty\n");
        printf("Re-enter Product Name: ");
    }
    printf("Enter Quantity: ");
    while (1)
    {
        scanf("%d", &product[*count].quantity);
        if (product[*count].quantity >= 0)
        {
            break;
        }
        printf("Quantity cant be less than 0\n");
        printf("Re-enter Quantity: ");
    }
    printf("Enter Price: ");
    while (1)
    {
        scanf("%f", &product[*count].price);
        if (product[*count].price >= 0)
        {
            break;
        }
        printf("Price cant be less than 0\n");
        printf("Re-enter Price: ");
    }
    (*count)++;
}

void display(Product product[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n", product[i].id, product[i].name, product[i].quantity, product[i].price);
    }
}

void delete(Product product[], int *count)
{
    int remove_id, found = 0;
    printf("Enter the product ID to remove: ");
    scanf("%d", &remove_id);

    for (int i = 0; i < *count; i++)
    {
        if (product[i].id == remove_id)
        {
            found = 1;
            for (int j = i; j < (*count) - 1; j++)
            {
                product[j] = product[j + 1];
            }
            printf("Product removed\n");
            (*count)--;
            break;
        }
    }
    if (!found)
    {
        printf("Product not found\n");
    }
}

int main(int argc, char const *argv[])
{
    Product product[5];
    int choice, flag = 1, count = 0;
    menu();
    printf("Your choice: ");
    while (flag)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(product, &count);
            break;
        case 2:
            if (count == 0)
            {
                printf("No product\n");
            }
            else
            {
                display(product, count);
            }

            break;
        case 3:
            if (count == 0)
            {
                printf("No product\n");
            }
            else
            {
                delete(product, &count);
            }
            break;
        case 4:
            flag = 0;
            break;
        default:
            printf("Invalid option\n");
            printf("Re-enter your choice: ");
            break;
        }
    }

    return 0;
}

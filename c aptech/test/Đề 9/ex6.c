#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int id;
    float price;
} CosmeticProduct;

int main()
{

    CosmeticProduct cosmeticProduct[3];

    for (int i = 0; i < 3; i++)
    {
        cosmeticProduct[i].name = malloc(50 * sizeof(char));
        if (cosmeticProduct[i].name == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Enter name, id, and price for product %d: ", i + 1);
        scanf(" %[^\n]", cosmeticProduct[i].name);
        scanf("%d", &cosmeticProduct[i].id);
        scanf("%f", &cosmeticProduct[i].price);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (cosmeticProduct[j].price > cosmeticProduct[j + 1].price)
            {
                CosmeticProduct temp = cosmeticProduct[j];
                cosmeticProduct[j] = cosmeticProduct[j + 1];
                cosmeticProduct[j + 1] = temp;
            }
        }
    }

    printf("Sorted products by price:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Product: %s, ID: %d, Price: $%.2f\n", cosmeticProduct[i].name, cosmeticProduct[i].id, cosmeticProduct[i].price);
    }

    for (int i = 0; i < 3; i++)
    {
        free(cosmeticProduct[i].name);
    }

    return 0;
}

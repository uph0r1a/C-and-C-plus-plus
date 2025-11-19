#include <stdio.h>

int main(int argc, char const *argv[])
{
    float price[10], search;
    printf("Enter 10 product prices: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &price[i]);
    }
    printf("Enter a price to search: ");
    scanf("%f", &search);

    for (int i = 0; i < 10; i++)
    {
        if (price[i] == search)
        {
            printf("Price found at index: %d", i);
            break;
        }
    }

    return 0;
}

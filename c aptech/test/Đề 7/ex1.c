#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number_of_items;
    float price, sum = 0;

    printf("Enter the number of items purchased: ");
    scanf("%d", &number_of_items);

    for (int i = 0; i < number_of_items; i++)
    {
        printf("Enter price of item %d: ", i + 1);
        scanf("%f", &price);
        sum += price;
    }

    printf("Total cost: $%.2f", sum);

    return 0;
}

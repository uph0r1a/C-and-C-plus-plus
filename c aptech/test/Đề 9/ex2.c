#include <stdio.h>

int main(int argc, char const *argv[])
{
    float price;
    printf("Enter the price: ");
    scanf("%f", &price);
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", " ", "5%", "10%", "15%", "20%", "25%", "30%", "35%", "40%", "45%", "50%");

    for (int i = 1; i <= 10; i++)
    {
        printf("%-10d", i);
        for (int j = 1; j <= 50; j++)
        {
            if (j % 5 == 0)
            {
                printf("$%-10.2f", (float)(i * (price - price * j / 100)));
            }
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

void applyDiscount(double *price, int percentage)
{
    printf("Discounted Price: %.2f", (*price) - (*price) * ((float)percentage / 100));
}

int main(int argc, char const *argv[])
{
    double price;
    int percentage;
    printf("Enter price: ");
    scanf("%lf", &price);
    printf("Enter discount percentage: ");
    scanf("%d", &percentage);

    applyDiscount(&price, percentage);
    return 0;
}

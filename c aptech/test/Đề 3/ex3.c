#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    printf("Enter 2 intergers: ");
    scanf("%d %d", &a, &b);

    printf("Sum: ", a + b);
    printf("Difference: ", a - b);
    printf("Product: ", a * b);
    printf("Quotient: ", a / b);

    return 0;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    float price1, price2;
    char operator;

    printf("Enter first price: ");
    scanf("%f", &price1);
    printf("Enter second price: ");
    scanf("%f", &price2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        printf("Result: %.2f", price1 + price2);
        break;
    case '-':
        printf("Result: %.2f", price1 - price2);
        break;
    case '*':
        printf("Result: %.2f", price1 * price2);
        break;
    case '/':
        while (1)
        {
            if (price2 != 0)
            {
                break;
            }
            printf("Cannot divide by 0\n");
            printf("Enter second price: ");
            scanf("%f", &price2);
        }

        printf("Result: %.2f", price1 / price2);
        break;
    default:
        break;
    }
    return 0;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    float number1, number2;
    int count = 0;
    while (1)
    {
        printf("Enter the first number: ");
        scanf("%f", &number1);
        printf("Enter the second number: ");
        scanf("%f", &number2);
        if (number1 < number2)
        {
            break;
        }
        printf("the first number must be less than the second number\n");
    }

    printf("The sum of numbers between %.2f and %.2f is: %.2f\n", number1, number2, number1 + number2);

    for (int i = number1; i <= number2; i++)
    {
        if (i % 2 != 0)
        {
            count++;
        }
    }
    printf("Total count of odd numbers between %.2f and %.2f is: %d", number1, number2, count);

    return 0;
}

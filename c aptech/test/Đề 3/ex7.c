#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number, isprime = 1;
    printf("Enter a positive integer: ");
    while (1)
    {
        scanf("%d", &number);
        if (number > 0)
        {
            break;
        }
        printf("Number must be positive\n");
        printf("Re-enter a positive integer: ");
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            isprime = 0;
        }
    }

    if (isprime)
    {
        printf("The entered number is prime");
    }
    else
    {
        printf("The entered number is not prime");
    }

    return 0;
}

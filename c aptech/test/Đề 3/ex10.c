#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = 2; i <= 100; i++)
    {
        int isprime = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isprime = 0;
            }
        }
        if (isprime)
        {
            sum += i;
        }
    }
    printf("The sum of all the prime numbers between 1 and 100: %d", sum);

    return 0;
}

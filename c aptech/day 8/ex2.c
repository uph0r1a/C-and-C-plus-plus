#include <stdio.h>

void calculateSum(int a, int b)
{
    int sum = a + b;
    printf("sum = %d", sum);
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;

    calculateSum(a, b);

    return 0;
}

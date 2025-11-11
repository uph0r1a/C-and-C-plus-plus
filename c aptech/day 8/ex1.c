#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("a = %d, b = %d", *a, *b);
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;

    swap(a, b);

    return 0;
}

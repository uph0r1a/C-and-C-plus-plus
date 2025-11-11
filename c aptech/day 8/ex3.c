#include <stdio.h>

void increment(int a)
{
    a++;
    printf("%d", a);
}

int main(int argc, char const *argv[])
{
    int a;

    increment(a);

    return 0;
}

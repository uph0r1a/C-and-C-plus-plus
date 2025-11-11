#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("1");
    else
        printf("0");
    return 0;
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    if (n < 10 || n > 20)
        printf("1");
    else
        printf("0");
    return 0;
}
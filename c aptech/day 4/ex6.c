#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
label:
    printf("Nhap n (n >= 20): ");
    scanf("%d", &n);

    if (n < 20)
        goto label;

    printf("%d\n", n);

    return 0;
}
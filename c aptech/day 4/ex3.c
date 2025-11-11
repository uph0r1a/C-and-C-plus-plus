#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("Nhap a: ");
    scanf("%d", &a);

    if (a >= 0 && a <= 9)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
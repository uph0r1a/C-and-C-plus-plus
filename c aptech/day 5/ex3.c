#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, tong = 0;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            tong += i;
        }
    }
    printf("%d", tong);
    return 0;
}
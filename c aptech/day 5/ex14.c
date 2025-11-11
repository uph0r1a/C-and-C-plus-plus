#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, tong = 0, du;

    printf("Nhap so: ");
    scanf("%d", &n);

    while (n != 0)
    {
        du = n % 10;

        tong += du;

        n /= 10;
    }

    if (tong == 9)
    {
        printf("So dep");
    }
    else
    {
        printf("So ko dep");
    }
    return 0;
}
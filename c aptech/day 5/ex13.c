#include <stdio.h>

int main(int argc, char const *argv[])
{
    int b, d = 0, du, b1;

    printf("Nhap so: ");
    scanf("%d", &b);
    b1 = b;

    while (b1 != 0)
    {
        du = b1 % 10;

        d = d * 10 + du;

        b1 /= 10;
    }

    if (b != d)
    {
        printf("Day ko la so dao nguoc");
    }
    else
    {
        printf("Day la so dao nguoc");
    }
    return 0;
}
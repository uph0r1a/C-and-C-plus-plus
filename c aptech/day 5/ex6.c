#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int x, n, tong;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Nhap n: ");
    scanf("%d", &n);

    tong = x;

    for (int i = 1; i <= n; i++)
    {
        tong += pow(x, (2 * i) + 1);
    }
    printf("%d", tong);
    return 0;
}
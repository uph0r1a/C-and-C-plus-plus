#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, tong = 0;
    printf("Nhap n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        tong += i;
    }
    printf("%d", tong);
    return 0;
}
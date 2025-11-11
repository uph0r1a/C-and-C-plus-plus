#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, giaithua = 1;
    printf("Nhap n: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        giaithua *= i;
    }
    printf("%d", giaithua);
    return 0;
}
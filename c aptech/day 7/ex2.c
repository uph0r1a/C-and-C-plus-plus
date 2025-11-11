#include <stdio.h>

int sum1toN(int N)
{
    int tong = 0;
    printf("Nhap N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        tong += i;
    }
    return tong;
}

int main(int argc, char const *argv[])
{
    int n;
    sum1toN(n);

    return 0;
}

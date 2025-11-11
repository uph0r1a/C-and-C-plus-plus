#include <stdio.h>

int sumchan1toN(int N)
{
    int tong = 0;
    printf("Nhap N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            tong += i;
        }
    }
    return tong;
}

int main(int argc, char const *argv[])
{
    int n;
    sumchan1toN(n);

    return 0;
}

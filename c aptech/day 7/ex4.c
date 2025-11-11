#include <stdio.h>

int giaithua(int N)
{
    int giaithua = 1;
    printf("Nhap N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        giaithua *= i;
    }
    return giaithua;
}

int main(int argc, char const *argv[])
{
    int n;
    giaithua(n);

    return 0;
}

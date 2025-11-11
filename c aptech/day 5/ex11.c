#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, bool = 1;

    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 2)
    {
        bool = 0;
    }
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                bool = 0;
                break;
            }
        }
    }

    if (bool)
    {
        printf("%d la so nguyen to\n", n);
    }
    else
    {
        printf("%d khong la so nguyen to\n", n);
    }
    return 0;
}
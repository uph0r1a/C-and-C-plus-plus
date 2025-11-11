#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Nhap so dong: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int num = 1;
        for (int j = 0; j < n - i - 1; j++)
            printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("%4d", num);
            num = num * (i - j) / (j + 1);
        }
        printf("\n");
    }
    return 0;
}
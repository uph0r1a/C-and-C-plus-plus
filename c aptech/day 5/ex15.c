#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
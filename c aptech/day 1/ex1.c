#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Hay nhap so a: ");
    scanf("%d", &a);
    printf("Hay nhap so b: ");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);

    if (b != 0)
    {
        printf("%d / %d = %d\n", a, b, a / b);
        printf("%d %% %d = %d\n", a, b, a % b);
        printf("%d / %d = %.3f\n", a, b, 1.0 * a / b);
    }
    else
    {
        printf("Khong the chia hoac chia du cho 0.\n");
    }

    return 0;
}
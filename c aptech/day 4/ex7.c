#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    char dau;

    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("Nhap dau (+, -, *, /): ");
    scanf(" %c", &dau);

    switch (dau)
    {
    case '+':
        printf("%d + %d = %d\n", a, b, a + b);
        break;
    case '-':
        printf("%d - %d = %d\n", a, b, a - b);
        break;
    case '*':
        printf("%d * %d = %d\n", a, b, a * b);
        break;
    case '/':
        if (b == 0)
            printf("Loi: Khong the chia cho 0.\n");
        else
            printf("%d / %d = %.2f\n", a, b, (float)a / b);
        break;
    default:
        printf("Toan tu khong hop le.\n");
        break;
    }

    return 0;
}
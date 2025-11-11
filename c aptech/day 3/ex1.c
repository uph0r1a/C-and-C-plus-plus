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
        printf("a + b = %d\n", a + b);
        break;
    case '-':
        printf("a - b = %d\n", a - b);
        break;
    case '*':
        printf("a * b = %d\n", a * b);
        break;
    case '/':
        if (b == 0)
            printf("Loi: Khong the chia cho 0.\n");
        else
            printf("a / b = %.2f\n", (float)a / b);
        break;
    default:
        printf("Toan tu khong hop le.\n");
        break;
    }

    return 0;
}
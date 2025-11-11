#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    printf("Nhap 3 canh cua mot tam giac: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
    {
        int chuvi = a + b + c;
        float p = chuvi / 2.0;
        float dientich = sqrt(p * (p - a) * (p - b) * (p - c));

        printf("Chu vi cua tam giac co ba canh %d, %d, %d la %d\n", a, b, c, chuvi);
        printf("Dien tich cua tam giac co ba canh %d, %d, %d la %.2f\n", a, b, c, dientich);
    }
    else
    {
        printf("Ba canh %d, %d, %d khong tao thanh tam giac hop le.\n", a, b, c);
    }

    return 0;
}
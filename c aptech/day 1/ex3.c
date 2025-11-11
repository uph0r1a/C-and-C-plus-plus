#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    const float PI = 3.14;
    int r;

    printf("Hay nhap ban kinh R: ");
    scanf("%d", &r);

    if (r > 0)
    {
        float chuvi = 2 * PI * r;
        float dientich = PI * pow(r, 2);

        printf("Chu vi cua hinh tron ban kinh %d la %.2f\n", r, chuvi);
        printf("Dien tich cua hinh tron ban kinh %d la %.2f\n", r, dientich);
    }
    else
    {
        printf("Ban kinh phai lon hon 0.\n");
    }

    return 0;
}
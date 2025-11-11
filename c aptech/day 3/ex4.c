#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float a, b, c;

    printf("Nhap a: ");
    scanf("%f", &a);
    printf("Nhap b: ");
    scanf("%f", &b);
    printf("Nhap c: ");
    scanf("%f", &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("VSN");
            else
                printf("VN");
        }
        else
        {
            float x = -c / b;
            printf("Nghiem: %.2f", x);
        }
    }
    else
    {
        float delta = b * b - 4 * a * c;

        if (delta < 0)
            printf("VN");
        else if (delta == 0)
        {
            float x = -b / (2 * a);
            printf("Nghiem kep: %.2f", x);
        }
        else
        {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Nghiem 1: %.2f\n", x1);
            printf("Nghiem 2: %.2f", x2);
        }
    }

    return 0;
}
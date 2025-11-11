#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, b;

    printf("Nhap a: ");
    scanf("%f", &a);
    printf("Nhap b: ");
    scanf("%f", &b);

    if (a == 0)
    {
        if (b == 0)
            printf("VSN");
        else
            printf("VN");
    }
    else
    {
        float x = -b / a;
        printf("Nghiem: %.2f", x);
    }

    return 0;
}
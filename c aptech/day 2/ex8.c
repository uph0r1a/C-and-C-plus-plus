#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    printf("Nhap canh a: ");
    scanf("%d", &a);
    printf("Nhap canh b: ");
    scanf("%d", &b);
    printf("Nhap canh c: ");
    scanf("%d", &c);

    if (a == b && b == c)
    {
        printf("1");
    }
    else if (a * a + b * b == c * c ||
             a * a + c * c == b * b ||
             b * b + c * c == a * a)
    {
        printf("3");
    }
    else if (a == b || a == c || b == c)
    {
        printf("2");
    }
    else
    {
        printf("4");
    }
    return 0;
}
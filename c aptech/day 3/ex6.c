#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n;

    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("%d ko phai so chinh phuong\n", n);
    }
    else
    {
        int can = (int)sqrt(n);
        if (can * can == n)
            printf("%d la so chinh phuong\n", n);
        else
            printf("%d ko phai so chinh phuong\n", n);
    }

    return 0;
}
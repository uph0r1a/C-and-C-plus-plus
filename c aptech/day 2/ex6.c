#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nam;
    printf("Nhap so nam: ");
    scanf("%d", &nam);
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
        printf("YES");
    else
        printf("NO");
    return 0;
}
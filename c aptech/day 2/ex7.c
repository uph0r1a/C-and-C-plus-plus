#include <stdio.h>

int main(int argc, char const *argv[])
{
    int thang, nam;
    printf("Nhap thang: ");
    scanf("%d", &thang);
    printf("Nhap nam: ");
    scanf("%d", &nam);

    if (thang == 2)
    {
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
            printf("29");
        else
            printf("28");
    }
    else if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
    {
        printf("31");
    }
    else
    {
        printf("30");
    }
    return 0;
}
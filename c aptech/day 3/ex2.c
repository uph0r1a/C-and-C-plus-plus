#include <stdio.h>

int main(int argc, char const *argv[])
{
    int thang, nam;

    printf("Nhap thang: ");
    scanf("%d", &thang);
    printf("Nhap nam: ");
    scanf("%d", &nam);

    if (thang < 1 || thang > 12)
    {
        printf("Thang khong hop le.");
    }
    else
    {
        switch (thang)
        {
        case 2:
            if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
                printf("29");
            else
                printf("28");
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30");
            break;
        }
    }

    return 0;
}
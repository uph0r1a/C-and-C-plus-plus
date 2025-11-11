#include <stdio.h>

int main(int argc, char const *argv[])
{
    int bcc_so;
    printf("Nhap bang cuu chuong: ");
    scanf("%d", &bcc_so);
    if (bcc_so >= 1 && bcc_so <= 10)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("%d * %d = %d\n", bcc_so, i, bcc_so * i);
        }
    }
    return 0;
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int bcc_so, i = 1;

    printf("Nhap bang cuu chuong (1-10): ");
    scanf("%d", &bcc_so);

    if (bcc_so >= 1 && bcc_so <= 10)
    {
    loop:
        printf("%d * %d = %d\n", bcc_so, i, bcc_so * i);
        if (i < 10)
        {
            i++;
            goto loop;
        }
    }

    return 0;
}
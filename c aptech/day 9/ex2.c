#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    int chon;
    printf("Nhap xau: ");
    fgets(c, 1000, stdin);
loop:
    printf("In thuong(1) hay hoa(2): ");
    scanf("%d", &chon);

    if (chon == 1)
    {
        printf("%s", strlwr(c));
    }
    else if (chon == 2)
    {
        printf("%s", strupr(c));
    }
    else
    {
        printf("Nhap sai\n");
        goto loop;
    }
    return 0;
}
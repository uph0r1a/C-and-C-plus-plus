#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char a;
    printf("Nhap chu a: ");
    scanf("%c", &a);

    if (isupper(a))
        printf("Chu hoa\n");
    else
        printf("Chu thuong\n");

    return 0;
}
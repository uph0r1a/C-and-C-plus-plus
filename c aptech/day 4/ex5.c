#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char a;
    printf("Nhap chu a: ");
    scanf(" %c", &a);

    if (isalpha(a))
        printf("%c\n", toupper(a));
    else
        printf("ERROR\n");

    return 0;
}
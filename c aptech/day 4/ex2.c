#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char a;
    printf("Nhap chu a: ");
    scanf("%c", &a);

    if (isupper(a))
        printf("%c\n", tolower(a));
    else
        printf("%c\n", toupper(a));

    return 0;
}
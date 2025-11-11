#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char a;
    printf("Nhap a: ");
    scanf(" %c", &a);

    if (isalpha(a))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
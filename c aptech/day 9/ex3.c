#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    printf("Nhap xau: ");
    fgets(c, 1000, stdin);

    for (int i = strlen(c); i >= 0; i--)
    {
        printf("%c", c[i]);
    }
    return 0;
}
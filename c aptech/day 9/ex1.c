#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    printf("Nhap xau: ");
    fgets(c, 1000, stdin);
    printf("Xau vua nhap : %s\n", c);
    return 0;
}
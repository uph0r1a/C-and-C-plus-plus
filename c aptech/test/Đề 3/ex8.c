#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char string[100];

    printf("Enter a string: ");
    scanf(" %[^\n]", string);

    printf("Reversed string: ");
    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char a[100], b[100];
    printf("Enter a string:");
    fgets(a, 100, stdin);

    int len = strlen(a);
    if (a[len - 1] == '\n')
    {
        a[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; i++)
    {
        b[i] = a[len - 1 - i];
    }
    b[len] = '\0';

    if (strcmp(a, b) == 0)
    {
        printf("The string is a palindrome");
    }
    else
    {
        printf("The string is not a palindrome");
    }
    return 0;
}

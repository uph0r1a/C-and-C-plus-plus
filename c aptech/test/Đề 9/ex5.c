#include <stdio.h>

int main()
{
    char string[100];
    char *ptr = string;
    char *end;

    printf("Enter product name: ");
    scanf(" %[^\n]", string);

    end = string;
    while (*end != '\0')
    {
        end++;
    }
    end--;

    printf("Reversed product name: ");

    while (end >= ptr)
    {
        printf("%c", *end);
        end--;
    }

    return 0;
}

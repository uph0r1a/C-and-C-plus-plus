#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a[100];
    int count = 0;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", a);

    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
    {
        if (a[i] == ' ')
        {
            count++;
        }
    }

    printf("The number of words: %d", count);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_separator(char c)
{
    return c == ' ' || c == '_' || c == '-';
}

int main(int argc, char const *argv[])
{
    char input[1000];
    char output[1000];
    int i = 0, j = 0;

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    while (is_separator(input[i]))
        i++;

    int word_started = 0;

    while (input[i] != '\0')
    {
        if (is_separator(input[i]))
        {
            if (word_started)
            {
                output[j++] = '_';
                word_started = 0;
            }
            while (is_separator(input[i]))
                i++;
        }
        else
        {
            output[j++] = input[i++];
            word_started = 1;
        }
    }

    if (j > 0 && output[j - 1] == '_')
        j--;

    output[j] = '\0';

    printf("Ket qua: %s\n", output);

    return 0;
}
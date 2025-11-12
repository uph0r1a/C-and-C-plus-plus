#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoaTen(char *s)
{
    char temp[1000];
    int i = 0, j = 0;

    while (isspace(s[i]))
        i++;

    int word_started = 0;

    while (s[i] != '\0')
    {
        if (isspace(s[i]))
        {
            if (word_started)
            {
                temp[j++] = ' ';
                word_started = 0;
            }
            while (isspace(s[i]))
                i++;
        }
        else
        {
            temp[j++] = tolower(s[i++]);
            word_started = 1;
        }
    }

    if (j > 0 && temp[j - 1] == ' ')
        j--;

    temp[j] = '\0';

    int len = strlen(temp);
    int first = 1;
    for (i = 0; i < len; i++)
    {
        if (first && isalpha(temp[i]))
        {
            temp[i] = toupper(temp[i]);
            first = 0;
        }
        else if (temp[i] == ' ')
        {
            first = 1;
        }
    }

    strcpy(s, temp);
}

int main(int argc, char const *argv[])
{
    char name[1000];

    printf("Nhap ten: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    chuanHoaTen(name);

    printf("Ten chuan hoa: %s\n", name);

    return 0;
}
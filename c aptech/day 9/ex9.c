#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoaTu(char *s)
{
    if (strlen(s) > 0)
    {
        s[0] = toupper(s[0]);
        for (int i = 1; s[i]; i++)
        {
            s[i] = tolower(s[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    char input[1000];
    char *words[100];
    int count = 0;

    printf("Nhap ho ten: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " \t");
    while (token != NULL)
    {
        chuanHoaTu(token);
        words[count++] = token;
        token = strtok(NULL, " \t");
    }

    if (count == 0)
    {
        printf("Khong co tu nao!\n");
        return 0;
    }

    printf("Ten chuan hoa: %s", words[count - 1]);

    for (int i = 0; i < count - 1; i++)
    {
        printf(" %s", words[i]);
    }

    printf("\n");

    return 0;
}
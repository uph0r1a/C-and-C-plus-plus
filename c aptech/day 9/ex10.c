#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerStr(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]);
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
        words[count++] = token;
        token = strtok(NULL, " \t");
    }

    if (count == 0)
    {
        printf("Khong co ten!\n");
        return 0;
    }

    char email[100] = "";
    char ten[50];
    strcpy(ten, words[count - 1]);
    toLowerStr(ten);
    strcat(email, ten);

    for (int i = 0; i < count - 1; i++)
    {
        char ch = tolower(words[i][0]);
        char str[2] = {ch, '\0'};
        strcat(email, str);
    }

    strcat(email, "@aptech.com.vn");

    printf("Email: %s\n", email);

    return 0;
}
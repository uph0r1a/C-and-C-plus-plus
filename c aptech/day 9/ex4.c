#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    int nguyenam = 0, phuam = 0;

    printf("Nhap xau: ");
    fgets(c, 1000, stdin);

    for (int i = 0; i < strlen(c); i++)
    {
        char ch = tolower(c[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            nguyenam++;
        }
        else if (isalpha(ch))
        {
            phuam++;
        }
    }

    printf("Nguyen am: %d\nPhu am: %d\n", nguyenam, phuam);

    return 0;
}
#include <stdio.h>

int ctype(char c)
{
    char chon;
    printf("1)isalnum \t2)isdigit \t3)islower \t4)isupper \t5)isalpha \t6)tolower \t7)toupper \t8)isspace \nChon stt cua ham:");
    scanf(" %c", &chon);

    if (chon == '1')
    {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (chon == '2')
    {
        if (c >= '0' && c <= '9')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (chon == '3')
    {
        if (c >= 'a' && c <= 'z')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (chon == '4')
    {
        if (c >= 'A' && c <= 'Z')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (chon == '5')
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (chon == '6')
    {
        if (c >= 'A' && c <= 'Z')
        {
            return c + 32;
        }
        else
        {
            return c;
        }
    }
    else if (chon == '7')
    {
        if (c >= 'a' && c <= 'z')
        {
            return c - 32;
        }
        else
        {
            return c;
        }
    }
    else if (chon == '8')
    {
        if (c == ' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    char c;
    ctype(c);
    
    return 0;
}

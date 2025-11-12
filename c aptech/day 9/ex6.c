#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    int tansuat[256] = {0};
    int length;

    printf("Nhap xau: ");
    fgets(c, 1000, stdin);

    c[strcspn(c, "\n")] = 0;

    length = strlen(c);

    for (int i = 0; i < length; i++)
    {
        unsigned char ch = (unsigned char)c[i];
        tansuat[ch]++;
    }

    printf("Tan suat xuat hien cac ky tu:\n");
    for (int i = 0; i < 256; i++)
    {
        if (tansuat[i] > 0)
        {
            printf("Ky tu '%c' xuat hien %d lan\n", i, tansuat[i]);
        }
    }

    return 0;
}
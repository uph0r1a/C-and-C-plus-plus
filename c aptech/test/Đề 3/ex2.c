#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 1;
    do
    {
        printf("%d\n", i);
        if (i > 9)
        {
            break;
        }
        i++;
    } while (1);

    return 0;
}

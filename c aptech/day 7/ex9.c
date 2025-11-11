#include <stdio.h>

void sochandautien(int n)
{
    int du, check = 0;
    while (n != 0)
    {
        du = n % 10;
        if (du % 2 == 0)
        {
            printf("%d", du);
            check = 1;
            break;
        }

        n /= 10;
    }
    if (check == 0)
    {
        printf("N ko co so chan");
    }
}

int main(int argc, char const *argv[])
{
    int n;
    sochandautien(n);
    
    return 0;
}

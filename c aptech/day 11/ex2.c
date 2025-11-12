#include <stdio.h>
#include <math.h>

int prime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    FILE *f;
    f = fopen("prime.txt", "w");
    int dem = 0;
    for (int i = 1; i <= 200; i++)
    {
        if (prime(i))
        {
            fprintf(f, "%d", i);
            ++dem;
        }
    }
    fclose(f);
    return 0;
}
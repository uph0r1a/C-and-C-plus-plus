#include <stdio.h>

int demchuso(int N)
{
    int i = 0;
    printf("Nhap N: ");
    scanf("%d", &N);

    do
    {
        N /= 10;
        i++;
    } while (N > 0);
    return i;
}

int main(int argc, char const *argv[])
{
    int n;
    demchuso(n);
    
    return 0;
}

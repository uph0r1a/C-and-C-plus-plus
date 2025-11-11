#include <stdio.h>

int tong(int N)
{
    int tong = 0;
    while (N != 0)
    {
        tong += N % 10;
        N /= 10;
    }
    return tong;
}

int main(int argc, char const *argv[])
{
    int n;
    tong(n);
    
    return 0;
}

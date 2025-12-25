#include <iostream>
using namespace std;

int sumDigits(int n)
{
    int temp = n, sum = 0;

    if (n == 0)
    {
        return n;
    }
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n = 123456;
    cout << sumDigits(n);
    return 0;
}

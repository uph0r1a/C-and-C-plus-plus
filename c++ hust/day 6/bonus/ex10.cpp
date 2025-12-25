#include <iostream>
using namespace std;

void minMaxDigits(int n)
{
    int max = 0, min = 9, temp = n;

    if (n == 0)
    {
        max = min = 0;
    }

    while (temp > 0)
    {
        int digit = temp % 10;

        if (digit > max)
        {
            max = digit;
        }

        if (digit < min)
        {
            min = digit;
        }

        temp /= 10;
    }

    cout << "Smallest digits: " << min << endl
         << "Largest digits: " << max << endl;
}

int main(int argc, char const *argv[])
{
    int n = 1234567;
    minMaxDigits(n);
    return 0;
}

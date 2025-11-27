#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a positive integer: ";
    while (1)
    {
        cin >> n;
        if (n > 0)
        {
            break;
        }
        cout << "Integer must be positive\nRe-enter a positive integer: ";
    }

    if (n >= 2)
    {
        cout << "Prime numbers less than " << n << " are:\n";
        cout << 2 << endl;

        for (int i = 3; i < n; i += 2)
        {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                cout << i << endl;
            }
        }
    }
    else
    {
        cout << "No prime numbers less than " << n << endl;
    }

    return 0;
}

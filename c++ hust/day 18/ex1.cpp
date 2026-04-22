#include <iostream>
using namespace std;

int factorial(int n)
{
    int factorial = n;
    if (n == 0 || n == 1)
    {
        return 1;
    }

    for (int i = n - 1; i > 0; i--)
    {
        factorial *= i;
    }
    return factorial;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter n: ";
    while (1)
    {
        cin >> n;
        if (n >= 0)
        {
            break;
        }
        cout << "N must not be negative\nRe-enter n: ";
    }

    cout << "Factorial of " << n << ": " << factorial(n);
    return 0;
}

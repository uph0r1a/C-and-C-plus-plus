#include <iostream>
using namespace std;

bool isPrime(int a)
{
    if (a == 2)
    {
        return true;
    }
    if (a <= 1)
    {
        return false;
    }

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int a;
    cout << "Enter a number: ";
    cin >> a;

    if (isPrime(a))
    {
        cout << a << " is prime";
    }
    else
    {
        cout << a << " is not prime";
    }

    return 0;
}

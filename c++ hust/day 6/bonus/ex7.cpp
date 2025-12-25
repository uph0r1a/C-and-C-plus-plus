#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n = 996;

    if (isPrime(n))
    {
        cout << "N is prime" << endl;
    }
    else
    {
        cout << "N is not prime" << endl;
    }

    return 0;
}

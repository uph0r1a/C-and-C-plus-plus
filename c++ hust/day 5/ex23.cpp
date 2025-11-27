#include <iostream>
#include <fstream>
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
    ofstream f("prime.txt");
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i))
        {
            f << i << "\t";
        }
    }

    f.close();
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b)
{
    int count;
    if (a < b)
    {
        count = a;
    }
    else
    {
        count = b;
    }

    for (int i = count; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 0;
}

int LCM(int a, int b)
{
    if (GCD(a, b) == 0)
    {
        return 0;
    }

    return (abs(a * b)) / GCD(a, b);
}

int main(int argc, char const *argv[])
{
    int a, b;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if (LCM(a, b) == 0)
    {
        cout << "No LCM" << endl;
    }
    else
    {
        cout << "LCM = " << LCM(a, b);
    }

    return 0;
}

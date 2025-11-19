#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    float x, sum = 0;
    cout << "Enter n: ";
    while (1)
    {
        cin >> n;
        if (n > 0)
        {
            break;
        }
        cout << "n must be positive\n";
        cout << "Re-enter n: ";
    }

    cout << "Enter x: ";
    while (1)
    {
        cin >> x;
        if (x > 0)
        {
            break;
        }
        cout << "x must be positive\n";
        cout << "Re-enter x: ";
    }

    for (int i = 1; i <= n; i++)
    {
        sum += pow(x, i);
    }

    cout << "S(n) = x + x^2 + x^3 + ... + x^n = " << sum;

    return 0;
}

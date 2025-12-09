#include <iostream>
#include <cmath>
using namespace std;

float S(int n, float x)
{
    if (n == 1)
    {
        return sqrt(x);
    }

    return sqrt(x + S(n - 1, x));
}

int main(int argc, char const *argv[])
{
    int n;
    float x;

    cout << "Enter x: ";
    while (1)
    {
        cin >> x;
        if (x >= 0)
        {
            break;
        }
        cout << "X cannot be negative\nRe-enter x: ";
    }

    cout << "Enter n: ";
    while (1)
    {
        cin >> n;
        if (n >= 0)
        {
            break;
        }
        cout << "N cannot be negative\nRe-enter n: ";
    }

    float s = S(n, x);

    cout << "S = " << s << endl;

    return 0;
}

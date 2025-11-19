#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Enter a: ";
    while (1)
    {
        cin >> a;
        if (a > 0)
        {
            break;
        }
        cout << "a must be positive\n";
        cout << "Re-enter a: ";
    }

    cout << "Enter b: ";
    while (1)
    {
        cin >> b;
        if (b > 0)
        {
            break;
        }
        cout << "b must be positive\n";
        cout << "Re-enter b: ";
    }

    for (int i = a; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            cout << "GCD: " << i;
            break;
        }
    }
    return 0;
}

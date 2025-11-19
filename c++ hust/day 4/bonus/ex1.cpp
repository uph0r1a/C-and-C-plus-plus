#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, factorial = 1;
    cout << "Enter a positive interger n: ";
    while (1)
    {
        cin >> n;
        if (n >= 0)
        {
            break;
        }
        cout << "n must not be negative\n";
        cout << "Re-enter a positive interger n: ";
    }

    if (n == 0)
    {
        cout << "Factorial: 1";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    cout << "Factorial: " << factorial;

    return 0;
}

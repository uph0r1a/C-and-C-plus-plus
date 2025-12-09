#include <iostream>
#include <iomanip>
using namespace std;

double S(int n)
{
    if (n == 1)
        return 1.0 / (1.0 * 2.0);

    return 1.0 / (n * (n + 1)) + S(n - 1);
}

int main()
{
    int n;
    cout << "Enter integer n (>= 1): ";
    while (cin >> n)
    {
        if (n >= 1)
            break;
        cout << "N must be positive\nRe-enter n: ";
    }

    cout << fixed << setprecision(6);
    cout << "S = " << S(n) << endl;

    return 0;
}

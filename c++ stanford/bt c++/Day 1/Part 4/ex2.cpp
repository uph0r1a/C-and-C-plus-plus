#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double fa(double x)
{
    return (x > 0) ? 3 * x + sqrt(x) : exp(x) + 4;
}

double fb(double x)
{
    if (x >= 1)
        return sqrt(x * x + 1);
    else if (x > -1)
        return 3 * x + 5;
    else
        return x * x + 2 * x - 1;
}

int main(int argc, char const *argv[])
{
    double x;
    cout << fixed << setprecision(4);

    cout << "--- Ham f_a ---\n";
    cout << "Nhap x: ";
    cin >> x;
    cout << "f_a(" << x << ") = " << fa(x) << "\n";

    cout << "--- Ham f_b ---\n";
    cout << "Nhap x: ";
    cin >> x;
    cout << "f_b(" << x << ") = " << fb(x) << "\n";

    return 0;
}

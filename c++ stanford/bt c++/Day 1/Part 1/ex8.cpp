#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b;
    cout << "Nhap gia tri a ban dau: ";
    cin >> a;
    cout << "Nhap gia tri b ban dau: ";
    cin >> b;

    for (int i = 0; i < 3; i++)
    {
        a = sqrt(3 + a);
        b = 2 + 1.0 / b;
    }

    cout << fixed << setprecision(2);
    cout << "a) " << a << "\n";
    cout << "b) " << b - 2 << "\n";
    return 0;
}

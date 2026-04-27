#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    double cau_a = a * a - 2 * b + (a * b / c);
    double cau_b = (b * b - 4 * a * c) / (2 * a);
    double cau_c = 3 * a - b * b * b - 2 * sqrt(c);
    double cau_d = sqrt(a * a / b - 4 * a / b * c + 1);

    cout << fixed << setprecision(3);
    cout << "a) " << cau_a << "\n";
    cout << "b) " << cau_b << "\n";
    cout << "c) " << cau_c << "\n";
    cout << "d) " << cau_d << "\n";
    return 0;
}

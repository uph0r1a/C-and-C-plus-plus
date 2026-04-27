#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double a = 0, b = 0, c = 0;

    cout << "Nhap gia tri a: ";
    cin >> a;
    cout << "Nhap gia tri b: ";
    cin >> b;
    cout << "Nhap gia tri c: ";
    cin >> c;

    double cau9a = pow(a, 2) - 2 * b + (a * b) / c;
    double cau9b = 3 * a - pow(b, 3) - 2 * sqrt(c);
    double cau9c = (b * b - 16 * a) / (2 * a);
    double cau9d = sqrt(pow(a, 2) / b - (4 * a) / (b * c) + 1);

    cout << fixed << setprecision(3);
    cout << "\na) a^2 - 2b + (ab)/c = " << cau9a << endl;
    cout << "b) 3a - b^3 - 2*sqrt(c) = " << cau9b << endl;
    cout << "c) (b^2 - 16a) / (2a) = " << cau9c << endl;
    cout << "d) sqrt(a^2/b - 4a/(bc) + 1) = " << cau9d << endl;

    return 0;
}

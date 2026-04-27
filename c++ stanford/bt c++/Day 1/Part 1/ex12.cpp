#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const double PI = acos(-1.0);

    double a, l, w, r;
    cout << "Nhap canh hinh vuong: ";
    cin >> a;
    cout << "Nhap chieu dai hinh chu nhat: ";
    cin >> l;
    cout << "Nhap chieu rong hinh chu nhat: ";
    cin >> w;
    cout << "Nhap ban kinh hinh tron: ";
    cin >> r;

    cout << fixed << setprecision(2);

    cout << "\nHinh vuong:\n";
    cout << "Dien tich = " << a * a << "\n";
    cout << "Chu vi = " << 4 * a << "\n";

    cout << "\nHinh chu nhat:\n";
    cout << "Dien tich = " << l * w << "\n";
    cout << "Chu vi = " << 2 * (l + w) << "\n";

    cout << "\nHinh tron:\n";
    cout << "Dien tich = " << PI * r * r << "\n";
    cout << "Chu vi = " << 2 * PI * r << "\n";

    return 0;
}

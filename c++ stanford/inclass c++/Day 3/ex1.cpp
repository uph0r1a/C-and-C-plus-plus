#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    const double PI = 3.14159265358979;
    double r = 0;

    cout << "Nhap ban kinh hinh tron r: ";
    cin >> r;

    if (r <= 0)
    {
        cout << "Ban kinh phai lon hon 0!\n";
        return 1;
    }

    double sTron = PI * r * r;
    double sVuong = (2 * r) * (2 * r);
    double sGioiHan = sVuong - sTron;

    cout << "Dien tich hinh vuong = " << sVuong << "\n";
    cout << "Dien tich hinh tron = " << sTron << "\n";
    cout << "Dien tich gioi han = " << sGioiHan << "\n";

    return 0;
}
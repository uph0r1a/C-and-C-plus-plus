#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b, c;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;
    cout << "Nhap so thu ba: ";
    cin >> c;

    double tbCong = (a + b + c) / 3.0;

    double tich = a * b * c;
    cout << fixed << setprecision(2);
    cout << "Trung binh cong = " << tbCong << "\n";
    if (tich >= 0)
        cout << "Trung binh nhan = " << cbrt(tich) << "\n";
    else
        cout << "Trung binh nhan khong xac dinh (tich am).\n";

    return 0;
}

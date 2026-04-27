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

    double trungBinhCong = (a + b + c) / 3.0;
    double tich = a * b * c;
    double trungBinhNhan = (tich >= 0) ? pow(tich, 1.0 / 3.0) : -pow(-tich, 1.0 / 3.0);

    cout << fixed << setprecision(3);
    cout << "\nTrung binh cong: " << trungBinhCong << endl;
    cout << "Trung binh nhan: " << trungBinhNhan << endl;

    return 0;
}

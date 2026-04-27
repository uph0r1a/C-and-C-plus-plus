#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a = 0, b = 0, c = 0;

    cout << "Nhap he so a (a != 0): ";
    cin >> a;

    if (a == 0)
    {
        cout << "Loi: He so a phai khac 0!" << endl;
        return 1;
    }

    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap gia tri c: ";
    cin >> c;

    double x = (c - b) / a;

    cout << fixed << setprecision(2);
    cout << "\nPhuong trinh: " << a << "x + " << b << " = " << c << endl;
    cout << "Nghiem: x = " << x << endl;

    return 0;
}

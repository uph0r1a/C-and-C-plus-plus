#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a = 0, b = 0;

    cout << "Nhap gia tri a: ";
    cin >> a;
    cout << "Nhap gia tri b: ";
    cin >> b;

    cout << fixed << setprecision(2);
    cout << "\nTong (" << a << " + " << b << ") = " << a + b << endl;
    cout << "Hieu (" << a << " - " << b << ") = " << a - b << endl;
    cout << "Tich (" << a << " * " << b << ") = " << a * b << endl;

    if (b != 0)
        cout << "Thuong(" << a << " / " << b << ") = " << a / b << endl;
    else
        cout << "Thuong: Khong the chia cho 0!" << endl;

    return 0;
}

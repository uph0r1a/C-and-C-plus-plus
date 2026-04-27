#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;

    cout << fixed << setprecision(4);
    cout << "Tong = " << a + b << "\n";
    cout << "Hieu = " << a - b << "\n";
    cout << "Tich = " << a * b << "\n";
    if (b != 0)
        cout << "Thuong = " << a / b << "\n";
    else
        cout << "Khong the chia cho 0!\n";

    return 0;
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a = 0, b = 0, c = 0;

    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    cout << "\nPhuong trinh: "
         << a << "x^2 + "
         << b << "x + "
         << c << " = 0" << endl;

    return 0;
}

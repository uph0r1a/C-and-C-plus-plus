#include <iostream>
#include <cmath>
using namespace std;

void giaiPhuongTrinhBacHai()
{
    double a = 0, b = 0, c = 0;

    cout << "Nhap he so a (a != 0): ";
    cin >> a;
    if (a == 0)
    {
        cout << "He so a phai khac 0!\n";
        return;
    }

    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    double delta = b * b - 4 * a * c;

    cout << "\nPhuong trinh: " << a << "x^2 + " << b << "x + " << c << " = 0\n";
    cout << "Delta = " << delta << "\n";

    if (delta < 0)
    {
        cout << "Phuong trinh vo nghiem.\n";
    }
    else if (delta == 0)
    {
        cout << "Phuong trinh co nghiem kep: x = " << -b / (2 * a) << "\n";
    }
    else
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co 2 nghiem: x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
}

int main(int argc, char const *argv[])
{
    giaiPhuongTrinhBacHai();
    return 0;
}

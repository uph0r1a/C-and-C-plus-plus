#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b, c;

    do
    {
        cout << "Nhap he so a (khac 0): ";
        cin >> a;
    } while (a == 0);
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    double delta = b * b - 4 * a * c;

    cout << fixed << setprecision(4);
    cout << "Delta = " << delta << "\n";

    if (delta > 0)
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co hai nghiem phan biet:\n";
        cout << "  x1 = " << x1 << "\n";
        cout << "  x2 = " << x2 << "\n";
    }
    else if (delta == 0)
    {
        double x = -b / (2 * a);
        cout << "Phuong trinh co nghiem kep: x = " << x << "\n";
    }
    else
    {
        double re = -b / (2 * a);
        double im = sqrt(-delta) / (2 * a);
        cout << "Phuong trinh vo nghiem thuc (delta < 0).\n";
        cout << "Nghiem phuc:\n";
        cout << "  x1 = " << re << " + " << im << "i\n";
        cout << "  x2 = " << re << " - " << im << "i\n";
    }
    return 0;
}

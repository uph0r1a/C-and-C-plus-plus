#include <iostream>
#include <iomanip>
using namespace std;

void giai(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double D = a1 * b2 - a2 * b1;
    double Dx = c1 * b2 - c2 * b1;
    double Dy = a1 * c2 - a2 * c1;

    cout << fixed << setprecision(4);
    if (D != 0)
    {
        cout << "Nghiem duy nhat: x = " << Dx / D << ",  y = " << Dy / D << "\n";
    }
    else
    {
        if (Dx == 0 && Dy == 0)
            cout << "Vo so nghiem (hai phuong trinh tuong duong).\n";
        else
            cout << "Vo nghiem (hai duong thang song song).\n";
    }
}

int main(int argc, char const *argv[])
{
    double a1, b1, c1, a2, b2, c2;
    cout << "PT1 a1*x + b1*y = c1 -> a1 b1 c1: ";
    cin >> a1 >> b1 >> c1;
    cout << "PT2 a2*x + b2*y = c2 -> a2 b2 c2: ";
    cin >> a2 >> b2 >> c2;
    giai(a1, b1, c1, a2, b2, c2);
    return 0;
}
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b, c;

    do
    {
        cout << "Nhap canh a (> 0): ";
        cin >> a;
    } while (a <= 0);
    do
    {
        cout << "Nhap canh b (> 0): ";
        cin >> b;
    } while (b <= 0);
    do
    {
        cout << "Nhap canh c (> 0): ";
        cin >> c;
    } while (c <= 0);

    if (a + b > c && a + c > b && b + c > a)
    {
        double p = (a + b + c) / 2.0;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << fixed << setprecision(4);
        cout << "Chu vi = " << a + b + c << "\n";
        cout << "Dien tich = " << S << "\n";
    }
    else
    {
        cout << "a, b, c khong tao thanh tam giac hop le!\n";
    }

    return 0;
}

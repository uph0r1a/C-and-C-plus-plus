#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

static void inHeSo(double hs, const string &bien, bool laDauTien)
{
    if (hs == 0)
        return;

    if (laDauTien)
    {
        if (hs == 1 && !bien.empty())
            cout << bien;
        else if (hs == -1 && !bien.empty())
            cout << "-" << bien;
        else
            cout << hs << bien;
    }
    else
    {
        if (hs > 0)
            cout << " + ";
        else
            cout << " - ";
        double abs_hs = fabs(hs);
        if (abs_hs == 1 && !bien.empty())
            cout << bien;
        else
            cout << abs_hs << bien;
    }
}

int main(int argc, char const *argv[])
{
    double a, b, c;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    cout << "Phuong trinh: ";

    bool first = true;
    if (a != 0)
    {
        inHeSo(a, "x^2", first);
        first = false;
    }
    if (b != 0)
    {
        inHeSo(b, "x", first);
        first = false;
    }
    if (c != 0)
    {
        inHeSo(c, "", first);
    }
    if (first)
        cout << "0";

    cout << " = 0\n";
    return 0;
}

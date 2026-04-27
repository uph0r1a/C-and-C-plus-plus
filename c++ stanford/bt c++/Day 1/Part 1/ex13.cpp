#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, b, c;
    while (true)
    {
        cout << "Nhap canh a: ";
        cin >> a;
        cout << "Nhap canh b: ";
        cin >> b;
        cout << "Nhap canh c: ";
        cin >> c;
        if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
            break;
        cout << "[!] Ba canh khong hop le. Nhap lai.\n\n";
    }

    double s = (a + b + c) / 2.0;
    double S = sqrt(s * (s - a) * (s - b) * (s - c));
    double P = a + b + c;
    double h_a = 2 * S / a, h_b = 2 * S / b, h_c = 2 * S / c;
    double m_a = sqrt((2 * b * b + 2 * c * c - a * a) / 4.0);
    double m_b = sqrt((2 * a * a + 2 * c * c - b * b) / 4.0);
    double m_c = sqrt((2 * a * a + 2 * b * b - c * c) / 4.0);
    double l_a = (2 * b * c * sqrt(s * (s - a))) / ((b + c) * sqrt(s * (s - a) + (s - b) * (s - c))) * sqrt(s * (s - a) + (s - b) * (s - c));
    l_a = sqrt(b * c * ((b + c) * (b + c) - a * a)) / (b + c);
    double l_b = sqrt(a * c * ((a + c) * (a + c) - b * b)) / (a + c);
    double l_c = sqrt(a * b * ((a + b) * (a + b) - c * c)) / (a + b);
    double r_noi = S / s;
    double R_ngoai = (a * b * c) / (4 * S);

    cout << fixed << setprecision(4);
    cout << "\nChu vi = " << P << "\n";
    cout << "Dien tich = " << S << "\n";
    cout << "Duong cao: h_a =" << h_a << "  h_b =" << h_b << "  h_c =" << h_c << "\n";
    cout << "Trung tuyen: m_a =" << m_a << "  m_b =" << m_b << "  m_c =" << m_c << "\n";
    cout << "Phan giac: l_a =" << l_a << "  l_b =" << l_b << "  l_c =" << l_c << "\n";
    cout << "Ban kinh noi tiep r = " << r_noi << "\n";
    cout << "Ban kinh ngoai tiep R = " << R_ngoai << "\n";

    return 0;
}

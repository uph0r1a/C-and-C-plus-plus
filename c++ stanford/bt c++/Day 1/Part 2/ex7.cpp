#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

static double nhapDiem(const string &mon)
{
    double d;
    while (true)
    {
        cout << "Diem " << mon << " (0-10): ";
        cin >> d;
        if (d >= 0.0 && d <= 10.0)
            return d;
        cout << "[!] Diem phai tu 0 den 10.\n";
    }
}

static string xepLoai(double dtb)
{
    if (dtb >= 9.0)
        return "Xuat sac";
    if (dtb >= 8.0)
        return "Gioi";
    if (dtb >= 7.0)
        return "Kha";
    if (dtb >= 6.0)
        return "Trung binh kha";
    if (dtb >= 5.0)
        return "Trung binh";
    return "Kem";
}

int main(int argc, char const *argv[])
{
    double toan = nhapDiem("Toan");
    double ly = nhapDiem("Ly");
    double hoa = nhapDiem("Hoa");

    double dtb = (toan * 2 + ly + hoa) / 4.0;

    cout << fixed << setprecision(2);
    cout << "Diem trung binh: " << dtb << "\n";
    cout << "Hoc luc: " << xepLoai(dtb) << "\n";
    return 0;
}

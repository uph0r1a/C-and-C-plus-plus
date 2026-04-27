#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

static const double LUONG_CO_SO = 1'800'000.0;

struct NhanVien
{
    string hoTen;
    double heSoLuong;
    double pctPhuCap;
    double pctBHXH;

    double luongCoBan() const
    {
        return heSoLuong * LUONG_CO_SO;
    }
    double tienPhuCap() const
    {
        return luongCoBan() * pctPhuCap / 100.0;
    }
    double tienBHXH() const
    {
        return luongCoBan() * pctBHXH / 100.0;
    }
    double tongThuNhap() const
    {
        return luongCoBan() + tienPhuCap() - tienBHXH();
    }
};

static double nhapPercent(const string &label)
{
    double v;
    while (true)
    {
        cout << label << " (0-100%): ";
        cin >> v;
        if (v >= 0 && v <= 100)
            return v;
        cout << "[!] Phan tram phai tu 0 den 100.\n";
    }
}

int main(int argc, char const *argv[])
{
    const int N = 2;
    NhanVien nv[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nNhan vien thu " << (i + 1) << ":\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ho ten: ";
        getline(cin, nv[i].hoTen);
        cout << "He so luong: ";
        cin >> nv[i].heSoLuong;
        nv[i].pctPhuCap = nhapPercent("Phu cap");
        nv[i].pctBHXH = nhapPercent("BHXH");
    }

    cout << "\n"
         << string(80, '-') << "\n";
    cout << left
         << setw(20) << "Ho ten"
         << setw(8) << "He so"
         << setw(14) << "Luong CB"
         << setw(12) << "Phu cap"
         << setw(12) << "BHXH"
         << setw(14) << "Tong nhan"
         << "\n"
         << string(80, '-') << "\n";

    for (int i = 0; i < N; i++)
    {
        cout << fixed << setprecision(0)
             << left
             << setw(20) << nv[i].hoTen
             << setw(8) << nv[i].heSoLuong
             << setw(14) << nv[i].luongCoBan()
             << setw(12) << nv[i].tienPhuCap()
             << setw(12) << nv[i].tienBHXH()
             << setw(14) << nv[i].tongThuNhap()
             << "\n";
    }
    return 0;
}

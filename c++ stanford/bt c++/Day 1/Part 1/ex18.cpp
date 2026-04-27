#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

struct SinhVien
{
    string hoTen;
    int tuoi;
    double diemToan, diemTin;
    double diemTB() const
    {
        return (diemToan * 2 + diemTin) / 3.0;
    }
};

static double nhapDiem(const string &mon)
{
    double d;
    while (true)
    {
        cout << "Diem " << mon << " (0-10): ";
        cin >> d;
        if (d >= 0 && d <= 10)
            return d;
        cout << "[!] Diem phai tu 0 den 10.\n";
    }
}

int main(int argc, char const *argv[])
{
    const int N = 2;
    SinhVien sv[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nSinh vien thu " << (i + 1) << ":\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ho ten: ";
        getline(cin, sv[i].hoTen);
        cout << "Tuoi: ";
        cin >> sv[i].tuoi;
        sv[i].diemToan = nhapDiem("Toan");
        sv[i].diemTin = nhapDiem("Tin");
    }

    cout << "\n"
         << string(65, '-') << "\n";
    cout << left
         << setw(22) << "Ho ten"
         << setw(6) << "Tuoi"
         << setw(10) << "Toan(x2)"
         << setw(10) << "Tin(x1)"
         << setw(8) << "DTB"
         << "\n"
         << string(65, '-') << "\n";

    for (int i = 0; i < N; i++)
    {
        cout << fixed << setprecision(2)
             << left
             << setw(22) << sv[i].hoTen
             << setw(6) << sv[i].tuoi
             << setw(10) << sv[i].diemToan
             << setw(10) << sv[i].diemTin
             << setw(8) << sv[i].diemTB()
             << "\n";
    }
    return 0;
}

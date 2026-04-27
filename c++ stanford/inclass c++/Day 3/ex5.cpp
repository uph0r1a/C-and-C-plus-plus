#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct ThiSinh
{
    long SoBD;
    string HoTen;
    string DiaChi;
    float Toan, Ly, Hoa;
};

void NhapThiSinh(ThiSinh &ts)
{
    cout << "So BD: ";
    cin >> ts.SoBD;
    cin.ignore(1);
    cout << "Ho ten: ";
    getline(cin, ts.HoTen);
    cout << "Dia chi: ";
    getline(cin, ts.DiaChi);
    cout << "Diem Toan: ";
    cin >> ts.Toan;
    cout << "Diem Ly: ";
    cin >> ts.Ly;
    cout << "Diem Hoa: ";
    cin >> ts.Hoa;
}

void NhapDanhSach(ThiSinh ds[], int n)
{
    cout << "Nhap danh sach " << n << " thi sinh:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Thi sinh " << i + 1 << ":\n";
        NhapThiSinh(ds[i]);
    }
}

void InDanhSach(ThiSinh ds[], int n)
{
    cout << "\n";
    cout << left
         << setw(8) << "So BD"
         << setw(22) << "Ho ten"
         << setw(16) << "Dia chi"
         << setw(7) << "Toan"
         << setw(7) << "Ly"
         << setw(7) << "Hoa"
         << "\n";
    cout << string(67, '-') << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(8) << ds[i].SoBD
             << setw(22) << ds[i].HoTen
             << setw(16) << ds[i].DiaChi
             << setw(7) << ds[i].Toan
             << setw(7) << ds[i].Ly
             << setw(7) << ds[i].Hoa
             << "\n";
    }
}

int main(int argc, char const *argv[])
{
    const int MAX = 3;
    ThiSinh ds[MAX];

    NhapDanhSach(ds, MAX);
    InDanhSach(ds, MAX);

    return 0;
}
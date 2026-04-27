#include <iostream>
using namespace std;

struct ToaDo
{
    int x, y;
};

struct NgayThang
{
    int Ngay, Thang, Nam;
};

struct ThiSinh
{
    long SoBD;
    string HoTen;
    string DiaChi;
    float Toan, Ly, Hoa;
};

int main(int argc, char const *argv[])
{
    ToaDo A;
    A.x = 100;
    A.y = 200;
    cout << "=== TOA DO ===\n";
    cout << "Diem A(" << A.x << ", " << A.y << ")\n\n";

    NgayThang now = {4, 1, 2025};
    cout << "=== NGAY THANG ===\n";
    cout << "Hom nay: " << now.Ngay << "/" << now.Thang << "/" << now.Nam << "\n\n";

    ThiSinh nam;
    nam.SoBD = 1000;
    nam.HoTen = "Vu Van Nam";
    nam.DiaChi = "Ha Noi";
    nam.Toan = 9.0f;
    nam.Ly = 8.0f;
    nam.Hoa = 7.0f;

    cout << "=== THI SINH ===\n";
    cout << "So BD: " << nam.SoBD << "\n";
    cout << "Ho ten: " << nam.HoTen << "\n";
    cout << "Dia chi: " << nam.DiaChi << "\n";
    cout << "Toan: " << nam.Toan << "\n";
    cout << "Ly: " << nam.Ly << "\n";
    cout << "Hoa: " << nam.Hoa << "\n";

    return 0;
}
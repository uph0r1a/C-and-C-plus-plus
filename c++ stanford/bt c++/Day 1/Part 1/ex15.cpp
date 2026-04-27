#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    auto nhapChuSo = [](const string &lbl)
    {
        int x;
        do
        {
            cout << lbl;
            cin >> x;
        } while (x < 0 || x > 9);
        return x;
    };

    a = nhapChuSo("Nhap chu so thu 1 (0-9): ");
    b = nhapChuSo("Nhap chu so thu 2 (0-9): ");
    c = nhapChuSo("Nhap chu so thu 3 (0-9): ");
    d = nhapChuSo("Nhap chu so thu 4 (0-9): ");

    int tong = a + b + c + d;
    cout << "Tong = " << tong << "\n";
    cout << "Hang chuc = " << (tong / 10) % 10 << "\n";
    cout << "Hang don vi = " << tong % 10 << "\n";
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double soThuc;
    int soNguyen;
    long soNguyenDai;
    char kyTu;

    cout << "Nhap so thuc: ";
    cin >> soThuc;
    cout << "Nhap so nguyen: ";
    cin >> soNguyen;
    cout << "Nhap so nguyen dai: ";
    cin >> soNguyenDai;
    cout << "Nhap ky tu: ";
    cin >> kyTu;

    cout << "\nKet qua:\n";
    cout << "  So thuc = " << fixed << setprecision(6) << soThuc << "\n";
    cout << "  So nguyen = " << soNguyen << "\n";
    cout << "  So nguyen dai = " << soNguyenDai << "\n";
    cout << "  Ky tu = " << kyTu << "\n";

    return 0;
}

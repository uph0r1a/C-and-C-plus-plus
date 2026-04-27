#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float soThuc = 0;
    int soNguyen = 0;
    long soNguyenDai = 0;
    char kiTu;

    cout << "Nhap so thuc: ";
    cin >> soThuc;

    cout << "Nhap so nguyen: ";
    cin >> soNguyen;

    cout << "Nhap so nguyen dai: ";
    cin >> soNguyenDai;

    cin.ignore(1);

    cout << "Nhap ki tu: ";
    cin.get(kiTu);

    cout << fixed << setprecision(2);
    cout << "\n--- Ket qua ---" << endl;
    cout << "So thuc: " << soThuc << endl;
    cout << "So nguyen: " << soNguyen << endl;
    cout << "So nguyen dai: " << soNguyenDai << endl;
    cout << "Ki tu: " << kiTu << endl;

    return 0;
}

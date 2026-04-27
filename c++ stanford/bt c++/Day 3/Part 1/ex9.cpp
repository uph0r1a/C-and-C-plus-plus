#include <iostream>
#include <string>
using namespace std;

string thapPhanSangNhiPhan(int n)
{
    if (n == 0)
        return "0";

    string ketQua = "";
    while (n > 0)
    {
        ketQua = (char)('0' + n % 2) + ketQua;
        n /= 2;
    }
    return ketQua;
}

void hienThiTungBuoc(int n)
{
    if (n == 0)
    {
        cout << "0 % 2 = 0  du 0" << endl;
        return;
    }

    cout << "Cac buoc chia:" << endl;
    int temp = n;
    while (temp > 0)
    {
        cout << "  " << temp << " / 2 = " << temp / 2 << "  du " << temp % 2 << endl;
        temp /= 2;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so nguyen duong (>= 0): ";
        cin >> n;
        if (n < 0)
            cout << "Chi chap nhan so khong am. Nhap lai." << endl;
    } while (n < 0);

    cout << "\nChuyen doi " << n << " sang nhi phan:" << endl;
    hienThiTungBuoc(n);

    string ketQua = thapPhanSangNhiPhan(n);
    cout << "\nKet qua: " << n << " (thap phan) = " << ketQua << " (nhi phan)" << endl;

    int kiemTra = 0;
    for (char bit : ketQua)
        kiemTra = kiemTra * 2 + (bit - '0');
    cout << "Kiem tra nguoc: " << ketQua << " -> " << kiemTra << endl;

    return 0;
}

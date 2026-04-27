#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string thapPhanSangNhiPhan(int so)
{
    if (so == 0)
        return "0";
    string ket = "";
    while (so > 0)
    {
        ket = (char)('0' + so % 2) + ket;
        so /= 2;
    }
    return ket;
}

int nhiPhanSangThapPhan(const string &soNhiPhan)
{
    int ket = 0;
    int len = (int)soNhiPhan.length();
    for (int i = 0; i < len; i++)
    {
        if (soNhiPhan[i] == '1')
            ket += (int)pow(2, len - i - 1);
    }
    return ket;
}

int main(int argc, char const *argv[])
{
    int so = 0;
    cout << "Nhap so thap phan can chuyen sang nhi phan: ";
    cin >> so;
    cout << so << "(thap phan) = " << thapPhanSangNhiPhan(so) << " (nhi phan)\n\n";

    string soNhiPhan;
    cout << "Nhap so nhi phan can chuyen sang thap phan: ";
    cin >> soNhiPhan;
    cout << soNhiPhan << "(nhi phan) = " << nhiPhanSangThapPhan(soNhiPhan) << " (thap phan)\n";

    return 0;
}

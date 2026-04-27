#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned short tuoiNguoi = 20;
    unsigned int soLuongCay = 10000;
    float canhTamGiac = 24.5665f;
    double khoangCach = 5464646546.5675;
    char chuSo = '9';
    float x = 12.3454f;

    char chuCai = 'A';
    float delta = 25.56765f;

    cout << fixed << setprecision(2);

    cout << "Tuoi nguoi: " << tuoiNguoi << endl;
    cout << "So luong cay: " << soLuongCay << endl;
    cout << "Canh tam giac: " << canhTamGiac << endl;
    cout << "Khoang cach (km): " << khoangCach << endl;
    cout << "Chu so: " << chuSo << endl;
    cout << "Nghiem x: " << x << endl;
    cout << "Chu cai: " << chuCai << endl;
    cout << "Biet thuc delta: " << delta << endl;

    return 0;
}
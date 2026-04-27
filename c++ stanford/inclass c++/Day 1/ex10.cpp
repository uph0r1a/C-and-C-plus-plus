#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const double PI = 3.14159265358979;

    cout << fixed << setprecision(2);

    double canh = 0;
    cout << "\n[Hinh vuong]" << endl;
    cout << "Nhap do dai canh: ";
    cin >> canh;

    cout << "Chu vi = " << 4 * canh << endl;
    cout << "Dien tich = " << canh * canh << endl;

    double dai = 0, rong = 0;
    cout << "\n[Hinh chu nhat]" << endl;
    cout << "Nhap chieu dai: ";
    cin >> dai;
    cout << "Nhap chieu rong: ";
    cin >> rong;

    cout << "Chu vi = " << 2 * (dai + rong) << endl;
    cout << "Dien tich = " << dai * rong << endl;

    double r = 0;
    cout << "\n[Hinh tron]" << endl;
    cout << "Nhap ban kinh r: ";
    cin >> r;

    cout << "Chu vi = " << 2 * PI * r << endl;
    cout << "Dien tich = " << PI * r * r << endl;

    return 0;
}

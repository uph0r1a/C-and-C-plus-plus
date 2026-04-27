#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);

double dienTichHinhVuong(double R)
{
    return 4.0 * R * R;
}

double dienTichHinhTron(double R)
{
    return PI * R * R;
}

double dienTichGioiHan(double R)
{
    return dienTichHinhVuong(R) - dienTichHinhTron(R);
}

int main(int argc, char const *argv[])
{
    cout << "Hinh vuong ngoai tiep duong tron ban kinh R (canh = 2R)" << endl;

    double R;
    do
    {
        cout << "Nhap ban kinh R (R > 0): ";
        cin >> R;
        if (R <= 0)
            cout << "Ban kinh phai lon hon 0! Vui long nhap lai." << endl;
    } while (R <= 0);

    cout << fixed << setprecision(6);
    cout << "\nBan kinh R = " << R << endl;
    cout << "Canh hinh vuong (2R) = " << 2 * R << endl;
    cout << "Dien tich hinh vuong = " << dienTichHinhVuong(R) << endl;
    cout << "Dien tich hinh tron = " << dienTichHinhTron(R) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Dien tich gioi han (4 goc) = " << dienTichGioiHan(R) << endl;
    cout << "Ti le phan gioi han / hinh vuong = "
         << (dienTichGioiHan(R) / dienTichHinhVuong(R)) * 100 << "%" << endl;

    return 0;
}

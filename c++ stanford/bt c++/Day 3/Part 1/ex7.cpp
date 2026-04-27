#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct KetQua
{
    float delta;
    int soNghiem;
    float x1, x2;
};

KetQua giaiPhuongTrinhBac2(float a, float b, float c)
{
    KetQua kq = {};

    if (a == 0)
    {
        if (b == 0)
        {
            kq.soNghiem = (c == 0) ? -1 : 0;
        }
        else
        {
            kq.soNghiem = 1;
            kq.x1 = -c / b;
        }
        return kq;
    }

    kq.delta = b * b - 4 * a * c;

    if (kq.delta < 0)
    {
        kq.soNghiem = 0;
    }
    else if (kq.delta == 0)
    {
        kq.soNghiem = 1;
        kq.x1 = -b / (2 * a);
    }
    else
    {
        kq.soNghiem = 2;
        kq.x1 = (-b + sqrt(kq.delta)) / (2 * a);
        kq.x2 = (-b - sqrt(kq.delta)) / (2 * a);
    }

    return kq;
}

void hienThiKetQua(float a, float b, float c, const KetQua &kq)
{
    cout << fixed << setprecision(4);
    cout << "\nPhuong trinh: ";
    if (a != 0)
        cout << a << "x^2 + ";
    cout << b << "x + " << c << " = 0" << endl;

    if (a != 0)
        cout << "Delta = " << kq.delta << endl;

    switch (kq.soNghiem)
    {
    case -1:
        cout << "Phuong trinh co vo so nghiem." << endl;
        break;
    case 0:
        cout << "Phuong trinh vo nghiem." << endl;
        break;
    case 1:
        if (a != 0)
            cout << "Phuong trinh co nghiem kep: x = " << kq.x1 << endl;
        else
            cout << "Phuong trinh bac nhat co nghiem: x = " << kq.x1 << endl;
        break;
    case 2:
        cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
        cout << "x1 = " << kq.x1 << endl;
        cout << "x2 = " << kq.x2 << endl;
        break;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Dang: ax^2 + bx + c = 0" << endl;

    char tiepTuc;
    do
    {
        float a, b, c;
        cout << "\nNhap he so a: ";
        cin >> a;
        cout << "Nhap he so b: ";
        cin >> b;
        cout << "Nhap he so c: ";
        cin >> c;

        KetQua kq = giaiPhuongTrinhBac2(a, b, c);
        hienThiKetQua(a, b, c, kq);

        cout << "\nTiep tuc? (y/n): ";
        cin >> tiepTuc;
    } while (tiepTuc == 'y' || tiepTuc == 'Y');

    return 0;
}

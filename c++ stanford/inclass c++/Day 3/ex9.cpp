#include <iostream>
#include <string>
using namespace std;

void inThongTin()
{
    cout << "Hom nay troi dep qua!\n";
}

void inThongTin(int n)
{
    for (int i = 1; i <= n; i++)
        cout << "Hom nay troi dep qua - " << i << "\n";
}

string LayTenCongTy()
{
    return "Stanford - Day kinh nghiem lap trinh";
}

int TongHaiSo(int a, int b)
{
    return a + b;
}

float TongHaiSo(float a, float b)
{
    return a + b;
}

void HoanDoi(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void HoanDoi(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main(int argc, char const *argv[])
{
    cout << "=== DANG 1 & 2 ===\n";
    inThongTin();
    inThongTin(3);

    cout << "\n=== DANG 3 ===\n";
    cout << LayTenCongTy() << "\n";

    cout << "\n=== DANG 4 (OVERLOADING) ===\n";
    int xi = 4, yi = 7;
    float xf = 1.5f, yf = 2.5f;
    cout << "Tong int: " << TongHaiSo(xi, yi) << "\n";
    cout << "Tong float: " << TongHaiSo(xf, yf) << "\n";

    cout << "\n=== HOAN DOI BANG THAM CHIEU ===\n";
    int a = 10, b = 20;
    cout << "Truoc: a = " << a << " b = " << b << "\n";
    HoanDoi(a, b);
    cout << "Sau: a = " << a << " b = " << b << "\n";

    cout << "\n=== HOAN DOI BANG CON TRO ===\n";
    HoanDoi(&a, &b);
    cout << "Sau lan 2: a = " << a << " b = " << b << "\n";

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

class HinhTron
{
private:
    static const double PI = 3.14159265358979;
    double r;

public:
    HinhTron()
        : r(0.0) {}

    explicit HinhTron(double banKinh)
        : r(banKinh > 0 ? banKinh : 0.0) {}

    double getBanKinh() const
    {
        return r;
    }

    void setBanKinh(double banKinh)
    {
        if (banKinh <= 0)
        {
            cout << "Ban kinh phai > 0. Giu nguyen gia tri cu.\n";
            return;
        }
        r = banKinh;
    }

    double chuVi() const
    {
        return 2 * PI * r;
    }

    double dienTich() const
    {
        return PI * r * r;
    }

    void inThongTin() const
    {
        cout << "Ban kink: " << r << "\n";
        cout << "Chu vi: " << chuVi() << "\n";
        cout << "Dien tich: " << dienTich() << "\n";
    }

    friend ostream &operator<<(ostream &os, const HinhTron &ht)
    {
        os << "HinhTron(r=" << ht.r
           << ", C=" << ht.chuVi()
           << ", S=" << ht.dienTich() << ")";
        return os;
    }
};

class TinhToan
{
private:
    int a;

public:
    int b;

    TinhToan()
        : a(5),
          b(10)
    {
        cout << "[TinhToan] Doi tuong duoc tao ra. a = " << a << "\n";
    }

    ~TinhToan()
    {
        cout << "[TinhToan] Ham huy duoc goi.\n";
    }

    int getA() const
    {
        return a;
    }

    void InThongTin() const
    {
        cout << "Lop va doi tuong trong C++\n";
    }

    void InThongTin(int n) const
    {
        for (int i = 1; i <= n; i++)
            cout << "I love you - " << i << "\n";
    }

    int TongHaiSo(int x, int y) const
    {
        return x + y;
    }

    int HieuHaiSo(int x, int y) const
    {
        return x - y;
    }

    int TichHaiSo(int x, int y) const
    {
        return x * y;
    }

    string LayTenCongTy() const
    {
        return "Stanford - Day lap trinh";
    }
};

int main(int argc, char const *argv[])
{
    cout << fixed << setprecision(4);

    cout << "===== LOC TINHTOAN =====\n";
    TinhToan tt;

    tt.InThongTin();
    tt.InThongTin(3);

    int x = 0, y = 0;
    cout << "\nNhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;

    cout << "Tong (" << x << " + " << y << ") = " << tt.TongHaiSo(x, y) << "\n";
    cout << "Hieu (" << x << " - " << y << ") = " << tt.HieuHaiSo(x, y) << "\n";
    cout << "Ten cong ty: " << tt.LayTenCongTy() << "\n";
    cout << "b = " << tt.b << ",  a = " << tt.getA() << "\n";

    cout << "\n===== LOC HINHTRON =====\n";

    double r = 0;
    cout << "Nhap ban kinh r: ";
    cin >> r;

    HinhTron ht1(r);
    cout << "\n[ht1 - constructor(r)]\n";
    ht1.inThongTin();
    cout << ht1 << "\n";

    HinhTron ht2;
    ht2.setBanKinh(r);
    cout << "\n[ht2 - default + setBanKinh]\n";
    ht2.inThongTin();

    cout << "\n[Thu set ban kinh = -5]\n";
    HinhTron ht3;
    ht3.setBanKinh(-5);
    ht3.inThongTin();

    return 0;
}

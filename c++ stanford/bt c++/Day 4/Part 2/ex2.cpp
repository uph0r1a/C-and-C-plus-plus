#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace std;

class PhanSo
{
private:
    long long tu;
    long long mau;

    static long long gcd(long long a, long long b)
    {
        a = abs(a);
        b = abs(b);
        while (b)
        {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a == 0 ? 1 : a;
    }

    void normalize()
    {
        if (mau == 0)
            throw invalid_argument("Mau so khong the bang 0");
        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
        long long g = gcd(abs(tu), mau);
        tu /= g;
        mau /= g;
    }

public:
    PhanSo(long long tu = 0, long long mau = 1)
        : tu(tu),
          mau(mau)
    {
        normalize();
    }

    long long getTu() const
    {
        return tu;
    }

    long long getMau() const
    {
        return mau;
    }

    void nhap()
    {
        long long t, m;
        while (true)
        {
            cout << "Nhap tu so  : ";
            cin >> t;
            cout << "Nhap mau so : ";
            cin >> m;
            if (m != 0)
            {
                tu = t;
                mau = m;
                normalize();
                break;
            }
            cout << "[!] Mau so khong duoc bang 0. Nhap lai.\n";
        }
    }

    void in() const
    {
        if (mau == 1)
            cout << tu;
        else
            cout << tu << "/" << mau;
    }

    string toString() const
    {
        if (mau == 1)
            return to_string(tu);
        return to_string(tu) + "/" + to_string(mau);
    }

    PhanSo cong(const PhanSo &other) const
    {
        return PhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
    }

    PhanSo tru(const PhanSo &other) const
    {
        return PhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
    }

    PhanSo nhan(const PhanSo &other) const
    {
        return PhanSo(tu * other.tu, mau * other.mau);
    }

    PhanSo chia(const PhanSo &other) const
    {
        if (other.tu == 0)
            throw invalid_argument("Khong the chia cho 0");
        return PhanSo(tu * other.mau, mau * other.tu);
    }

    PhanSo operator+(const PhanSo &o) const
    {
        return cong(o);
    }

    PhanSo operator-(const PhanSo &o) const
    {
        return tru(o);
    }

    PhanSo operator*(const PhanSo &o) const
    {
        return nhan(o);
    }

    PhanSo operator/(const PhanSo &o) const
    {
        return chia(o);
    }

    bool operator==(const PhanSo &o) const
    {
        return tu == o.tu && mau == o.mau;
    }

    PhanSo rutGon() const
    {
        return *this;
    }

    double toDouble() const
    {
        return (double)tu / mau;
    }
};

static void inPhepTinh(const PhanSo &a, const string &op, const PhanSo &b)
{
    PhanSo result;
    try
    {
        if (op == "+")
            result = a + b;
        else if (op == "-")
            result = a - b;
        else if (op == "*")
            result = a * b;
        else if (op == "/")
            result = a / b;
    }
    catch (const invalid_argument &e)
    {
        cout << "Loi: " << e.what() << "\n";
        return;
    }
    cout << a.toString() << " " << op << " " << b.toString()
         << " = " << result.toString()
         << " (~" << result.toDouble() << ")\n";
}

int main(int argc, char const *argv[])
{
    cout << "Nhap phan so thu nhat:\n";
    PhanSo p1;
    p1.nhap();

    cout << "Nhap phan so thu hai:\n";
    PhanSo p2;
    p2.nhap();

    cout << "\nPhan so 1 : ";
    p1.in();
    cout << "\nPhan so 2 : ";
    p2.in();
    cout << "\n\n";

    cout << "  P1 rut gon: ";
    p1.rutGon().in();
    cout << "\n  P2 rut gon: ";
    p2.rutGon().in();
    cout << "\n  (Phan so luon duoc rut gon ngay khi tao)\n\n";

    inPhepTinh(p1, "+", p2);
    inPhepTinh(p1, "-", p2);
    inPhepTinh(p1, "*", p2);
    inPhepTinh(p1, "/", p2);
    cout << "\n";

    PhanSo a(3, 4), b(2, 6);
    cout << "  a = ";
    a.in();
    cout << ",  b = ";
    b.in();
    cout << "\n";
    inPhepTinh(a, "+", b);
    inPhepTinh(a, "-", b);
    inPhepTinh(a, "*", b);
    inPhepTinh(a, "/", b);

    cout << "\n  Chia cho 0:\n";
    inPhepTinh(a, "/", PhanSo(0, 1));

    cout << "\n  So am: (-3)/4 + 1/4 = ";
    (PhanSo(-3, 4) + PhanSo(1, 4)).in();
    cout << "\n";

    return 0;
}
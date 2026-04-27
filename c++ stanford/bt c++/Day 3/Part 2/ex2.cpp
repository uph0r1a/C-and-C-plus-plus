#include <iostream>
#include <stdexcept>
using namespace std;

int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a == 0 ? 1 : a;
}

struct PhanSo
{
    int tu;
    int mau;

    static PhanSo tao(int t, int m)
    {
        if (m == 0)
            throw invalid_argument("Mau so khong duoc bang 0.");
        int g = ucln(abs(t), abs(m));
        if (m < 0)
        {
            t = -t;
            m = -m;
        }
        return {t / g, m / g};
    }

    void nhap()
    {
        cout << "Tu so: ";
        cin >> tu;
        int m;
        do
        {
            cout << "Mau so: ";
            cin >> m;
            if (m == 0)
                cout << "Mau so phai khac 0!\n";
        } while (m == 0);
        *this = tao(tu, m);
    }

    void hienThi(const string &nhan = "") const
    {
        if (!nhan.empty())
            cout << nhan << " = ";
        if (mau == 1)
            cout << tu;
        else
            cout << tu << "/" << mau;
        cout << endl;
    }

    void rutGon()
    {
        *this = tao(tu, mau);
    }
};

PhanSo cong(PhanSo a, PhanSo b)
{
    return PhanSo::tao(a.tu * b.mau + b.tu * a.mau, a.mau * b.mau);
}

PhanSo tru(PhanSo a, PhanSo b)
{
    return PhanSo::tao(a.tu * b.mau - b.tu * a.mau, a.mau * b.mau);
}

PhanSo nhan(PhanSo a, PhanSo b)
{
    return PhanSo::tao(a.tu * b.tu, a.mau * b.mau);
}

PhanSo chia(PhanSo a, PhanSo b)
{
    if (b.tu == 0)
        throw invalid_argument("Khong the chia cho phan so bang 0.");
    return PhanSo::tao(a.tu * b.mau, a.mau * b.tu);
}

void nhapHai(PhanSo &ps1, PhanSo &ps2)
{
    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();
    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();
}

void menu()
{
    cout << "\n========================================\n";
    cout << "         XU LY PHAN SO\n";
    cout << "========================================\n";
    cout << "1. Nhap va hien thi phan so\n";
    cout << "2. Cong hai phan so\n";
    cout << "3. Tru hai phan so\n";
    cout << "4. Nhan hai phan so\n";
    cout << "5. Chia hai phan so\n";
    cout << "6. Rut gon mot phan so\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

int main(int argc, char const *argv[])
{
    PhanSo ps1{}, ps2{}, kq{};
    int lua;

    do
    {
        menu();
        cin >> lua;
        cout << endl;

        try
        {
            switch (lua)
            {
            case 1:
                cout << "Nhap phan so:\n";
                ps1.nhap();
                ps1.hienThi("Phan so");
                break;
            case 2:
                nhapHai(ps1, ps2);
                kq = cong(ps1, ps2);
                ps1.hienThi("ps1");
                ps2.hienThi("ps2");
                kq.hienThi("ps1 + ps2");
                break;
            case 3:
                nhapHai(ps1, ps2);
                kq = tru(ps1, ps2);
                ps1.hienThi("ps1");
                ps2.hienThi("ps2");
                kq.hienThi("ps1 - ps2");
                break;
            case 4:
                nhapHai(ps1, ps2);
                kq = nhan(ps1, ps2);
                ps1.hienThi("ps1");
                ps2.hienThi("ps2");
                kq.hienThi("ps1 * ps2");
                break;
            case 5:
                nhapHai(ps1, ps2);
                kq = chia(ps1, ps2);
                ps1.hienThi("ps1");
                ps2.hienThi("ps2");
                kq.hienThi("ps1 / ps2");
                break;
            case 6:
                cout << "Nhap phan so can rut gon:\n";
                ps1.nhap();
                ps1.hienThi("Truoc rut gon");
                ps1.rutGon();
                ps1.hienThi("Sau rut gon ");
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
            }
        }
        catch (const exception &e)
        {
            cout << "Loi: " << e.what() << endl;
        }
    } while (lua != 0);

    return 0;
}

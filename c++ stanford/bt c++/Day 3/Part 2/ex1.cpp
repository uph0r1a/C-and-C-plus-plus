#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct SoPhuc
{
    double thuc;
    double ao;

    void nhap(const string &tenBien = "")
    {
        if (!tenBien.empty())
            cout << "Nhap so phuc " << tenBien << ":\n";
        cout << "Phan thuc = ";
        cin >> thuc;
        cout << "Phan ao = ";
        cin >> ao;
    }

    void hienThi(const string &nhanDe = "So phuc") const
    {
        cout << nhanDe << ": " << fixed << setprecision(4) << thuc;
        if (ao >= 0)
            cout << " + " << ao << "i";
        else
            cout << " - " << -ao << "i";
        cout << endl;
    }

    double modul() const
    {
        return sqrt(thuc * thuc + ao * ao);
    }

    SoPhuc lienHop() const
    {
        return {thuc, -ao};
    }
};

SoPhuc cong(SoPhuc a, SoPhuc b)
{
    return {a.thuc + b.thuc, a.ao + b.ao};
}

SoPhuc tru(SoPhuc a, SoPhuc b)
{
    return {a.thuc - b.thuc, a.ao - b.ao};
}

SoPhuc nhan(SoPhuc a, SoPhuc b)
{
    return {a.thuc * b.thuc - a.ao * b.ao,
            a.thuc * b.ao + a.ao * b.thuc};
}

SoPhuc chia(SoPhuc a, SoPhuc b)
{
    double mau = b.thuc * b.thuc + b.ao * b.ao;
    if (mau == 0.0)
    {
        cout << "Loi: Chia cho so phuc bang 0!\n";
        return {0, 0};
    }
    return {(a.thuc * b.thuc + a.ao * b.ao) / mau,
            (a.ao * b.thuc - a.thuc * b.ao) / mau};
}

SoPhuc binhPhuong(SoPhuc a)
{
    return nhan(a, a);
}

void menu()
{
    cout << "\n========================================\n";
    cout << "       XU LY SO PHUC\n";
    cout << "========================================\n";
    cout << "1. Nhap va hien thi so phuc\n";
    cout << "2. Cong hai so phuc\n";
    cout << "3. Tru hai so phuc\n";
    cout << "4. Nhan hai so phuc\n";
    cout << "5. Chia hai so phuc\n";
    cout << "6. Binh phuong mot so phuc\n";
    cout << "7. Modul va lien hop\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

int main(int argc, char const *argv[])
{
    SoPhuc sp1, sp2, kq;
    int lua;

    do
    {
        menu();
        cin >> lua;
        cout << endl;

        switch (lua)
        {
        case 1:
            sp1.nhap("z");
            sp1.hienThi();
            break;
        case 2:
            sp1.nhap("z1");
            sp2.nhap("z2");
            kq = cong(sp1, sp2);
            sp1.hienThi("z1");
            sp2.hienThi("z2");
            kq.hienThi("z1 + z2");
            break;
        case 3:
            sp1.nhap("z1");
            sp2.nhap("z2");
            kq = tru(sp1, sp2);
            sp1.hienThi("z1");
            sp2.hienThi("z2");
            kq.hienThi("z1 - z2");
            break;
        case 4:
            sp1.nhap("z1");
            sp2.nhap("z2");
            kq = nhan(sp1, sp2);
            sp1.hienThi("z1");
            sp2.hienThi("z2");
            kq.hienThi("z1 * z2");
            break;
        case 5:
            sp1.nhap("z1");
            sp2.nhap("z2");
            kq = chia(sp1, sp2);
            sp1.hienThi("z1");
            sp2.hienThi("z2");
            kq.hienThi("z1 / z2");
            break;
        case 6:
            sp1.nhap("z");
            kq = binhPhuong(sp1);
            sp1.hienThi("z");
            kq.hienThi("z^2");
            break;
        case 7:
            sp1.nhap("z");
            sp1.hienThi("z");
            cout << fixed << setprecision(4);
            cout << "  |z|  = " << sp1.modul() << endl;
            sp1.lienHop().hienThi("  Lien hop");
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (lua != 0);

    return 0;
}

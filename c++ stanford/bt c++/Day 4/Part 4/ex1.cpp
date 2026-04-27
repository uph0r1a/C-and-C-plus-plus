#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class KySu
{
private:
    string hoTen;
    string ngaySinh;
    string queQuan;
    string nganhHoc;
    int namTotNghiep;

    static string readStr(const string &prompt)
    {
        string s;
        cout << prompt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, s);
        return s;
    }
    static string readStrNoIgnore(const string &prompt)
    {
        string s;
        cout << prompt;
        getline(cin, s);
        return s;
    }
    static int readInt(const string &prompt, int lo, int hi)
    {
        int v;
        while (true)
        {
            cout << prompt;
            if (cin >> v && v >= lo && v <= hi)
                return v;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Gia tri phai trong [" << lo << ", " << hi << "]\n";
        }
    }

public:
    KySu()
        : namTotNghiep(0) {}

    void nhap()
    {
        hoTen = readStr("Ho ten: ");
        ngaySinh = readStrNoIgnore("Ngay sinh (DD/MM/YYYY): ");
        queQuan = readStrNoIgnore("Que quan: ");
        nganhHoc = readStrNoIgnore("Nganh hoc: ");
        namTotNghiep = readInt("Nam tot nghiep: ", 1900, 2100);
    }

    void inRa() const
    {
        cout << left
             << setw(22) << hoTen
             << setw(14) << ngaySinh
             << setw(18) << queQuan
             << setw(20) << nganhHoc
             << setw(6) << namTotNghiep
             << "\n";
    }

    int getNamTotNghiep() const
    {
        return namTotNghiep;
    }

    string getHoTen() const
    {
        return hoTen;
    }
};

static void printHeader()
{
    cout << "\n"
         << string(82, '-') << "\n"
         << left
         << setw(22) << "Ho ten"
         << setw(14) << "Ngay sinh"
         << setw(18) << "Que quan"
         << setw(20) << "Nganh hoc"
         << setw(6) << "Nam TN"
         << "\n"
         << string(82, '-') << "\n";
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so luong ky su (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<KySu> ds(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nKy su thu " << (i + 1) << ":\n";
        ds[i].nhap();
    }

    cout << "\n===== DANH SACH KY SU =====";
    printHeader();
    for (const auto &ks : ds)
        ks.inRa();

    auto best = max_element(ds.begin(), ds.end(),
                            [](const KySu &a, const KySu &b)
                            {
                                return a.getNamTotNghiep() < b.getNamTotNghiep();
                            });

    cout << "\n===== KY SU TOT NGHIEP GAN NHAT (nam "
         << best->getNamTotNghiep() << ") =====";
    printHeader();
    for (const auto &ks : ds)
        if (ks.getNamTotNghiep() == best->getNamTotNghiep())
            ks.inRa();

    return 0;
}
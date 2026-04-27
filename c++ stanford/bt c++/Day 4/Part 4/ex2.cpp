#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;

class SinhVien
{
private:
    string maSV;
    string hoTen;
    string lop;
    double d1, d2, d3;

    static double readDiem(const string &prompt)
    {
        double v;
        while (true)
        {
            cout << prompt;
            if (cin >> v && v >= 0 && v <= 10)
                return v;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Diem phai trong [0, 10]\n";
        }
    }

public:
    SinhVien()
        : d1(0),
          d2(0),
          d3(0) {}

    void nhap()
    {
        cout << "Ma SV: ";
        cin >> maSV;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ho ten: ";
        getline(cin, hoTen);
        cout << "Lop: ";
        getline(cin, lop);
        d1 = readDiem("Diem mon 1 (0-10): ");
        d2 = readDiem("Diem mon 2 (0-10): ");
        d3 = readDiem("Diem mon 3 (0-10): ");
    }

    void inRa() const
    {
        cout << left
             << setw(10) << maSV
             << setw(22) << hoTen
             << setw(10) << lop
             << setw(7) << fixed << setprecision(1) << d1
             << setw(7) << d2
             << setw(7) << d3
             << setw(7) << diemTB()
             << "\n";
    }

    string getMaSV() const
    {
        return maSV;
    }

    string getLop() const
    {
        return lop;
    }

    double getDiem1() const
    {
        return d1;
    }

    double getDiem2() const
    {
        return d2;
    }

    double getDiem3() const
    {
        return d3;
    }

    double diemTB() const
    {
        return (d1 + d2 + d3) / 3.0;
    }

    bool datYeuCau() const
    {
        return d1 >= 5 && d2 >= 5 && d3 >= 5;
    }
};

static void printHeader()
{
    cout << "\n"
         << string(72, '-') << "\n"
         << left
         << setw(10) << "Ma SV"
         << setw(22) << "Ho ten"
         << setw(10) << "Lop"
         << setw(7) << "Mon 1"
         << setw(7) << "Mon 2"
         << setw(7) << "Mon 3"
         << setw(7) << "DTB"
         << "\n"
         << string(72, '-') << "\n";
}
static void printList(const vector<SinhVien> &v)
{
    printHeader();
    for (const auto &sv : v)
        sv.inRa();
    if (v.empty())
        cout << "(Khong co sinh vien nao)\n";
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so sinh vien (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<SinhVien> ds(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nSinh vien thu " << (i + 1) << ":\n";
        ds[i].nhap();
    }

    cout << "\n===== DANH SACH SINH VIEN =====";
    printList(ds);

    cout << "\n===== TIM THEO MA SINH VIEN =====\n";
    string ma;
    cout << "Nhap ma SV can tim: ";
    cin >> ma;
    vector<SinhVien> kqMa;
    for (const auto &sv : ds)
        if (sv.getMaSV() == ma)
            kqMa.push_back(sv);
    printList(kqMa);

    cout << "\n===== TIM TAT CA SV THEO LOP =====\n";
    string lopTim;
    cout << "Nhap ten lop: ";
    cin >> lopTim;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<SinhVien> kqLop;
    for (const auto &sv : ds)
        if (sv.getLop() == lopTim)
            kqLop.push_back(sv);
    cout << "Lop " << lopTim << " co " << kqLop.size() << " sinh vien:";
    printList(kqLop);

    cout << "\n===== SINH VIEN KHONG THI LAI =====";
    vector<SinhVien> kqDat;
    for (const auto &sv : ds)
        if (sv.datYeuCau())
            kqDat.push_back(sv);
    printList(kqDat);

    cout << "\n===== TOP 3 DIEM CAO NHAT =====";
    vector<SinhVien> sorted = ds;
    sort(sorted.begin(), sorted.end(),
         [](const SinhVien &a, const SinhVien &b)
         { return a.diemTB() > b.diemTB(); });
    int top = min(3, (int)sorted.size());
    vector<SinhVien> kqTop(sorted.begin(), sorted.begin() + top);
    printList(kqTop);

    return 0;
}
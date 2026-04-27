#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
using namespace std;

class Sach
{
private:
    string maSach;
    string tenSach;
    string theLoai;
    int soLuong;
    string tacGia;

    static int readInt(const string &prompt, int lo)
    {
        int v;
        while (true)
        {
            cout << prompt;
            if (cin >> v && v >= lo)
                return v;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Gia tri phai >= " << lo << "\n";
        }
    }

public:
    Sach()
        : soLuong(0) {}

    void nhap()
    {
        cout << "Ma sach: ";
        cin >> maSach;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ten sach: ";
        getline(cin, tenSach);
        cout << "The loai: ";
        getline(cin, theLoai);
        cout << "Tac gia: ";
        getline(cin, tacGia);
        soLuong = readInt("So luong: ", 0);
    }

    void inRa() const
    {
        cout << left
             << setw(10) << maSach
             << setw(28) << tenSach
             << setw(16) << theLoai
             << setw(20) << tacGia
             << setw(6) << soLuong
             << "\n";
    }

    static bool containsCI(const string &hay, const string &needle)
    {
        string h = hay, n = needle;
        transform(h.begin(), h.end(), h.begin(), ::tolower);
        transform(n.begin(), n.end(), n.begin(), ::tolower);
        return h.find(n) != string::npos;
    }

    bool matchMa(const string &q) const
    {
        return containsCI(maSach, q);
    }

    bool matchTen(const string &q) const
    {
        return containsCI(tenSach, q);
    }

    bool matchTheLoai(const string &q) const
    {
        return containsCI(theLoai, q);
    }

    bool matchTacGia(const string &q) const
    {
        return containsCI(tacGia, q);
    }
};

static void printHeader()
{
    cout << "\n"
         << string(82, '-') << "\n"
         << left
         << setw(10) << "Ma sach"
         << setw(28) << "Ten sach"
         << setw(16) << "The loai"
         << setw(20) << "Tac gia"
         << setw(6) << "SL"
         << "\n"
         << string(82, '-') << "\n";
}
static void printList(const vector<Sach> &v, const string &title = "")
{
    if (!title.empty())
        cout << "\n"
             << title;
    printHeader();
    for (const auto &s : v)
        s.inRa();
    if (v.empty())
        cout << "(Khong tim thay sach nao)\n";
    else
        cout << "Tong: " << v.size() << " cuon.\n";
}

static vector<Sach> filter(const vector<Sach> &ds, bool (Sach::*pred)(const string &) const, const string &q)
{
    vector<Sach> res;
    for (const auto &s : ds)
        if ((s.*pred)(q))
            res.push_back(s);
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so luong sach (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<Sach> ds(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nSach thu " << (i + 1) << ":\n";
        ds[i].nhap();
    }

    printList(ds, "===== DANH SACH SACH =====");

    int choice;
    do
    {
        cout << "\n===== TIM KIEM =====\n"
             << "1. Tim theo ma sach\n"
             << "2. Tim theo ten sach\n"
             << "3. Tim theo the loai\n"
             << "4. Tim theo ten tac gia\n"
             << "0. Thoat\n"
             << "Chon: ";
        cin >> choice;
        if (choice == 0)
            break;
        if (choice < 1 || choice > 4)
        {
            cout << "Lua chon khong hop le.\n";
            continue;
        }

        string q;
        cout << "Nhap tu khoa tim kiem: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, q);

        vector<Sach> kq;
        if (choice == 1)
            kq = filter(ds, &Sach::matchMa, q);
        else if (choice == 2)
            kq = filter(ds, &Sach::matchTen, q);
        else if (choice == 3)
            kq = filter(ds, &Sach::matchTheLoai, q);
        else
            kq = filter(ds, &Sach::matchTacGia, q);

        printList(kq, "===== KET QUA TIM KIEM =====");
    } while (true);

    return 0;
}
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int nhapSoNguyen(const string &loi)
{
    int v;
    while (true)
    {
        cout << loi;
        if (cin >> v)
            return v;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Gia tri khong hop le. Nhap lai.\n";
    }
}

void inMang(const vector<int> &a, const string &nhan = "")
{
    if (!nhan.empty())
        cout << nhan << ": ";
    cout << "[ ";
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i];
        if (i < (int)a.size() - 1)
            cout << ", ";
    }
    cout << " ]\n";
}

vector<int> nhapMang()
{
    int n;
    do
    {
        cout << "So phan tu mang (>= 1): ";
        cin >> n;
        if (n < 1)
            cout << "Phai >= 1. Nhap lai.\n";
    } while (n < 1);

    vector<int> a(n);
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++)
        a[i] = nhapSoNguyen("  a[" + to_string(i) + "] = ");
    return a;
}

void timMaxMin(const vector<int> &a)
{
    int idxMax = 0, idxMin = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[i] > a[idxMax])
            idxMax = i;
        if (a[i] < a[idxMin])
            idxMin = i;
    }

    cout << "\n--- Phan tu lon nhat va nho nhat ---\n";
    cout << "Max: gia tri = " << setw(5) << a[idxMax]
         << " tai vi tri [" << idxMax << "]\n";
    cout << "Min: gia tri = " << setw(5) << a[idxMin]
         << " tai vi tri [" << idxMin << "]\n";
}

vector<int> sapXepGiamDan(vector<int> a)
{
    sort(a.begin(), a.end(), greater<int>());
    return a;
}

void top3VaTongChan(const vector<int> &a)
{
    vector<int> sorted = sapXepGiamDan(a);

    cout << "\n--- Top 3 gia tri cao nhat ---\n";
    for (int i = 0; i < min(3, (int)sorted.size()); i++)
        cout << "  [" << i + 1 << "] " << sorted[i] << "\n";

    long long tongChan = 0;
    int demChan = 0;
    for (int x : a)
    {
        if (x % 2 == 0)
        {
            tongChan += x;
            demChan++;
        }
    }
    cout << "\n--- Tong cac so chan ---\n";
    cout << "So phan tu chan: " << demChan << "\n";
    cout << "Tong so chan   : " << tongChan << "\n";
}

void thongKeChuSo5(const vector<int> &a)
{
    int tongLanXuatHien = 0;
    int soPhanTuChua5 = 0;

    cout << "\n--- Thong ke chu so 5 trong day ---\n";
    for (int x : a)
    {
        string s = to_string(abs(x));
        int dem = count(s.begin(), s.end(), '5');
        if (dem > 0)
        {
            cout << "Phan tu " << setw(5) << x
                 << " chua " << dem << " chu so '5'\n";
            tongLanXuatHien += dem;
            soPhanTuChua5++;
        }
    }

    cout << "Tong so chu so '5' xuat hien: " << tongLanXuatHien << " lan\n";
    cout << "So phan tu chua chu so '5': " << soPhanTuChua5 << " phan tu\n";
}

void bai2TachChuoi()
{
    cout << "\n========================================\n";
    cout << "  DE BAI 2: TACH SO TU CHUOI\n";
    cout << "========================================\n";
    cout << "Nhap chuoi cac so cach nhau bang dau phay\n";
    cout << "Chuoi: ";

    cin.ignore(1000, '\n');
    string chuoi;
    getline(cin, chuoi);

    vector<int> soTach;
    stringstream ss(chuoi);
    string token;
    bool loiDinhDang = false;

    while (getline(ss, token, ','))
    {
        size_t start = token.find_first_not_of(" \t");
        size_t end = token.find_last_not_of(" \t");
        if (start == string::npos)
            continue;
        token = token.substr(start, end - start + 1);

        try
        {
            size_t pos;
            int val = stoi(token, &pos);
            if (pos != token.size())
                throw invalid_argument("Chuoi con lai");
            soTach.push_back(val);
        }
        catch (...)
        {
            cout << "Canh bao: Bo qua token khong hop le: \"" << token << "\"\n";
            loiDinhDang = true;
        }
    }

    if (soTach.empty())
    {
        cout << "Khong tim thay so nao hop le trong chuoi.\n";
        return;
    }

    cout << "\nCac so tach duoc (" << soTach.size() << " so):\n  ";
    for (int i = 0; i < (int)soTach.size(); i++)
    {
        cout << soTach[i];
        if (i < (int)soTach.size() - 1)
            cout << " + ";
    }

    long long tong = 0;
    for (int x : soTach)
        tong += x;
    cout << " = " << tong << "\n";
}

int main(int argc, char const *argv[])
{
    cout << "\n=== DE BAI 1: XU LY MANG SO NGUYEN ===\n";
    cout << "\n1. Dung du lieu mau (55,65,10,75,20,45,100,85,95,30)\n";
    cout << "2. Nhap tu ban phim\n";
    cout << "Chon: ";
    int chon;
    cin >> chon;

    vector<int> mang;
    if (chon == 2)
    {
        mang = nhapMang();
    }
    else
    {
        mang = {55, 65, 10, 75, 20, 45, 100, 85, 95, 30};
        cout << "Du lieu mau da duoc tai.\n";
    }

    cout << "\n";
    inMang(mang, "Mang goc");

    timMaxMin(mang);

    vector<int> mangSapXep = sapXepGiamDan(mang);
    cout << "\n--- Sap xep giam dan ---\n";
    inMang(mangSapXep, "Ket qua");

    top3VaTongChan(mang);

    thongKeChuSo5(mang);

    bai2TachChuoi();

    return 0;
}
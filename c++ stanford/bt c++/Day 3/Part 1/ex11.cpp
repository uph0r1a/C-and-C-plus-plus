#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string layTen(const string &hoTen)
{
    size_t pos = hoTen.rfind(' ');
    if (pos == string::npos)
        return hoTen;
    return hoTen.substr(pos + 1);
}

bool soSanhTheoTen(const string &a, const string &b)
{
    string tenA = layTen(a);
    string tenB = layTen(b);
    if (tenA != tenB)
        return tenA < tenB;
    return a < b;
}

void hienThiDanhSach(const vector<string> &ds, const string &tieuDe)
{
    cout << "\n"
         << tieuDe << ":" << endl;
    for (int i = 0; i < (int)ds.size(); i++)
    {
        cout << (i + 1) << ". " << ds[i] << " [Ten: " << layTen(ds[i]) << "]" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so luong ho ten (>= 1): ";
        cin >> n;
        if (n < 1)
            cout << "So luong phai >= 1." << endl;
    } while (n < 1);

    cin.ignore();
    vector<string> danhSach;
    danhSach.reserve(n);

    for (int i = 0; i < n; i++)
    {
        string hoTen;
        cout << "Nhap ho ten thu " << (i + 1) << ": ";
        getline(cin, hoTen);
        // Loại bỏ khoảng trắng đầu/cuối
        while (!hoTen.empty() && hoTen.front() == ' ')
            hoTen.erase(0, 1);
        while (!hoTen.empty() && hoTen.back() == ' ')
            hoTen.pop_back();
        if (!hoTen.empty())
            danhSach.push_back(hoTen);
    }

    hienThiDanhSach(danhSach, "Danh sach TRUOC khi sap xep");

    sort(danhSach.begin(), danhSach.end(), soSanhTheoTen);
    hienThiDanhSach(danhSach, "Danh sach SAU khi sap xep (theo ten)");

    sort(danhSach.begin(), danhSach.end());
    hienThiDanhSach(danhSach, "Danh sach SAU khi sap xep (theo ho ten A-Z)");

    return 0;
}

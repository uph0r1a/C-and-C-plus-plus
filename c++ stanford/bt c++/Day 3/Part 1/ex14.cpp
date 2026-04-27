#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct ThiSinh
{
    string soBaoDanh;
    string hoTen;
    int namSinh;
    float diemToan, diemLy, diemHoa;

    float tongDiem() const { return diemToan + diemLy + diemHoa; }

    bool biDiemLiet() const
    {
        return diemToan <= 1.0f || diemLy <= 1.0f || diemHoa <= 1.0f;
    }
};

float nhapDiem(const string &tenMon)
{
    float d;
    do
    {
        cout << "Diem " << tenMon << " (0 - 10): ";
        cin >> d;
        if (d < 0 || d > 10)
            cout << "Diem phai trong khoang [0, 10]!" << endl;
    } while (d < 0 || d > 10);
    return d;
}

ThiSinh nhapThiSinh(int stt)
{
    ThiSinh ts;
    cout << "\n--- Thi sinh thu " << stt << " ---" << endl;
    cout << "So bao danh: ";
    cin >> ts.soBaoDanh;
    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, ts.hoTen);
    cout << "Nam sinh: ";
    cin >> ts.namSinh;
    ts.diemToan = nhapDiem("Toan");
    ts.diemLy = nhapDiem("Ly");
    ts.diemHoa = nhapDiem("Hoa");
    return ts;
}

void inDauTrang()
{
    cout << left
         << setw(8) << "SBD"
         << setw(22) << "Ho ten"
         << setw(8) << "NS"
         << setw(7) << "Toan"
         << setw(7) << "Ly"
         << setw(7) << "Hoa"
         << setw(8) << "Tong"
         << "Ghi chu"
         << endl;
    cout << string(75, '-') << endl;
}

void inDongThiSinh(const ThiSinh &ts)
{
    cout << fixed << setprecision(1) << left
         << setw(8) << ts.soBaoDanh
         << setw(22) << ts.hoTen
         << setw(8) << ts.namSinh
         << setw(7) << ts.diemToan
         << setw(7) << ts.diemLy
         << setw(7) << ts.diemHoa
         << setw(8) << ts.tongDiem()
         << (ts.biDiemLiet() ? "[LIET]" : "")
         << endl;
}

void inDanhSach(const vector<ThiSinh> &ds, const string &tieuDe)
{
    cout << "\n=== " << tieuDe << " ===" << endl;
    if (ds.empty())
    {
        cout << "(Khong co thi sinh nao.)" << endl;
        return;
    }
    inDauTrang();
    for (const auto &ts : ds)
        inDongThiSinh(ts);
    cout << "Tong so: " << ds.size() << " thi sinh." << endl;
}

vector<ThiSinh> layTop5(vector<ThiSinh> ds)
{
    ds.erase(remove_if(ds.begin(), ds.end(),
                       [](const ThiSinh &t)
                       { return t.biDiemLiet(); }),
             ds.end());

    sort(ds.begin(), ds.end(),
         [](const ThiSinh &a, const ThiSinh &b)
         { return a.tongDiem() > b.tongDiem(); });

    if ((int)ds.size() > 5)
        ds.resize(5);
    return ds;
}

vector<ThiSinh> layDatDiemSan(const vector<ThiSinh> &ds, float diemSan = 15.0f)
{
    vector<ThiSinh> kq;
    for (const auto &ts : ds)
        if (ts.tongDiem() >= diemSan && !ts.biDiemLiet())
            kq.push_back(ts);
    return kq;
}

vector<ThiSinh> layBiDiemLiet(const vector<ThiSinh> &ds)
{
    vector<ThiSinh> kq;
    for (const auto &ts : ds)
        if (ts.biDiemLiet())
            kq.push_back(ts);
    return kq;
}

int main(int argc, char const *argv[])
{
    cout << "=====================================================" << endl;
    cout << "     QUAN LY THI SINH TUYEN SINH KHOI A              " << endl;
    cout << "=====================================================" << endl;

    int soLuong;
    do
    {
        cout << "Nhap so luong thi sinh (10 - 20): ";
        cin >> soLuong;
        if (soLuong < 10 || soLuong > 20)
            cout << "So luong phai tu 10 den 20!" << endl;
    } while (soLuong < 10 || soLuong > 20);

    vector<ThiSinh> danhSach;
    danhSach.reserve(soLuong);
    for (int i = 0; i < soLuong; i++)
        danhSach.push_back(nhapThiSinh(i + 1));

    auto tatCa = danhSach;
    inDanhSach(tatCa, "DANH SACH TOAN BO THI SINH");

    auto top5 = layTop5(danhSach);
    inDanhSach(top5, "TOP 5 THI SINH DIEM CAO NHAT (KHONG BI LIET)");

    auto datSan = layDatDiemSan(danhSach, 15.0f);
    inDanhSach(datSan, "THI SINH DAT DIEM SAN (>= 15 DIEM, KHONG BI LIET)");

    auto biLiet = layBiDiemLiet(danhSach);
    inDanhSach(biLiet, "THI SINH BI DIEM LIET");

    return 0;
}

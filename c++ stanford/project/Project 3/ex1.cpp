#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const double DIEM_SAN = 15.0;
const double DIEM_LIET = 1.0;

struct ThiSinh
{
    int sbd;
    string hoTen;
    string queQuan;
    double toan, ly, hoa;

    double tongDiem() const
    {
        return toan + ly + hoa;
    }

    bool biDiemLiet() const
    {
        return toan == DIEM_LIET || ly == DIEM_LIET || hoa == DIEM_LIET;
    }

    bool datDiemSan() const
    {
        return tongDiem() >= DIEM_SAN && !biDiemLiet();
    }
};

double nhapDiem(const string &monHoc)
{
    double d;
    while (true)
    {
        cout << "Diem " << monHoc << " (0 - 10): ";
        if (cin >> d && d >= 0.0 && d <= 10.0)
            return d;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Loi: Diem phai trong khoang [0, 10]. Nhap lai.\n";
    }
}

int nhapSBD(const string &loi)
{
    int sbd;
    while (true)
    {
        cout << loi;
        if (cin >> sbd && sbd > 0)
            return sbd;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Loi: SBD phai la so nguyen duong. Nhap lai.\n";
    }
}

bool trungSBD(const vector<ThiSinh> &ds, int sbd)
{
    for (const auto &ts : ds)
        if (ts.sbd == sbd)
            return true;
    return false;
}

ThiSinh nhapMot(const vector<ThiSinh> &danhSach)
{
    ThiSinh ts;

    while (true)
    {
        ts.sbd = nhapSBD("So bao danh: ");
        if (!trungSBD(danhSach, ts.sbd))
            break;
        cout << "Loi: SBD " << ts.sbd << " da ton tai. Nhap SBD khac.\n";
    }

    cin.ignore(1000, '\n');
    cout << "Ho ten: ";
    getline(cin, ts.hoTen);
    cout << "Que quan: ";
    getline(cin, ts.queQuan);

    ts.toan = nhapDiem("Toan");
    ts.ly = nhapDiem("Ly");
    ts.hoa = nhapDiem("Hoa");

    return ts;
}

vector<ThiSinh> taoMauDuLieu()
{
    return {
        {1000, "Bui Quang Hai", "Ha Noi", 9, 8, 6},
        {1001, "Nguyen Thi Anh", "Hai Phong", 5, 8, 6},
        {1002, "Nguyen Van Anh", "Nam Dinh", 5, 4, 6},
        {1003, "Tran Thai Hoa", "Hai Duong", 6, 8, 5},
        {1004, "Le Hai Ha", "Ha Nam", 5, 7, 3},
        {1005, "Do Dang Thuc", "Bac Giang", 4, 9, 1},
        {1006, "Vu Thi Tham", "Hai Phong", 8, 8, 9},
        {1007, "Pham Anh Quang", "Ha Noi", 10, 8, 9},
        {1008, "Tran Thanh Hai", "Ha Nam", 5, 1, 6},
        {1009, "Tran Thanh An", "Nam Dinh", 3, 4, 5},
    };
}

void inHeader()
{
    cout << string(72, '-') << "\n";
    cout << left
         << setw(6) << "SBD"
         << setw(22) << "Ho Ten"
         << setw(16) << "Que Quan"
         << setw(6) << "Toan"
         << setw(6) << "Ly"
         << setw(6) << "Hoa"
         << setw(8) << "Tong"
         << "Ghi chu\n";
    cout << string(72, '-') << "\n";
}

void inMot(const ThiSinh &ts)
{
    cout << fixed << setprecision(1) << left
         << setw(6) << ts.sbd
         << setw(22) << ts.hoTen
         << setw(16) << ts.queQuan
         << setw(6) << ts.toan
         << setw(6) << ts.ly
         << setw(6) << ts.hoa
         << setw(8) << ts.tongDiem()
         << (ts.biDiemLiet() ? "[LIET]" : "")
         << "\n";
}

void inDanhSach(const vector<ThiSinh> &ds, const string &tieuDe)
{
    cout << "\n=== " << tieuDe << " ===\n";
    if (ds.empty())
    {
        cout << "(Khong co thi sinh nao)\n";
        return;
    }
    inHeader();
    for (const auto &ts : ds)
        inMot(ts);
    cout << string(72, '-') << "\n";
    cout << "Tong: " << ds.size() << " thi sinh.\n";
}

void hienThiGiamDan(vector<ThiSinh> ds)
{
    sort(ds.begin(), ds.end(), [](const ThiSinh &a, const ThiSinh &b)
         { return a.tongDiem() > b.tongDiem(); });
    inDanhSach(ds, "DANH SACH THI SINH (TONG DIEM GIAM DAN)");
}

void timKiemTheoSBD(const vector<ThiSinh> &ds)
{
    int sbd;
    cout << "\nNhap SBD can tim: ";
    cin >> sbd;

    bool timThay = false;
    for (const auto &ts : ds)
    {
        if (ts.sbd == sbd)
        {
            cout << "\n=== KET QUA TIM KIEM SBD " << sbd << " ===\n";
            inHeader();
            inMot(ts);
            timThay = true;
            break;
        }
    }
    if (!timThay)
        cout << "Khong tim thay thi sinh co SBD: " << sbd << "\n";
}

bool soSanhUuTien(const ThiSinh &a, const ThiSinh &b)
{
    if (a.tongDiem() != b.tongDiem())
        return a.tongDiem() > b.tongDiem();

    bool aHN = (a.queQuan == "Ha Noi");
    bool bHN = (b.queQuan == "Ha Noi");
    if (aHN != bHN)
        return !aHN;

    return a.toan > b.toan;
}

void hienThiTop3(vector<ThiSinh> ds)
{
    sort(ds.begin(), ds.end(), soSanhUuTien);

    cout << "\n=== TOP 3 THI SINH DIEM CAO NHAT ===\n";
    inHeader();
    int dem = 0;
    for (const auto &ts : ds)
    {
        if (dem >= 3)
            break;
        cout << "[" << (dem + 1) << "] ";
        inMot(ts);
        dem++;
    }
    cout << string(72, '-') << "\n";
}

void hienThiDiemSanVaLiet(const vector<ThiSinh> &ds)
{
    vector<ThiSinh> datSan, biLiet;

    for (const auto &ts : ds)
    {
        if (ts.biDiemLiet())
            biLiet.push_back(ts);
        else if (ts.datDiemSan())
            datSan.push_back(ts);
    }

    inDanhSach(datSan,
               "DAT DIEM SAN (>= " + to_string((int)DIEM_SAN) + " DIEM, KHONG BI LIET)");
    inDanhSach(biLiet, "BI DIEM LIET (CO MON = 1 DIEM)");
}

int main(int argc, char const *argv[])
{
    cout << string(72, '*') << "\n";
    cout << "QUAN LY THI SINH TUYEN SINH KHOI A - Stanford \n";
    cout << string(72, '*') << "\n";

    vector<ThiSinh> danhSach;
    int luaChon;
    cout << "\n1. Dung du lieu mau (10 thi sinh)\n";
    cout << "2. Nhap du lieu tu ban phim\n";
    cout << "Chon: ";
    cin >> luaChon;

    if (luaChon == 2)
    {
        int n;
        do
        {
            cout << "So luong thi sinh (1-100): ";
            cin >> n;
        } while (n < 1 || n > 100);

        for (int i = 0; i < n; i++)
        {
            cout << "\n--- Thi sinh " << i + 1 << " ---\n";
            danhSach.push_back(nhapMot(danhSach));
        }
    }
    else
    {
        danhSach = taoMauDuLieu();
        cout << "Da tai " << danhSach.size() << " thi sinh mau.\n";
    }

    hienThiGiamDan(danhSach);
    timKiemTheoSBD(danhSach);
    hienThiTop3(danhSach);
    hienThiDiemSanVaLiet(danhSach);

    return 0;
}
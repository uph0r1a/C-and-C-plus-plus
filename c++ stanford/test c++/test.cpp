#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

class ThiSinh
{
private:
    string m_soBaoDanh, m_hoTen, m_queQuan;
    float m_diemToan = 0, m_diemLy = 0, m_diemHoa = 0;

    static float nhapDiem(const string &mon)
    {
        float d;
        while (true)
        {
            cout << "  Diem " << left << setw(5) << mon << ": ";
            if (cin >> d && d >= 0.0f && d <= 10.0f)
                return d;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Diem phai tu 0 den 10. Nhap lai.\n";
        }
    }

public:
    const string &soBaoDanh() const
    {
        return m_soBaoDanh;
    }

    const string &hoTen() const
    {
        return m_hoTen;
    }

    const string &queQuan() const
    {
        return m_queQuan;
    }

    float diemToan() const
    {
        return m_diemToan;
    }

    float diemLy() const
    {
        return m_diemLy;
    }

    float diemHoa() const
    {
        return m_diemHoa;
    }

    float tongDiem() const
    {
        return m_diemToan + m_diemLy + m_diemHoa;
    }

    bool datDiemSan() const
    {
        return tongDiem() >= 15.0f && m_diemToan > 1.0f && m_diemLy > 1.0f && m_diemHoa > 1.0f;
    }

    bool diemLiet() const
    {
        return m_diemToan <= 1.0f || m_diemLy <= 1.0f || m_diemHoa <= 1.0f;
    }

    void nhap(const vector<ThiSinh> &danhSach)
    {
        while (1)
        {
            cout << "  So bao danh : ";
            cin >> m_soBaoDanh;
            bool trung = false;
            for (const auto &ts : danhSach)
                if (ts.m_soBaoDanh == m_soBaoDanh)
                {
                    trung = true;
                    break;
                }
            if (!trung)
                break;
            cout << "  [!] So bao danh da ton tai. Nhap lai.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Ho ten      : ";
        getline(cin, m_hoTen);
        cout << "  Que quan    : ";
        getline(cin, m_queQuan);

        m_diemToan = nhapDiem("Toan");
        m_diemLy = nhapDiem("Ly");
        m_diemHoa = nhapDiem("Hoa");
    }
};

static void inHeader()
{
    cout << '\n'
         << left
         << setw(10) << "SBD"
         << setw(22) << "Ho Ten"
         << setw(16) << "Que Quan"
         << setw(8) << "Toan"
         << setw(8) << "Ly"
         << setw(8) << "Hoa"
         << setw(10) << "Tong Diem"
         << '\n'
         << string(82, '-') << '\n';
}

static void inRow(const ThiSinh &ts)
{
    cout << left
         << setw(10) << ts.soBaoDanh()
         << setw(22) << ts.hoTen()
         << setw(16) << ts.queQuan()
         << setw(8) << fixed << setprecision(1) << ts.diemToan()
         << setw(8) << ts.diemLy()
         << setw(8) << ts.diemHoa()
         << setw(10) << ts.tongDiem()
         << '\n';
}

static void hienThiDanhSach(const vector<ThiSinh> &ds)
{
    if (ds.empty())
    {
        cout << "  (Danh sach trong)\n";
        return;
    }
    inHeader();
    for (const auto &ts : ds)
        inRow(ts);
}

static void nhapThiSinh(vector<ThiSinh> &ds)
{
    ThiSinh ts;
    cout << "\nNhap thong tin thi sinh:\n";
    ts.nhap(ds);
    ds.push_back(move(ts));
    cout << "[+] Da them thi sinh.\n";
}

static void sapXep(vector<ThiSinh> &ds)
{
    sort(ds.begin(), ds.end(), [](const ThiSinh &a, const ThiSinh &b)
         { return a.tongDiem() > b.tongDiem(); });
    cout << "[+] Da sap xep theo tong diem giam dan.\n";
}

static void timKiem(const vector<ThiSinh> &ds)
{
    string sbd;
    cout << "Nhap SBD can tim: ";
    cin >> sbd;
    for (const auto &ts : ds)
    {
        if (ts.soBaoDanh() == sbd)
        {
            inHeader();
            inRow(ts);
            return;
        }
    }
    cout << "Khong tim thay SBD: " << sbd << '\n';
}

static void hienThiTop3(vector<ThiSinh> &ds)
{
    if (ds.empty())
    {
        cout << "Danh sach trong.\n";
        return;
    }
    sapXep(ds);
    int top = min(3, (int)ds.size());
    cout << "\nTop " << top << " thi sinh diem cao nhat:\n";
    inHeader();
    for (int i = 0; i < top; i++)
        inRow(ds[i]);
}

static void hienThiDatDiemSan(const vector<ThiSinh> &ds)
{
    cout << "\nDanh sach dat diem san (Tong >= 15, moi mon > 1):\n";
    bool co = false;
    for (const auto &ts : ds)
        if (ts.datDiemSan())
        {
            if (!co)
            {
                inHeader();
                co = true;
            }
            inRow(ts);
        }
    if (!co)
        cout << "  Khong co thi sinh nao.\n";
}

static void hienThiDiemLiet(const vector<ThiSinh> &ds)
{
    cout << "\nDanh sach diem liet (Co mon <= 1):\n";
    bool co = false;
    for (const auto &ts : ds)
        if (ts.diemLiet())
        {
            if (!co)
            {
                inHeader();
                co = true;
            }
            inRow(ts);
        }
    if (!co)
        cout << "  Khong co thi sinh nao.\n";
}

int main(int argc, char const *argv[])
{
    vector<ThiSinh> danhSach;
    int luaChon;

    do
    {
        cout << "\n==============================\n"
             << " QUAN LY THI SINH\n"
             << "==============================\n"
             << " 1. Nhap thi sinh\n"
             << " 2. Hien thi danh sach\n"
             << " 3. Sap xep theo tong diem\n"
             << " 4. Tim kiem theo SBD\n"
             << " 5. Top 3 thi sinh\n"
             << " 6. Danh sach dat diem san\n"
             << " 7. Danh sach diem liet\n"
             << " 0. Thoat\n"
             << "------------------------------\n"
             << "Lua chon: ";

        if (!(cin >> luaChon))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            luaChon = -1;
        }

        switch (luaChon)
        {
        case 1:
            nhapThiSinh(danhSach);
            break;
        case 2:
            hienThiDanhSach(danhSach);
            break;
        case 3:
            sapXep(danhSach);
            break;
        case 4:
            timKiem(danhSach);
            break;
        case 5:
            hienThiTop3(danhSach);
            break;
        case 6:
            hienThiDatDiemSan(danhSach);
            break;
        case 7:
            hienThiDiemLiet(danhSach);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 0);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>
#include <algorithm>
using namespace std;

class SinhVien
{
private:
    string maSinhVien;
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string soDienThoai;
    string email;
    string soCMT;
    string queQuan;

    static bool hopLeSoDienThoai(const string &s)
    {
        return regex_match(s, regex("0[0-9]{9}"));
    }

    static bool hopLeEmail(const string &s)
    {
        return regex_match(s, regex(R"([^@\s]+@[^@\s]+\.[^@\s]+)"));
    }

    static bool hopLeSoCMT(const string &s)
    {
        return regex_match(s, regex("[0-9]{9}|[0-9]{12}"));
    }

    static bool hopLeNgaySinh(const string &s)
    {
        if (!regex_match(s, regex(R"(\d{2}/\d{2}/\d{4})")))
            return false;
        int d = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        int y = stoi(s.substr(6, 4));
        return d >= 1 && d <= 31 && m >= 1 && m <= 12 && y >= 1900 && y <= 2100;
    }

public:
    SinhVien() = default;

    SinhVien(const string &maSV, const string &ten,
             const string &gt, const string &ns,
             const string &sdt, const string &mail,
             const string &cmt, const string &que)
        : maSinhVien(maSV), hoTen(ten), gioiTinh(gt),
          ngaySinh(ns), soDienThoai(sdt), email(mail),
          soCMT(cmt), queQuan(que) {}

    string getMaSinhVien() const
    {
        return maSinhVien;
    }

    string getHoTen() const
    {
        return hoTen;
    }

    string getGioiTinh() const
    {
        return gioiTinh;
    }

    string getNgaySinh() const
    {
        return ngaySinh;
    }

    string getSoDienThoai() const
    {
        return soDienThoai;
    }

    string getEmail() const
    {
        return email;
    }

    string getSoCMT() const
    {
        return soCMT;
    }

    string getQueQuan() const
    {
        return queQuan;
    }

    void setMaSinhVien(const string &s)
    {
        maSinhVien = s;
    }

    void setHoTen(const string &s)
    {
        hoTen = s;
    }

    void setQueQuan(const string &s)
    {
        queQuan = s;
    }

    void setGioiTinh(const string &s)
    {
        if (s != "Nam" && s != "Nu")
            throw invalid_argument("Gioi tinh phai la: Nam / Nu / Khac");
        gioiTinh = s;
    }

    void setNgaySinh(const string &s)
    {
        if (!hopLeNgaySinh(s))
            throw invalid_argument("Ngay sinh khong hop le. Dung dinh dang DD/MM/YYYY.");
        ngaySinh = s;
    }

    void setSoDienThoai(const string &s)
    {
        if (!hopLeSoDienThoai(s))
            throw invalid_argument("So dien thoai khong hop le (10 so, bat dau bang 0).");
        soDienThoai = s;
    }

    void setEmail(const string &s)
    {
        if (!hopLeEmail(s))
            throw invalid_argument("Email khong hop le.");
        email = s;
    }

    void setSoCMT(const string &s)
    {
        if (!hopLeSoCMT(s))
            throw invalid_argument("So CMT/CCCD khong hop le (9 hoac 12 chu so).");
        soCMT = s;
    }

    void nhap()
    {
        cout << "Ma sinh vien: ";
        getline(cin, maSinhVien);
        cout << "Ho ten: ";
        getline(cin, hoTen);

        while (1)
        {
            cout << "Gioi tinh (Nam/Nu): ";
            getline(cin, gioiTinh);
            try
            {
                setGioiTinh(gioiTinh);
                break;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << "\n";
            }
        }

        while (1)
        {
            cout << "Ngay sinh (DD/MM/YYYY): ";
            string tmp;
            getline(cin, tmp);
            try
            {
                setNgaySinh(tmp);
                break;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << "\n";
            }
        }

        while (1)
        {
            cout << "So dien thoai: ";
            string tmp;
            getline(cin, tmp);
            try
            {
                setSoDienThoai(tmp);
                break;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << "\n";
            }
        }

        while (1)
        {
            cout << "Email: ";
            string tmp;
            getline(cin, tmp);
            try
            {
                setEmail(tmp);
                break;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << "\n";
            }
        }

        while (1)
        {
            cout << "So CMT/CCCD: ";
            string tmp;
            getline(cin, tmp);
            try
            {
                setSoCMT(tmp);
                break;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << "\n";
            }
        }

        cout << "Que quan: ";
        getline(cin, queQuan);
    }

    void inThongTin() const
    {
        const int W = 16;
        cout << left
             << setw(W) << "Ma SV: " << maSinhVien << "\n"
             << setw(W) << "Ho ten: " << hoTen << "\n"
             << setw(W) << "Gioi tinh: " << gioiTinh << "\n"
             << setw(W) << "Ngay sinh: " << ngaySinh << "\n"
             << setw(W) << "Dien thoai: " << soDienThoai << "\n"
             << setw(W) << "Email: " << email << "\n"
             << setw(W) << "So CMT/CCCD: " << soCMT << "\n"
             << setw(W) << "Que quan: " << queQuan << "\n";
    }
};

class DanhSachSinhVien
{
    vector<SinhVien> ds;

public:
    void them(const SinhVien &sv)
    {
        ds.push_back(sv);
    }

    SinhVien *timTheoMa(const string &ma)
    {
        for (auto &sv : ds)
            if (sv.getMaSinhVien() == ma)
                return &sv;
        return nullptr;
    }

    vector<SinhVien *> timTheoTen(const string &ten)
    {
        vector<SinhVien *> kq;
        string tenLower = ten;
        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        for (auto &sv : ds)
        {
            string name = sv.getHoTen();
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            if (name.find(tenLower) != string::npos)
                kq.push_back(&sv);
        }
        return kq;
    }

    void inTatCa() const
    {
        if (ds.empty())
        {
            cout << "(Danh sach trong)\n";
            return;
        }
        for (int i = 0; i < (int)ds.size(); i++)
        {
            cout << "\n[" << i + 1 << "] ";
            cout << string(40, '-') << "\n";
            ds[i].inThongTin();
        }
    }

    int soLuong() const
    {
        return (int)ds.size();
    }
};

void menu()
{
    cout << "\n========================================\n";
    cout << "       QUAN LY SINH VIEN\n";
    cout << "========================================\n";
    cout << "  1. Them sinh vien moi\n";
    cout << "  2. In danh sach\n";
    cout << "  3. Tim kiem theo ma SV\n";
    cout << "  4. Tim kiem theo ten\n";
    cout << "  0. Thoat\n";
    cout << "Chon: ";
}

int main(int argc, char const *argv[])
{
    DanhSachSinhVien dssv;

    dssv.them(SinhVien("SV001", "Nguyen Van An", "Nam",
                       "15/03/2002", "0912345678",
                       "an.nguyen@example.com", "012345678", "Ha Noi"));
    dssv.them(SinhVien("SV002", "Tran Thi Bich", "Nu",
                       "20/07/2003", "0987654321",
                       "bich.tran@example.com", "098765432109", "Ho Chi Minh"));

    int lua;
    do
    {
        menu();
        cin >> lua;
        cin.ignore(1000, '\n');
        cout << "\n";

        switch (lua)
        {
        case 1:
        {
            SinhVien sv;
            cout << "Nhap thong tin sinh vien:\n";
            sv.nhap();
            dssv.them(sv);
            cout << "Da them thanh cong!\n";
            break;
        }
        case 2:
            cout << "DANH SACH SINH VIEN (" << dssv.soLuong() << " sv):\n";
            dssv.inTatCa();
            break;
        case 3:
        {
            cout << "Nhap ma sinh vien can tim: ";
            string ma;
            getline(cin, ma);
            SinhVien *sv = dssv.timTheoMa(ma);
            if (sv)
                sv->inThongTin();
            else
                cout << "Khong tim thay sinh vien co ma: " << ma << "\n";
            break;
        }
        case 4:
        {
            cout << "Nhap ten can tim: ";
            string ten;
            getline(cin, ten);
            auto kq = dssv.timTheoTen(ten);
            if (kq.empty())
                cout << "Khong tim thay ket qua.\n";
            else
                for (auto *sv : kq)
                {
                    cout << "\n";
                    sv->inThongTin();
                }
            break;
        }
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (lua != 0);

    return 0;
}
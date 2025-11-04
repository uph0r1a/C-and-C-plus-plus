#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct ThiSinh
{
    string soBaoDanh;
    string hoTen;
    string queQuan;
    float diemToan;
    float diemLy;
    float diemHoa;

    float tinhTongDiem() const
    {
        return diemToan + diemLy + diemHoa;
    }
};

void nhapThongTinThiSinh(vector<ThiSinh> &danhSach)
{
    ThiSinh thiSinh;
    cout << "Nhap thong tin thi sinh:\n";

    while (true)
    {
        cout << "Nhap so bao danh: ";
        cin >> thiSinh.soBaoDanh;
        bool trungLap = false;
        for (const auto &ts : danhSach)
        {
            if (ts.soBaoDanh == thiSinh.soBaoDanh)
            {
                trungLap = true;
                cout << "So bao danh bi trung. Vui long nhap lai.\n";
                break;
            }
        }
        if (!trungLap)
            break;
    }

    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, thiSinh.hoTen);
    cout << "Nhap que quan: ";
    getline(cin, thiSinh.queQuan);

    do
    {
        cout << "Nhap diem Toan: ";
        cin >> thiSinh.diemToan;
    } while (thiSinh.diemToan < 0 || thiSinh.diemToan > 10);

    do
    {
        cout << "Nhap diem Ly: ";
        cin >> thiSinh.diemLy;
    } while (thiSinh.diemLy < 0 || thiSinh.diemLy > 10);

    do
    {
        cout << "Nhap diem Hoa: ";
        cin >> thiSinh.diemHoa;
    } while (thiSinh.diemHoa < 0 || thiSinh.diemHoa > 10);

    danhSach.push_back(thiSinh);
}

void hienThiDanhSach(const vector<ThiSinh> &danhSach)
{
    cout << left << setw(10) << "SBD" << setw(20) << "Ho Ten" << setw(15)
         << "Que Quan" << setw(10) << "Toan" << setw(10) << "Ly"
         << setw(10) << "Hoa" << setw(10) << "Tong Diem" << endl;

    for (const auto &ts : danhSach)
    {
        cout << left << setw(10) << ts.soBaoDanh << setw(20) << ts.hoTen << setw(15)
             << ts.queQuan << setw(10) << ts.diemToan << setw(10) << ts.diemLy
             << setw(10) << ts.diemHoa << setw(10) << ts.tinhTongDiem() << endl;
    }
}

void sapXepThiSinhTheoTongDiem(vector<ThiSinh> &danhSach)
{
    for (size_t i = 0; i < danhSach.size() - 1; i++)
    {
        for (size_t j = i + 1; j < danhSach.size(); j++)
        {
            if (danhSach[i].tinhTongDiem() < danhSach[j].tinhTongDiem())
            {
                swap(danhSach[i], danhSach[j]);
            }
        }
    }
}

void timKiemTheoSoBaoDanh(const vector<ThiSinh> &danhSach)
{
    string sbd;
    cout << "Nhap so bao danh can tim: ";
    cin >> sbd;

    for (const auto &ts : danhSach)
    {
        if (ts.soBaoDanh == sbd)
        {
            hienThiDanhSach({ts});
            return;
        }
    }
    cout << "Khong tim thay thi sinh voi SBD: " << sbd << endl;
}

void hienThiTop3ThiSinh(vector<ThiSinh> &danhSach)
{
    sapXepThiSinhTheoTongDiem(danhSach);
    cout << "Top 3 thi sinh co diem cao nhat:\n";
    hienThiDanhSach(vector<ThiSinh>(danhSach.begin(), danhSach.begin() + min(3, (int)danhSach.size())));
}

void hienThiDanhSachDatDiemSan(const vector<ThiSinh> &danhSach)
{
    cout << "Danh sach thi sinh dat diem san (Tong >= 15, khong co diem nao la 1):\n";
    for (const auto &ts : danhSach)
    {
        if (ts.tinhTongDiem() >= 15 && ts.diemToan > 1 && ts.diemLy > 1 && ts.diemHoa > 1)
        {
            hienThiDanhSach({ts});
        }
    }
}

void hienThiDanhSachDiemLiet(const vector<ThiSinh> &danhSach)
{
    cout << "Danh sach thi sinh co diem liet (Mot mon co diem = 1):\n";
    for (const auto &ts : danhSach)
    {
        if (ts.diemToan == 1 || ts.diemLy == 1 || ts.diemHoa == 1)
        {
            hienThiDanhSach({ts});
        }
    }
}

int main()
{
    vector<ThiSinh> danhSach;
    int luaChon;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Nhap thong tin thi sinh\n";
        cout << "2. Hien thi danh sach thi sinh\n";
        cout << "3. Sap xep danh sach theo tong diem\n";
        cout << "4. Tim kiem thi sinh theo SBD\n";
        cout << "5. Hien thi Top 3 thi sinh\n";
        cout << "6. Hien thi danh sach dat diem san\n";
        cout << "7. Hien thi danh sach diem liet\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case 1:
            nhapThongTinThiSinh(danhSach);
            break;
        case 2:
            hienThiDanhSach(danhSach);
            break;
        case 3:
            sapXepThiSinhTheoTongDiem(danhSach);
            cout << "Danh sach da duoc sap xep theo tong diem.\n";
            break;
        case 4:
            timKiemTheoSoBaoDanh(danhSach);
            break;
        case 5:
            hienThiTop3ThiSinh(danhSach);
            break;
        case 6:
            hienThiDanhSachDatDiemSan(danhSach);
            break;
        case 7:
            hienThiDanhSachDiemLiet(danhSach);
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

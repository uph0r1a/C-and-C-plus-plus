#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <limits>
using namespace std;

class Mobile
{
protected:
    string manHinh;
    string mau;
    double trongLuong;
    string hangSanXuat;
    string heDieuHanh;
    double gia;

public:
    Mobile()
        : trongLuong(0),
          gia(0) {}

    Mobile(const string &manHinh, const string &mau,
           double trongLuong, const string &hangSanXuat,
           const string &heDieuHanh, double gia)
        : manHinh(manHinh), mau(mau),
          trongLuong(trongLuong),
          hangSanXuat(hangSanXuat),
          heDieuHanh(heDieuHanh),
          gia(gia) {}

    virtual ~Mobile() = default;

    string getManHinh() const
    {
        return manHinh;
    }

    string getMau() const
    {
        return mau;
    }

    double getTrongLuong() const
    {
        return trongLuong;
    }

    string getHangSanXuat() const
    {
        return hangSanXuat;
    }

    string getHeDieuHanh() const
    {
        return heDieuHanh;
    }

    double getGia() const
    {
        return gia;
    }

    void setManHinh(const string &v)
    {
        manHinh = v;
    }

    void setMau(const string &v)
    {
        mau = v;
    }

    void setTrongLuong(double v)
    {
        trongLuong = v;
    }

    void setHangSanXuat(const string &v)
    {
        hangSanXuat = v;
    }

    void setHeDieuHanh(const string &v)
    {
        heDieuHanh = v;
    }

    void setGia(double v)
    {
        gia = v;
    }

    virtual void hienThi() const
    {
        cout << "Man hinh: " << manHinh << "\n"
             << "Mau: " << mau << "\n"
             << "Trong luong: " << trongLuong << " g\n"
             << "Hang SX: " << hangSanXuat << "\n"
             << "He dieu hanh: " << heDieuHanh << "\n"
             << "Gia: " << fixed << setprecision(1)
             << gia << " trieu VND\n";
    }

    virtual string tenSanPham() const
    {
        return hangSanXuat;
    }
};

class SmartPhone : public Mobile
{
protected:
    int ram;
    int oĐia;
    string choPhAnMem;

public:
    SmartPhone()
        : ram(0),
          oĐia(0) {}

    SmartPhone(const string &manHinh, const string &mau,
               double trongLuong, const string &hang,
               const string &heDH, double gia,
               int ram, int oDia, const string &cho)
        : Mobile(manHinh, mau, trongLuong, hang, heDH, gia),
          ram(ram),
          oĐia(oDia),
          choPhAnMem(cho) {}

    int getRam() const
    {
        return ram;
    }

    int getODia() const
    {
        return oĐia;
    }

    string getChoPhanMem() const
    {
        return choPhAnMem;
    }

    void setRam(int v)
    {
        ram = v;
    }

    void setODia(int v)
    {
        oĐia = v;
    }

    void setChoPhanMem(const string &v)
    {
        choPhAnMem = v;
    }

    void hienThi() const override
    {
        Mobile::hienThi();
        cout << "RAM: " << ram << " GB\n"
             << "O dia: " << oĐia << " GB\n"
             << "Cho PM: " << choPhAnMem << "\n";
    }
};

class iPhone : public SmartPhone
{
private:
    string model;

public:
    iPhone() = default;

    iPhone(const string &model,
           const string &manHinh, const string &mau,
           double trongLuong, double gia,
           int ram, int oDia)
        : SmartPhone(manHinh, mau, trongLuong, "Apple", "iOS", gia, ram, oDia, "App Store"),
          model(model) {}

    string getModel() const
    {
        return model;
    }

    string tenSanPham() const override
    {
        return model;
    }

    void hienThi() const override
    {
        cout << "┌─ " << model << " ─────────────────────────────\n";
        SmartPhone::hienThi();
        cout << "└────────────────────────────────────────────\n";
    }
};

class Samsung : public SmartPhone
{
private:
    string model;

public:
    Samsung() = default;

    Samsung(const string &model,
            const string &manHinh, const string &mau,
            double trongLuong, double gia,
            int ram, int oDia)
        : SmartPhone(manHinh, mau, trongLuong, "Samsung", "Android", gia, ram, oDia, "Google Play"),
          model(model) {}

    string getModel() const
    {
        return model;
    }

    string tenSanPham() const override
    {
        return model;
    }

    void hienThi() const override
    {
        cout << "┌─ " << model << " ─────────────────────────────\n";
        SmartPhone::hienThi();
        cout << "└────────────────────────────────────────────\n";
    }
};

static void inDanhSach(const vector<unique_ptr<Mobile>> &ds, const string &tieuDe)
{
    cout << "\n╔══════════════════════════════════════════════╗\n"
         << "║  " << left << setw(44) << tieuDe << "║\n"
         << "╚══════════════════════════════════════════════╝\n";
    for (const auto &p : ds)
    {
        p->hienThi();
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    vector<unique_ptr<Mobile>> iphones;

    iphones.push_back(make_unique<iPhone>(
        "iPhone 4S",
        "3.5 inch Retina IPS", "Trang/Den",
        140, 4.5,
        512 / 1024.0, 8));

    iphones.push_back(make_unique<iPhone>(
        "iPhone 5S",
        "4.0 inch Retina IPS", "Vang/Bac/Xam",
        132, 8.5,
        1, 16));

    iphones.push_back(make_unique<iPhone>(
        "iPhone 6",
        "4.7 inch Retina IPS", "Vang/Bac/Xam vu tru",
        129, 13.5,
        1, 16));

    iphones.push_back(make_unique<iPhone>(
        "iPhone 6 Plus",
        "5.5 inch Retina IPS", "Vang/Bac/Xam vu tru",
        172, 16.0,
        1, 16));

    vector<unique_ptr<Mobile>> samsungs;

    samsungs.push_back(make_unique<Samsung>(
        "Galaxy S3",
        "4.8 inch Super AMOLED", "Marble White/Pebble Blue",
        133, 5.5,
        1, 16));

    samsungs.push_back(make_unique<Samsung>(
        "Galaxy Note Edge",
        "5.6 inch Super AMOLED (cong)", "Charcoal Black/Frost White",
        174, 16.5,
        3, 32));

    samsungs.push_back(make_unique<Samsung>(
        "Galaxy S6",
        "5.1 inch Super AMOLED QHD", "Black Sapphire/White Pearl/Gold Platinum",
        138, 14.0,
        3, 32));

    inDanhSach(iphones, "DANH SACH iPHONE");
    inDanhSach(samsungs, "DANH SACH SAMSUNG GALAXY");

    cout << "\n╔══════════════════════════════════════════════╗\n"
         << "║  TONG HOP TEN SAN PHAM (DA HINH)             ║\n"
         << "╚══════════════════════════════════════════════╝\n";

    vector<Mobile *> tatCa;
    for (const auto &p : iphones)
        tatCa.push_back(p.get());
    for (const auto &p : samsungs)
        tatCa.push_back(p.get());

    for (int i = 0; i < (int)tatCa.size(); i++)
        cout << "  " << (i + 1) << ". " << tatCa[i]->tenSanPham()
             << "  (" << tatCa[i]->getHangSanXuat() << ")"
             << "  -  " << tatCa[i]->getGia() << " tr VND\n";

    sort(tatCa.begin(), tatCa.end(),
         [](Mobile *a, Mobile *b)
         { return a->getGia() < b->getGia(); });

    cout << "\n╔══════════════════════════════════════════════╗\n"
         << "║  SAP XEP THEO GIA TANG DAN                   ║\n"
         << "╚══════════════════════════════════════════════╝\n";
    for (const auto *p : tatCa)
        cout << "  " << left << setw(22) << p->tenSanPham()
             << fixed << setprecision(1) << p->getGia() << " tr VND\n";

    return 0;
}
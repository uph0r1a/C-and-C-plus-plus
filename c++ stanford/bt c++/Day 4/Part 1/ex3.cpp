#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class HangHoa
{
private:
    string maHang;
    string tenHang;
    string moTa;
    int soLuong;
    double giaBan;
    string loaiHang;

public:
    HangHoa(string ma = "", string ten = "", string description = "",
            int amount = 0, double price = 0, string type = "")
        : maHang(ma),
          tenHang(ten),
          moTa(description),
          soLuong(amount),
          giaBan(price),
          loaiHang(type) {}

    void setMaHang(const string &ma)
    {
        if (!ma.empty())
            maHang = ma;
    }

    void setTenHang(const string &ten)
    {
        if (!ten.empty())
            tenHang = ten;
    }

    void setMoTa(const string &moTa_new)
    {
        moTa = moTa_new;
    }

    void setSoLuong(int amount)
    {
        if (amount >= 0)
            soLuong = amount;
    }

    void setGiaBan(double price)
    {
        if (price >= 0)
            giaBan = price;
    }

    void setLoaiHang(const string &type)
    {
        if (!type.empty())
            loaiHang = type;
    }

    string getMaHang() const
    {
        return maHang;
    }

    string getTenHang() const
    {
        return tenHang;
    }

    string getMoTa() const
    {
        return moTa;
    }

    int getSoLuong() const
    {
        return soLuong;
    }

    double getGiaBan() const
    {
        return giaBan;
    }

    string getLoaiHang() const
    {
        return loaiHang;
    }

    double getTongGiaTri() const
    {
        return soLuong * giaBan;
    }

    void hienThi() const
    {
        cout << string(50, '-') << endl;
        cout << "Mã hàng: " << maHang << endl;
        cout << "Tên hàng: " << tenHang << endl;
        cout << "Mô tả: " << moTa << endl;
        cout << "Số lượng: " << soLuong << endl;
        cout << "Giá bán: " << fixed << setprecision(2) << giaBan << endl;
        cout << "Loại hàng: " << loaiHang << endl;
        cout << "Tổng giá trị: " << fixed << setprecision(2) << getTongGiaTri() << endl;
        cout << string(50, '-') << endl;
    }

    bool isValid() const
    {
        return !maHang.empty() && !tenHang.empty() && soLuong >= 0 && giaBan >= 0;
    }
};

int main(int argc, char const *argv[])
{
    HangHoa item("12345", "Laptop", "High-end gaming laptop", 2, 15000000, "Electronics");

    cout << "\n=== THÔNG TIN SẢN PHẨM ===" << endl;
    item.hienThi();

    cout << "\n=== CẬP NHẬT THÔNG TIN ===" << endl;
    item.setSoLuong(5);
    item.setGiaBan(14500000);
    item.hienThi();

    HangHoa item2("54321", "Chuột máy tính", "Chuột không dây hiệu năng cao",
                  50, 250000, "Phụ kiện");

    cout << "\n=== SẢN PHẨM THỨ HAI ===" << endl;
    item2.hienThi();

    cout << "\n=== KIỂM TRA TÍNH HỢP LỆ ===" << endl;
    cout << "Product 1 valid: " << (item.isValid() ? "Yes" : "No") << endl;
    cout << "Product 2 valid: " << (item2.isValid() ? "Yes" : "No") << endl;

    return 0;
}
// Stanford_LopVaDoiTuongCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//Khai báo lớp cần làm việc
#include "TinhToan.h"
#include "HinhTron.h"
int main()
{
    /*
    //Khai báo 1 đối tượng
    TinhToan tt;

    //Sử dụng các thành phần được định nghĩa trong lớp TinhToan qua đối tượng tt
    tt.InThongTin();
    //Gọi lần 2
    tt.InThongTin();

    //In 10 câu I Love You
    tt.InThongTin(10);

    //Khai báo biến
    int x = 0, y = 0, tong = 0, hieu = 0;

    cout << "Nhap gia tri x = ";
    cin >> x;
    cout << "Nhap gia tri y = ";
    cin >> y;

    //Tính toán
    tong = tt.TongHaiSo(x, y);
    hieu = tt.HieuHaiSo(x, y);

    cout << "Tong hai so " << x << " va " << y << " la: " << tong << endl;
    cout << "Hieu hai so " << x << " va " << y << " la: " << hieu << endl;

    cout << "Ten cong ty la: " << tt.LayTenCongTy() << endl;

    cout << "Gia tri b = " << tt.b << endl;*/

    //Khai báo biến
    double banKinh = 0, chuVi = 0, dienTich = 0;

    cout << "Nhap ban kinh hinh tron r = ";
    cin >> banKinh;
    /*
    //Khai báo 1 đối tượng
    HinhTron ht(banKinh);

    //Gọi hàm để tính toán
    chuVi = ht.ChuVi();
    dienTich = ht.DienTich();

    cout << "Chu vi hinh tron la: " << chuVi << endl;
    cout << "Dien tich hinh tron la: " << dienTich << endl;

    cout << "Cach 2: " << endl;
    ht.InThongTin();*/

    HinhTron ht2;

    //Gán giá trị bán kính
    ht2.setBanKinh(banKinh);

    ht2.InThongTin();

}


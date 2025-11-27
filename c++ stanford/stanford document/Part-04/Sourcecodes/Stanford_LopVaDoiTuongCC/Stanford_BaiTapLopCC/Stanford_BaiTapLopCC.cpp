// Stanford_BaiTapLopCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TinhToan.h"
using namespace std;

int main()
{
    //Khai báo đối tượng
    TinhToan tt;

    //Khai báo biến
    double dai = 0, rong = 0, chuViHCN = 0, dienTichHCN = 0, r = 0, chuViHT = 0, dienTichHT = 0, dayLon = 0, dayNho = 0, chieuCao = 0, dtHinhThang = 0;

    cout << "Nhap chieu dai HCN = ";
    cin >> dai;

    cout << "Nhap chieu rong HCN = ";
    cin >> rong;

    //Tính toán
    chuViHCN = tt.ChuViHCN(dai, rong);
    dienTichHCN = tt.DienTichHCN(dai, rong);
    cout << "Chu vi HCN la: " << chuViHCN << endl;
    cout << "Dien tich HCN la: " << dienTichHCN << endl;

    cout << "Nhap ban kinh hinh tron r = ";
    cin >> r;
    //Tính toán
    chuViHT = tt.ChuViHT(r);
    dienTichHT = tt.DienTichHT(r);
    cout << "Chu vi hinh tron la: " << chuViHT << endl;
    cout << "Dien tich hinh tron la: " << dienTichHT << endl;

    cout << "Nhap day lon hinh thang = ";
    cin >> dayLon;
    cout << "Nhap day nho hinh thang = ";
    cin >> dayNho;
    cout << "Nhap chieu cao hinh thang = ";
    cin >> chieuCao;
    //Tính toán
    dtHinhThang = tt.DienTichHinhThang(dayLon, dayNho, chieuCao);
    cout << "Dien tich hinh thang la: " << dtHinhThang << endl;

    int n = 0, giaiThua = 0;
    cout << "Nhap gia tri can tinh giai thua n = ";
    cin >> n;

    giaiThua = tt.GiaiThua(n);

    cout << "Giai thua cua " << n << " la: " << giaiThua << endl;

}


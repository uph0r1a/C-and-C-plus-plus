// Stanford_BaiKiemTraCuoiKhoa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "NhanVien.h"
#include <iostream>
#include <conio.h>
#include<iomanip>

int main()
{
	cout << setprecision(15);

	cout << "************************************STANFORD - DAY KINH NGHIEM LAP TRINH*************************************" << endl;
	cout << "\t" << "Dia chi: So 20 ngo 678 Duong Lang, Dong Da, Ha Noi\t\t\t" << "Website: www.stanford.com.vn" << endl;

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	cout << "QUAN LY THONG TIN NHAN SU BAI THUC HANH TONG HOP CUOI KHOA C/C++ FOR BASE" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	int n = 10;
	NhanVien a[10];
	NhanVien nv;
	nv.Nhapdanhsach(a);

	cout << endl;

	cout << "Danh sach Can Bo Cong Nhan Vien Co Tong Luong Xep Theo Chieu Giam Gian: " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	nv.HienThi(a, n);

	cout << endl;

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	nv.TimKiem(a, n);

	cout << endl;

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	nv.InDanhSachRaFile(a, n);

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Danh sach nhan vien moi vao tu nam 2025 co tong luong giam dan va sap xep theo phong ban la: " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	nv.Sapxep2025(a, n);

	nv.InBangLuongMoiNam2025(a, n);

	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	cout << endl;
}
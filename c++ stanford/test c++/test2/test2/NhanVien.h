#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class NhanVien
{
public:
	int NamVaoCongTy;
	double heSoLuong, phuCap, tongLuong;
	string maNV, hoTen, diaChi, phongBan;
	double tinhTongLuong();
	bool NhapThongTinNhanVien();
};

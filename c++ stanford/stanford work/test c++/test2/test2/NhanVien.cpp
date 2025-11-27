#include "NhanVien.h"

double NhanVien::tinhTongLuong()
{
	tongLuong = 4000000 * heSoLuong + phuCap;
	return tongLuong;
}

bool NhanVien::NhapThongTinNhanVien()
{

	cout << "Nhap ma nhan vien: ";
	cin >> maNV;

	cout << "Nhap ten nhan vien: ";
	cin.ignore();
	getline(cin, hoTen);

	cout << "Nhap dia chi nhan vien: ";
	getline(cin, diaChi);

	do {
		cout << "Nhap he so luong nhan vien (>= 1.5): ";
		cin >> heSoLuong;
	} while (heSoLuong < 1.5);

	do {
		cout << "Nhap phu cap nhan vien (>= 0): ";
		cin >> phuCap;
	} while (phuCap < 0);

	do {
		cout << "Nhap phong ban nhan vien (CNTT, KT, KD): ";
		cin >> phongBan;
	} while (phongBan != "CNTT" && phongBan != "KT" && phongBan != "KD");

	return true;
}
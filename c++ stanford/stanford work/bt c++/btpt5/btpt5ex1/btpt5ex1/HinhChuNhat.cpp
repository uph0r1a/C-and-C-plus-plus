#include "HinhChuNhat.h"

double HinhChuNhat::ChuVi()
{
	return 2 * (this->ChieuDai + this->ChieuRong);
}

double HinhChuNhat::DienTich()
{
	return this->ChieuDai * this->ChieuRong;
}

void HinhChuNhat::InThongTin()
{
	cout << "Chu vi hinh chu nhat la: " << this->ChuVi() << endl;
	cout << "Dien tich hinh chu nhat la: " << this->DienTich() << endl;
}

#include "HinhTron.h"
#include "HinhTron.h"

double HinhTron::ChuVi()
{
	return 2 * this->PI * this->r;
}

double HinhTron::DienTich()
{
	return this->PI * this->r * this->r;
}

void HinhTron::InThongTin()
{
	cout << "Chu vi hinh tron la: " << this->ChuVi() << endl;
	cout << "Dien tich hinh tron la: " << this->DienTich() << endl;
}

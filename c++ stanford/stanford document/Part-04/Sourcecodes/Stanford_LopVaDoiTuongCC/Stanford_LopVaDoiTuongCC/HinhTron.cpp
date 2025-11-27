#include "HinhTron.h"

HinhTron::HinhTron(double r)
{
	this->r = r;
}

HinhTron::HinhTron()
{

}

double HinhTron::getBanKinh()
{
	return this->r;
}

void HinhTron::setBanKinh(double r)
{
	cout << "Ham gan ban kinh hinh tron" << endl;
	if (r <= 0)
	{
		this->r = 0;
	}
	else
	{
		this->r = r;
	}
}
double HinhTron::ChuVi()
{
	return 2 * this->PI * r;
}

double HinhTron::DienTich()
{
	return this->PI * r * r;
}

void HinhTron::InThongTin()
{
	cout << "Chu vi hinh tron la: " << this->ChuVi() << endl;
	cout << "Dien tich hinh tron la: " << this->DienTich() << endl;
}

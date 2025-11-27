#include "TinhToan.h"

double TinhToan::ChuViHCN(double chieuDai, double chieuRong)
{
	return 2 * (chieuDai + chieuRong);
}

double TinhToan::DienTichHCN(double chieuDai, double chieuRong)
{
	return chieuDai * chieuRong;
}

double TinhToan::ChuViHT(double r)
{
	return 2 * this->PI * r;
}

double TinhToan::DienTichHT(double r)
{
	return this->PI * r * r;
}

double TinhToan::DienTichHinhThang(double dayLon, double dayNho, double chieuCao)
{
	return ((dayLon + dayNho) * chieuCao) / 2;
}

int TinhToan::GiaiThua(int n)
{
	int ketQua = 1;
	for (int i = n; i >= 1; i--)
	{
		ketQua *= i;
	}

	return ketQua;
}
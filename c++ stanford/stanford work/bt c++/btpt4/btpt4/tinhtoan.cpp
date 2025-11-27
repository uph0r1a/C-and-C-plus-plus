#include "tinhtoan.h"

double tinhtoan::ChuVihcn(double chieudai, double chieurong);
{
	return 2 * (chieudai + chieurong);
}

double tinhtoan::DienTichhcn(double chieudai, double chieurong);
{
	return chieudai * chieurong;
}

double tinhtoan::ChuViHT(double r);
{
	return 2 * this->pi * r;
}

double tinhtoan::DientichHT(double r);
{
	return this->pi * r * r;
}

double tinhtoan::DientichHinhThang(double daylon, double daybe, double chieucao);
{
	return ((daylon + daybe) * chieucao) / 2;
}

int tinhtoan::GiaiThua(int n);
{
	int ketqua = 1;
	for (int i = n; i >= 1; i--)
	{
		ketqua *= i;
	}

	return ketqua;
}
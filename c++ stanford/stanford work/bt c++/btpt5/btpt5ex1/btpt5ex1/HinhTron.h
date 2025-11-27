#pragma once
#include "TinhToan.h"
class HinhTron :public TinhToan
{
private:
	const double PI = 3.14;
public:
	double r = 0;
	double ChuVi();
	double DienTich();
	void InThongTin();
};

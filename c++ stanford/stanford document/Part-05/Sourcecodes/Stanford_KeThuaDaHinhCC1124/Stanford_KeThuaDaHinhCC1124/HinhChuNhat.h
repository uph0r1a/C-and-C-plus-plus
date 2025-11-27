#pragma once
#include "TinhToan.h"
class HinhChuNhat: public TinhToan
{
public:
	double ChieuDai, ChieuRong;
	double ChuVi();
	double DienTich();
	void InThongTin();
};


#pragma once
#include <iostream>
using namespace std;

class tinhtoan
{
private:
	const double pi = 3.14;
public:
	double ChuVihcn(double chieudai, double chieurong);
	double DienTichhcn(double chieudai, double chieurong);
	double ChuViHT(double r);
	double DientichHT(double r);
	double DientichHinhThang(double daylon, double daybe, double chieucao);
	int GiaiThua(int n);
};
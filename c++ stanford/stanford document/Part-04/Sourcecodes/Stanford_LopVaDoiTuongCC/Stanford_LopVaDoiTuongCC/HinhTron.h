#pragma once
#include <iostream>
using namespace std;

class HinhTron
{
private:
	const double PI = 3.14;
	double r = 0;
public:
	HinhTron(double r);
	HinhTron();
	double getBanKinh();
	void setBanKinh(double r);
	double ChuVi();
	double DienTich();
	void InThongTin();
};


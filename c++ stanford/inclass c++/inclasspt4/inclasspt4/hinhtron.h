#pragma once
#include <iostream>
using namespace std;

class hinhtron
{
private:
	const double pi = 3.14;
	double r = 0;
public:
	hinhtron(double r);
	hinhtron();
	double getBanKinh();
	void setBanKinh(double r);
	double chuvi();
	double dientich();
	void InThongTin();
};
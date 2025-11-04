#pragma once
#include <iostream>
#include <string>
using namespace std;

class ConNguoi
{
public:
	string mauMat = "";
	string mauDa = "";
	double chieuCao = 0;
	double canNang = 0;
	virtual string tiengNoi();
	double chieuCaoTrungBinh();
	double canNangTrungBinh();
	void inThongTin();
};


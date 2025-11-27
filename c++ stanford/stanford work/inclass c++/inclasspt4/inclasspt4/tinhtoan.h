#pragma once
#include <iostream>
#include <string>
using namespace std;

class tinhtoan
{
private:
	int a = 5;
public:
	int b = 10;
	void InThongTin();
	void InThongTin(int n);
	int TongHaiSo(int a, int b);
	int HieuHaiSo(int a, int b);
	string LayTenCongTy();
	tinhtoan();
	//Hàm hủy
	~tinhtoan();
};

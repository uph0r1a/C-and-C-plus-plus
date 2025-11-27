#pragma once
class TinhToan
{
private:
	const double PI = 3.14;
public:
	double ChuViHCN(double chieuDai, double chieuRong);
	double DienTichHCN(double chieuDai, double chieuRong);
	double ChuViHT(double r);
	double DienTichHT(double r);
	double DienTichHinhThang(double dayLon, double dayNho, double chieuCao);
	int GiaiThua(int n);
};


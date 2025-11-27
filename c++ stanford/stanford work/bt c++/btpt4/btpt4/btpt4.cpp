#include <iostream>
#include "tinhtoan.h"
using namespace std;

int main()
{
	//Khai báo đối tượng 
	tinhtoan tt;

	//Khai báo biến
	double dai = 0, rong = 0, chuvihcn = 0, dientichhcn = 0, r = 0, chuviht = 0, dientichht = 0, daylon = 0, daynho = 0, chieucao = 0, dthinhthang = 0;

	cout << "Nhap chieu dai hcn = ";
	cin >> dai;

	cout << "Nhap chieu rong hcn = ";
	cin >> rong;

	//Tính toán 
	chuvihcn = tt.ChuVihcn(dai, rong);
	dientichhcn = tt.DienTichhcn(dai, rong);
	cout << "Chu vi hcn la: " << chuvihcn << endl;
	cout << "Dien tich hcn la: " << dientichhcn << endl;

	cout << "Nhap ban kinh hinh tron r = ";
	cin >> r;

	//Tính toán 
	chuviht = tt.ChuViHT(r);
	dientichht = tt.DientichHT(r);
	cout << "Chu vi hinh tron la: " << chuviht << endl;
	cout << "Dien tich hinh tron la: " << dientichht << endl;

	cout << "Nhap day lon hinh thang = ";
	cin >> daylon;
	cout << "Nhap day nho hinh thang = ";
	cin >> daynho;
	cout << "Nhap chieu cao hinh thang = ";
	cin >> chieucao;
	//Tính toán
	dthinhthang = tt.DientichHinhThang(daylon, daynho, chieucao);
	cout << "Dien tich hinh thang la: " << dthinhthang << endl;

	int giaithua = 0, n = 0;
	cout << "Nhap gia tri can tinh giai thua n = ";
	cin >> n;

	giaithua = tt.GiaiThua(n);

	cout << "Giai thua cua " << n << " la: " << giaithua << endl;
}
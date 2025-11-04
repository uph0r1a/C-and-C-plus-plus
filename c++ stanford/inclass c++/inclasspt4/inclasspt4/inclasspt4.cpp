#include <iostream>
//Khai báo lớp cần làm việc
#include "tinhtoan.h"
#include "hinhtron.h"
using namespace std;

int main()
{
	//Khai báo 1 đối tượng
	tinhtoan tt;

	//Sử dụng các thành phần được định nghĩa trong lớp tinhtoan qua đối tượng tt
	tt.InThongTin();
	//Gọi lần 2
	tt.InThongTin();

	//In 10 câu I love you
	tt.InThongTin(10);

	//Khai báo biến 
	int x = 0, y = 0, tong = 0, hieu = 0;

	cout << "Nhap gia tri x = ";
	cin >> x;
	cout << "Nhap gia tri y = ";
	cin >> y;

	//Tính toán
	tong = tt.TongHaiSo(x, y);
	hieu = tt.HieuHaiSo(x, y);

	cout << "Tong hai so " << x << " va " << y << " la: " << tong << endl;
	cout << "Hieu hai so " << x << " va " << y << " la: " << hieu << endl;

	cout << "Ten cong ty la: " << tt.LayTenCongTy() << endl;

	cout << "Gia tri b = " << tt.b << endl;

	//Khai báo biến
	double bankinh = 0, chuvi = 0, dientich = 0;

	cout << "Nhap ban kinh hinh tron r = ";
	cin >> bankinh;

	//Khai báo 1 đối tượng
	hinhtron ht(bankinh);

	//Gọi hàm để tính toán 
	chuvi = ht.chuvi();
	dientich = ht.dientich();

	cout << "Chu vi hinh tron la: " << chuvi << endl;
	cout << "Dien tich hinh tron la: " << dientich << endl;

	cout << "Cach 2: " << endl;
	ht.InThongTin();

	hinhtron ht2;

	//Gán giá trị bán kính
	ht2.setBanKinh(bankinh);

	ht2.InThongTin();
}

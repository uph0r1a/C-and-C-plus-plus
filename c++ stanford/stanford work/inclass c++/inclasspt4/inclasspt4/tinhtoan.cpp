#include "tinhtoan.h"

//Hàm khởi tạo
tinhtoan::tinhtoan()
{
	cout << "Doi tuong duoc tao ra " << endl;
	cout << "Gia tri cua a la " << this->a << endl;
}

tinhtoan::~tinhtoan()
{
	cout << "Goi ham huy cua lop Tinhtoan" << endl;
}

void tinhtoan::InThongTin()
{
	cout << "Lop va doi tuong trong C++" << endl;
}

void tinhtoan::InThongTin(int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << "I love you - " << i << endl;
	}
}

int tinhtoan::TongHaiSo(int a, int b)
{
	return a + b;
}

int tinhtoan::HieuHaiSo(int a, int b)
{
	return a - b;
}

string tinhtoan::LayTenCongTy()
{
	return "Standford - Day lap trinh";
}
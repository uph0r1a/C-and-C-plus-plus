#include "TinhToan.h"

//Hàm khởi tạo
TinhToan::TinhToan()
{
	cout << "Doi tuong duoc tao ra" << endl;

	cout << "Gia tri cua a = " << this->a << endl;
}

TinhToan::~TinhToan()
{
	cout << "Goi ham huy cua lop TinhToan" << endl;
}

void TinhToan::InThongTin()
{
	cout << "Lop va doi tuong trong C++" << endl;
}

void TinhToan::InThongTin(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "I Love You - " << i << endl;
	}
}

int TinhToan::TongHaiSo(int a, int b)
{
	return a + b;
}

int TinhToan::HieuHaiSo(int a, int b)
{
	return a - b;
}

string TinhToan::LayTenCongTy()
{
	return "Stanford - Day lap trinh";
}
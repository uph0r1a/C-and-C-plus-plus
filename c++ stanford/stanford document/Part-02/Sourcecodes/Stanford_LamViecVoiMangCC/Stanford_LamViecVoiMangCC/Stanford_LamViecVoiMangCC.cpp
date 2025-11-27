// Stanford_LamViecVoiMangCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
   //Ví dụ 1: Khai báo 1 mảng số nguyên gồm 3 phần tử
	int a[3];

	//Gán giá trị cho các phần tử
	a[0] = 2;
	a[1] = 3;
	a[2] = 5;

	cout << "Gia tri cua phan tu thu 2 la: " << a[1] << endl;
	cout << "Gia tri cua phan tu thu 3 la: " << a[2] << endl;

	cout << "Cac phan tu trong mang la: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << "\t";
	}

	cout << endl;

	//Ví dụ 2: Khai báo 1 mảng số thực gồm n phần tử nhập từ bàn phím sau in ra màn hình
	const int MAX = 20;

	//Khai báo mảng
	float arr2[MAX];

	int N = 0;
	NhapLai:
	cout << "Nhap mang gom N phan tu voi N = ";
	cin >> N;

	if (N > MAX)
	{
		cout << "Ban phan nhap so phan nho hon " << MAX << endl;
		goto NhapLai;
	}

	cout << "Nhap cac phan tu: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "arr2[" << i << "] = ";
		cin >> arr2[i];
	}

	cout << "Cac phan tu trong mang gom "<<N<<" phan tu: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr2[i] << "\t";
	}

	cout << endl;
}


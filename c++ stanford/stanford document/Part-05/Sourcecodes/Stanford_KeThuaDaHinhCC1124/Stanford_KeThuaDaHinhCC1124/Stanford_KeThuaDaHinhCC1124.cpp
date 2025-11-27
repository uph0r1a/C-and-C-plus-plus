// Stanford_KeThuaDaHinhCC1124.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "HinhTron.h"
#include "HinhChuNhat.h"
int main()
{
	/*
   //Khai báo 1 đối tượng mèo Tom
	Cat tom;

	//Gán giá trị cho các thuộc tính
	tom.SoMat = 2;
	tom.SoChan = 4;
	tom.MauLong = "Mau xam";

	//Gọi hàm in thông tin
	cout << "Thong tin cua meo Tom: " << endl;
	tom.InThongTin();

	cout << "Tieng keu: " << tom.TiengKeu() << endl;

	//Khai báo đối tượng chó minu
	Dog minu;

	//Gán giá trị cho các thuộc tính
	minu.SoMat = 2;
	minu.SoChan = 4;
	minu.MauLong = "Mau den";

	cout << "Thong tin cho Minu: " << endl;
	minu.InThongTin();
	cout << "Tieng keu: " << minu.TiengKeu() << endl;
	*/

	//Khai báo đối tượng
	HinhTron ht;

	//Khai báo biến
	double banKinh = 0;
	cout << "Nhap ban kinh hinh tron la r = ";
	cin >> banKinh;

	ht.r = banKinh;

	//Gọi hàm in thông tin
	ht.InThongTin();

	//Khai báo biến
	double dai = 0, rong = 0;

	cout << "Nhap chieu dai HCN = ";
	cin >> dai;

	cout << "Nhap chieu rong HCN = ";
	cin >> rong;

	//Khai báo đối tượng
	HinhChuNhat hcn;

	hcn.ChieuDai = dai;
	hcn.ChieuRong = rong;

	//Gọi hàm in thông tin
	hcn.InThongTin();
}


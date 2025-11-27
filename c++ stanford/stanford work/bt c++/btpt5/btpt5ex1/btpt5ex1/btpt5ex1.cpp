//Bài tập 1
//Xây dựng một lớp cơ sở có tên là TinhToan bao gồm các phương thức DienTich,
//InThongTin sau đó tạo ra lớp HinhChuNhat, HinhTron, HinhThang để thực hiện tính
//diện tích cho các hình này kế thừa từ lớp TinhToan.

#include <iostream>
#include "HinhTron.h"
#include "HinhChuNhat.h"
using namespace std;

int main()
{
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

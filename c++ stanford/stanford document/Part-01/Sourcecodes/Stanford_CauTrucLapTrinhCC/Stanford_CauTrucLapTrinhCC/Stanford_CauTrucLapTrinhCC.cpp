// Stanford_CauTrucLapTrinhCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	/*
	//Bài tập 9 - P1
	//Khai báo biến
	double a = 0, b = 0, c = 0, cau9a = 0, cau9b = 0, cau9c = 0, cau9d = 0;

	cout << "Nhap gia tri a = ";
	cin >> a;
	cout << "Nhap gia tri b = ";
	cin >> b;
	cout << "Nhap gia tri c = ";
	cin >> c;

	//Tính toán
	if (c != 0){
		cau9a = pow(a, 2) - 2 * b + (a * b) / c;

		cout << "Ket qua cau 9a la: " << cau9a << endl;
	}

	if (a != 0) {
		cau9b = (pow(b, 2) - 4 * a * c) / (2 * a);
		cout << "Ket qua cau 9b la: " << cau9b << endl;
	}

	if (c >= 0) {
		cau9c = 3 * a - pow(b, 3) - 2 * sqrt(c);
		cout << "Ket qua cau 9c la: " << cau9c << endl;
	}

	if (b != 0 && c != 0) {
		cau9d = a * a / b - (4 * a) / (b * c) + 1;

		if (cau9d >= 0)
		{
			cau9d = sqrt(cau9d);
			cout << "Ket qua cau 9d la: " << cau9d << endl;
		}
	}
	*/

	//Thiết lập hiển thị 2 số sau dấu phẩy
	cout << setiosflags(ios::fixed) << setprecision(2);
	/*
	//Bài tập 11: In ra trung bình cộng, trung bình nhân của 3 số được nhập vào từ bàn phím.
	double trungBinhCong = 0, trungBinhNhan = 0;

	trungBinhCong = (a + b + c) / 3;
	trungBinhNhan = a * b * c;
	trungBinhNhan = pow(trungBinhNhan, 1 / 3.0);

	cout << "Trung binh cong: " << trungBinhCong << endl << "Trung binh nhan: " << trungBinhNhan << endl;

	//Bài tập 12: Viết chương trình nhập cạnh, bán kính và in ra diện tích, chu vi của các hình: hình vuông, hình chữ nhật, hình tròn.

	//Khai báo 1 hằng số
	const float PI = 3.14;

	//Khai báo biến
	double r = 0, chuViHT = 0, dienTichHT = 0, canh = 0, chuViHV = 0, dienTichHV = 0, chieuDai = 0, chieuRong = 0, chuViHCN = 0, dienTichHCN = 0;

	cout << "Nhap ban kinh hinh tron r = ";
	cin >> r;

	cout << "Nhap canh hinh vuong = ";
	cin >> canh;

	cout << "Nhap chieu dai HCN = ";
	cin >> chieuDai;
	cout << "Nhap chieu rong HCN = ";
	cin >> chieuRong;
	//Tính toán
	chuViHT = 2 * PI * r;
	dienTichHT = PI * r * r;
	chuViHV = 4 * canh;
	dienTichHV = canh * canh;
	chuViHCN = 2 * (chieuDai + chieuRong);
	dienTichHCN = chieuDai * chieuRong;
	//In kết quả
	cout << "Chu vi hinh tron la: " << chuViHT << endl << "Dien tich hinh tron: " << dienTichHT << endl;
	cout << "Chu vi hinh vuong la: " << chuViHV << endl << "Dien tich hinh vuong: " << dienTichHV << endl;
	cout << "Chu vi hinh chu nhat la: " << chuViHCN << endl << "Dien tich hinh chu nhat: " << dienTichHCN << endl;

	//Bài tập 15: Nhập vào 4 chữ số. In ra tổng của 4 chữ số này và chữ số hàng chục, hàng đơn vị của tổng(ví dụ 4 chữ số 3, 1, 8, 5 có tổng là 17 và chữ số hàng chục là 1 và hàng đơn vị là 7, cần in ra 17, 1, 7)
	//Khai báo biến
	int so1 = 0, so2 = 0, so3 = 0, so4 = 0, tong = 0, chuc = 0, donVi = 0;
	cout << "Nhap so thu 1 = ";
	cin >> so1;
	cout << "Nhap so thu 2 = ";
	cin >> so2;
	cout << "Nhap so thu 3 = ";
	cin >> so3;
	cout << "Nhap so thu 4 = ";
	cin >> so4;
	//Tính toán
	tong = so1 + so2 + so3 + so4;
	chuc = tong / 10;
	donVi = tong % 10;
	cout << "Tong 4 so la: " << tong << endl;
	cout << "So hang chuc la: " << chuc << endl;
	cout << "So hang don vi la: " << donVi << endl;

	//Bài tập 16: Nhập vào một số nguyên (có 4 chữ số). In ra tổng của 4 chữ số này và chữ số đầu, chữ số cuối(ví dụ số 3185 có tổng các chữ số là 17, đầu và cuối là 3 và 5, kết quả in pra là : 17, 3, 5).
	//3185
	//nghin = 3185/1000 = 3
	//temp = 3185%1000 = 185
	//tram = temp/100 = 185/100 = 1
	//temp = temp%100 = 185%100 = 85
	//chuc = temp/10 = 85/10 = 8
	//donVi = temp%10 = 85%10 = 5
	//Khai báo biến
	int so4ChuSo = 0, temp = 0, nghin = 0, tram = 0, chuc = 0, donVi = 0, tong = 0;
NhapLai:
	cout << "Nhap so gom 4 chu so = ";
	cin >> so4ChuSo;

	if (so4ChuSo < 1000 || so4ChuSo > 9999)
	{
		cout << "Ban can phai nhap so gom 4 chu so" << endl;
		goto NhapLai;
	}

	//Tách số
	nghin = so4ChuSo / 1000;
	temp = so4ChuSo % 1000;
	tram = temp / 100;
	temp = temp % 100;//85
	chuc = temp / 10;//8
	donVi = temp % 10;

	tong = nghin + tram + chuc + donVi;

	cout << "So hang nghin la: " << nghin << endl;
	cout << "So hang don vi la: " << donVi << endl;
	cout << "Tong cua 4 chu so la: " << tong << endl;	*/
	//Bài tập 17: Hãy nhập 2 số a và b. Viết chương trình đổi giá trị của a và b theo 2 cách:
	//Khai báo biến
	int a = 0, b = 0, t = 0;
	cout << "Nhap gia tri a = ";
	cin >> a;
	cout << "Nhap gia tri b = ";
	cin >> b;

	cout << "Truoc khi hoan doi, a = " << a << ", b = " << b << endl;
	//− Dùng biến phụ t : t = a; a = b; b = t;
	t = a;
	a = b;
	b = t;
	cout << "Sau khi hoan doi, a = " << a << ", b = " << b << endl;
	//− Không dùng biến phụ : a = a + b; b = a - b; a = a - b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "Sau khi hoan doi lan 2, a = " << a << ", b = " << b << endl;


}


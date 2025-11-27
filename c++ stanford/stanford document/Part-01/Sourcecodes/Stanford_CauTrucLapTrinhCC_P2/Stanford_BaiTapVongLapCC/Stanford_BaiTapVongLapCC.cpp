// Stanford_BaiTapVongLapCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	/*
	//Bài 4 - P4: Nhập số nguyên dương N. Tính:

	//Khai báo biến
	double S1 = 0, S2 = 0;
	int N = 0;

	cout << "Nhap gia tri day gom N phan tu voi N = ";
	cin >> N;

	//Sử dụng vòng lặp để tính toán
	for (int i = 1; i <= N; i++)
	{
		S1 += i;
		S2 += i * i;
	}

	//Tính toán
	S1 = S1 / N;
	S2 = sqrt(S2);

	//In thông tin
	cout << "Gia tri cua S1 = " << S1 << endl;
	cout << "Gia tri cua S2 = " << S2 << endl;
	//Bài 5: In ra màn hình các số có 2 chữ số sao cho tích của 2 chữ số này bằng 2 lần tổng của 2 chữ số đó(ví dụ số 36 có tích 3 * 6 = 18 gấp 2 lần tổng của nó là 3 + 6 = 9)
	//Khai báo biến
	int chuc = 0, donVi = 0, tong = 0, tich = 0;
	cout << "Cac so co 2 chu so ma tich bang 2 lan tong cua cac so do la: " << endl;
	for (int i = 10; i <= 99; i++)
	{
		chuc = i / 10;
		donVi = i % 10;
		tong = chuc + donVi;
		tich = chuc * donVi;
		if (tich == 2 * tong)
		{
			cout << i << endl;
		}
	}

	//Bài 3: Nhập vào tuổi cha và tuổi con hiện nay sao cho tuổi cha lớn hơn 2 lần tuổi con. Tìm xem bao nhiêu năm nữa tuổi cha sẽ bằng đúng 2 lần tuổi con(ví dụ 30 và 12, sau 6 năm
	//nữa tuổi cha là 36 gấp đôi tuổi con là 18).
	unsigned int tuoiCha = 0, tuoiCon = 0, soNam = 0;

	do
	{
		cout << "Nhap tuoi cha = ";
		cin >> tuoiCha;
		cout << "Nhap tuoi con = ";
		cin >> tuoiCon;
	} while (tuoiCha <= 2 * tuoiCon);

	//Tính toán
	soNam = tuoiCha - 2 * tuoiCon;

	tuoiCha += soNam;//tuoiCha = tuoiCha + soNam
	tuoiCon += soNam;

	cout << "So nam de tuoi cha gap 2 lan tuoi con la: " << soNam << endl;
	cout << "Tuoi cha moi la: " << tuoiCha << endl;
	cout << "Tuoi con moi la: " << tuoiCon << endl;

	//Bài tập 6 - P4
	//Khai báo biến
	double S1 = 0, S2 = 0;
	int N = 0;

	//Thực hiện công việc
	do
	{
		N++;
		S1 += 1 / (2.0 * N - 1);
	} while (S1 < 2.101999);

	cout << "6a. Gia tri lon nhat cua N de thoa man dieu kien la: " << N - 1 << endl;

	//Gán N = 0
	N = 0;

	do
	{
		N++;
		S2 = exp(N) - 1999 * log10(N);
	} while (S2 < 2000);

	cout << "6b. Gia tri lon nhat cua N de thoa man dieu kien la: " << N - 1 << endl;

	//Bài 1: Nhập một kí tự. Cho biết kí tự đó có phải là chữ cái hay không

	//Khai báo biến
	char kiTu, t;
NhapLai:
	cout << "Nhap vao 1 ki tu = ";
	cin.get(kiTu);

	if ((kiTu >= 65 && kiTu <= 90) || (kiTu >= 97 && kiTu <= 122))
	{
		cout << "Day la ki tu chu cai" << endl;
	}
	else
	{
		cout << "Khong phai la ki tu chu cai" << endl;
	}

	cout << "Ban co muon tiep tuc thuc hien ? Nhan 1 de tiep tuc: ";
	//Xóa kí tự thừa
	cin.ignore(1);

	cin.get(t);

	if (t == '1')
	{
		cin.ignore(1);
		goto NhapLai;
	}*/

	cout << "Ve hinh a: " << endl;

	int i = 0, j = 0;
	//In Dòng
	while (i < 8)
	{
		j = 0;
		//In cột
		while (j <= i)
		{
			cout << "*";
			j++;
		}
		//Xuống dòng
		cout << endl;
		i++;
	}

	cout << "Ve hinh b: " << endl;

	i = 0; j = 0;
	//In Dòng
	while (i < 8)
	{
		j = 0;
		//In cột
		while (j < 8-i)
		{
			cout << "*";
			j++;
		}
		//Xuống dòng
		cout << endl;
		i++;
	}
	//Dừng màn hình đến khi nhấn phím tiếp theo
	system("pause");
}


#include<iostream>
//Khai báo thư viện để lấy 2 số sau dấu phẩy
#include<iomanip>
//Khai báo thư viện làm việc với các hàm số học
#include<math.h>

using namespace std;

int main()
{

	//Bài 1
	//− Tuổi của một người − Số lượng cây trong thành phố
	unsigned short tuoiNguoi = 20;
	unsigned int soLuongCay = 100;
	//− Độ dài cạnh một tam giác − Khoảng cách giữa các hành tinh
	float canhTamGiac = 12.345;
	double khoangCach = 14345435.5465;
	//− Một chữ số − Nghiệm x của phương trình bậc 1
	char chuSo = '8';
	float x = 5.65;
	//− Một chữ cái − Biệt thức Δ của phương trình bậc 2
	char chuCai = 'S';
	float delta = 25.66;

	//In các thông tin ra màn hình
	cout << "Tuoi cua nguoi la: " << tuoiNguoi << endl;
	cout << "So luong cay: " << soLuongCay << endl;
	cout << "Canh cua tam giac: " << canhTamGiac << endl << "Khoach cach giua cac hanh tinh: " << khoangCach << endl;
	cout << "Chu so: " << chuSo << "\nNghiem x = " << x << endl;
	cout << "Chu cai: " << chuCai << "\nBiet thuc delta = " << delta << endl;

	//Bài tập 2: Viết câu lệnh nhập vào 4 giá trị lần lượt là số thực, nguyên, nguyên dài và kí tự. In ra màn hình các giá trị này để kiểm tra.
	//Khai báo biến
	float soThuc = 0;
	short soNguyen = 0;
	long soNguyenDai = 0;
	char kiTu;

	cout << "Nhap so thuc = ";
	cin >> soThuc;

	cout << "Nhap so nguyen = ";
	cin >> soNguyen;

	cout << "Nhap so nguyen dai = ";
	cin >> soNguyenDai;

	//Xóa kí tự thừa đi
	cin.ignore(1);

	cout << "Nhap ki tu = ";
	cin.get(kiTu);

	//In kết quả
	cout << "So thuc la: " << soThuc << endl;
	cout << "So nguyen la: " << soNguyen << endl;
	cout << "So nguyen dai la: " << soNguyenDai << endl;
	cout << "Ki tu la: " << kiTu << endl;

	//Bài tập 4: Viết chương trình nhập vào một kí tự. In ra kí tự đó và mã ascii của nó.
	cout << "Ki tu " << kiTu << " co ma ascii la: " << (int)kiTu << endl;

	//Bài tập 5: Viết chương trình nhập vào hai số thực. In ra hai số thực đó với 2 số lẻ và cách nhau 5 cột.
	//Khai báo biến
	//Thiết lập hiển thị 2 số sau dấu phẩy
	//cout<<setiosflags(ios::fixed)<<setprecision(2);


	float soThuc1 = 0, soThuc2 = 0;

	cout << "Nhap so thuc 1 = ";
	cin >> soThuc1;

	cout << "Nhap so thuc 2 = ";
	cin >> soThuc2;


	cout << "So thuc 1: " << soThuc1 << "\t" << "So thuc 2: " << soThuc2 << endl;

	//Bài tập 7: Nhập a, b, c. In ra màn hình dòng chữ phương trình có dạng ax^2 + bx + c = 0
	//Khai báo biến
	float a = 0, b = 0, c = 0;

	cout << "Nhap gia tri a = ";
	cin >> a;
	cout << "Nhap gia tri b = ";
	cin >> b;
	cout << "Nhap gia tri c = ";
	cin >> c;

	cout << "Phuong trinh: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

	//Bài tập 8
	//Khai báo biến
	float cau8a = 0, cau8b = 0;

	cau8a = sqrt(3.0 + sqrt(3.0 + sqrt(3.0)));

	cau8b = 1 / (2.0 + 1 / (2.0 + 1 / 2.0));

	cout << "Ket qua cau 8a = " << cau8a << endl;
	cout << "Ket qua cau 8b = " << cau8b << endl;

	//Thiết lập hiển thị 3 số sau dấu phẩy
	cout << setiosflags(ios::fixed) << setprecision(3);

	//Bài tập 9
	//Khai báo biến
	float a = 0, b = 0, c = 0, cau9a = 0, cau9b = 0, cau9c = 0, cau9d = 0;

	cout << "Nhap gia tri a = ";
	cin >> a;

	cout << "Nhap gia tri b = ";
	cin >> b;

	cout << "Nhap gia tri c = ";
	cin >> c;

	//Thực hiện tính toán
	cau9a = pow(a, 2) - 2 * b + (a * b) / c;
	cau9b = 3 * a - pow(b, 3) - 2 * sqrt(c);
	cau9c = (b * b - 4 * a * 4) / (2 * a);
	cau9d = pow(a, 2) / b - (4 * a) / (b * c) + 1;
	cau9d = sqrt(cau9d);

	cout << "Cau 9a = " << cau9a << endl;
	cout << "Cau 9b = " << cau9b << endl;
	cout << "Cau 9c = " << cau9c << endl;
	cout << "Cau 9d = " << cau9d << endl;

	//Bài tập 10: In ra tổng, tích, hiệu và thương của 2 số được nhập vào từ bàn phím.

	//Khai báo biến
	float a = 0, b = 0, tong = 0, hieu = 0, tich = 0, thuong = 0;

	cout << "Nhap gia tri a = ";
	cin >> a;

	cout << "Nhap gia tri b = ";
	cin >> b;

	//Tính toán
	tong = a + b;
	hieu = a - b;
	tich = a * b;
	thuong = a / b;

	cout << "Tong hai so " << a << " va " << b << " la: " << tong << endl;
	cout << "Hieu hai so " << a << " va " << b << " la: " << hieu << endl;
	cout << "Tich hai so " << a << " va " << b << " la: " << tich << endl;
	cout << "Thuong hai so " << a << " va " << b << " la: " << thuong << endl;

	//Bài tập 11: In ra trung bình cộng, trung bình nhân của 3 số được nhập vào từ bàn phím.
	//Khai báo biến
	float a = 0, b = 0, c = 0, trungBinhCong = 0, trungBinhNhan = 0;

	cout << "Nhap gia tri a = ";
	cin >> a;

	cout << "Nhap gia tri b = ";
	cin >> b;

	cout << "Nhap gia tri c = ";
	cin >> c;

	trungBinhCong = (a + b + c) / 3;
	trungBinhNhan = pow((a * b * c), 1 / 3.0);

	cout << "Trung binh cong la: " << trungBinhCong << endl;
	cout << "Trung binh nhan la: " << trungBinhNhan << endl;

	//Bài tập 12: Viết chương trình nhập cạnh, bán kính và in ra diện tích, chu vi của các hình: hình vuông, hình chữ nhật, hình tròn.
	float canh = 0, dtHV = 0, chuViHV = 0;

	cout << "Nhap canh hinh vuong = ";
	cin >> canh;

	//Tính toán
	dtHV = canh * canh;
	chuViHV = 4 * canh;

	cout << "Chu vi hinh vuong la: " << chuViHV << endl;
	cout << "Dien tich hinh vuong la: " << dtHV << endl;

	//Hình tròn
	float r = 0, dtHT = 0, chuViHT = 0;
	//Khai báo hằng số
	const float PI = 3.14;

	cout << "Nhap ban kinh r = ";
	cin >> r;

	//Tính toán
	chuViHT = 2 * PI * r;
	dtHT = PI * r * r;

	cout << "Chu vi hinh tron la: " << chuViHT << endl;
	cout << "Dien tich hinh tron la: " << dtHT << endl;

	//Dừng đến khi nhấn phím tiếp theo
	system("pause");

	return 0;
}


#include <iostream>
//Khai báo thư viện để sử dụng hàm số học
#include <math.h>
#include<iomanip>
using namespace std;

int main()
{

	//Ví dụ 3: Giải phương trình bậc nhất ax + b = c với a khác 0
	//Khai báo biến
	float a = 0, b = 0, c = 0, x = 0;

	cout << "Nhap he so a = ";
	cin >> a;

	if (a != 0)
	{
		cout << "Nhap he so b = ";
		cin >> b;

		cout << "Nhap he so c = ";
		cin >> c;

		//Giải nghiệm
		x = (c - b) / a;

		cout << "Nghiem cua phuong trinh bac nhat la: x = " << x << endl;
	}
	else
	{
		cout << "Ban can phai nhap he so a khac 0" << endl;
	}

	//Thiết lập lấy 2 só sau dấu phẩy
	cout << setiosflags(ios::fixed) << setprecision(2);
	//Bài tập 8: Viết chương trình tính và in ra giá trị các biểu thức sau với 2 số lẻ:
	//Khai báo biến
	float cau8a = 0, cau8b = 0;

	//Tính toán
	cau8a = sqrt(3.0 + sqrt(3.0 + sqrt(3.0)));
	cau8b = 1 / (2.0 + 1 / (2.0 + 1 / 2.0));

	//pow(2, 3) = 8

	cout << "Ket qua cau 8a = " << cau8a << endl;
	cout << "Ket qua cau 8b = " << cau8b << endl;

	return 0;
}


#include<stdio.h>
#include<conio.h>
#include<iostream>
//Khai báo lấy bao nhiêu số lẻ sau dấu phẩy
#include<iomanip>
using namespace std;

int main()
{

	//Khai báo biến tuổi của sinh viên
	int tuoiSV = 20;

	cout << "Tuoi sinh vien la: " << tuoiSV << endl;

	//Gán giá trị mới
	tuoiSV = 21;

	cout << "Tuoi sinh vien moi la: " << tuoiSV << endl;

	cout << "Nhap tuoi sinh vien = ";

	//Nhập tuổi
	cin >> tuoiSV;

	cout << "Tuoi moi sinh vien nhap la: " << tuoiSV << endl;

	//In thông tin sử dụng C
	printf("Chao mung cac ban den voi lap trinh C\n");

	//Khai báo biến
	int soCay = 0;

	printf("Nhap so luong cay = ");

	scanf("%d", &soCay);

	printf("So luong cay nhap la: %d\n", soCay);


	cout << "Xin chao cac ban !" << endl;
	cout << "Chuc cac ban hoc tap tot !" << endl;

	//Xóa thông tin trên màn hình trước đó
	system("cls");

	//clrscr();
	//Khai báo kí tự
	int soNha = 0;
	char kiTu;

	cout << "Nhap so nha = ";
	cin >> soNha;

	//Xóa kí tự thừa
	cin.ignore(1);

	cout << "Nhap ki tu la = ";
	cin.get(kiTu);

	cout << "So nha la: " << soNha << endl;
	cout << "Ki tu la: " << kiTu << endl;

	cout << "Kich thuoc kieu char la: " << sizeof(char) << " byte" << endl;
	cout << "Kich thuoc kieu short la: " << sizeof(short) << " byte" << endl;
	cout << "Kich thuoc kieu int la: " << sizeof(int) << " byte" << endl;
	cout << "Kich thuoc kieu uint la: " << sizeof(unsigned int) << " byte" << endl;

	//Thiết lập lấy 2 só sau dấu phẩy
	cout << setiosflags(ios::fixed) << setprecision(2);


	//Khai báo biến số lẻ
	//float diemTrungBinh = 8.6835;
	//cout <<"Diem trung binh la: "<<diemTrungBinh<<endl;

	//Bài tập 1: Viết câu lệnh khai báo biến để lưu các giá trị sau:
	//− Tuổi của một người − Số lượng cây trong thành phố
	unsigned short tuoiNguoi = 20;
	unsigned int soLuongCay = 10000;
	//− Độ dài cạnh một tam giác − Khoảng cách giữa các hành tinh
	float canhTamGiac = 24.5665;
	double khoangCach = 5464646546.5675;
	//− Một chữ số − Nghiệm x của phương trình bậc 1
	char chuSo = '9';
	float x = 12.3454;
	//− Một chữ cái − Biệt thức Δ của phương trình bậc 2
	char chuCai = 'A';
	float delta = 25.56765;

	cout << "Tuoi nguoi la: " << tuoiNguoi << endl;
	cout << "So luong cay la: " << soLuongCay << endl;
	cout << "Canh tam giac la: " << canhTamGiac << endl;
	cout << "Khoang cach giua cac hanh tinh: " << khoangCach << endl;
	cout << "Chu so la: " << chuSo << endl << "Chu cai la: " << chuCai << endl;
	cout << "Nghiem cua x = " << x << endl;
	cout << "Biet thuc delta = " << delta << endl;

	//Bài tập 2: Viết câu lệnh nhập vào 4 giá trị lần lượt là số thực, nguyên, nguyên dài và kí
	//tự. In ra màn hình các giá trị này để kiểm tra.
	//Khai báo biến
	float soThuc = 0;
	int soNguyen = 0;
	long soNguyenDai = 0;
	char kiTu;

	cout << "Nhap 1 so thuc la: ";
	cin >> soThuc;

	cout << "Nhap 1 so nguyen la: ";
	cin >> soNguyen;

	cout << "Nhap 1 so nguyen dai la: ";
	cin >> soNguyenDai;

	cout << "Nhap ki tu la: ";
	//Xóa kí tự thừa xuống dòng
	cin.ignore(1);

	//Nhập kí tự
	cin.get(kiTu);

	//In thông tin ra màn hình
	cout << "So thuc la: " << soThuc << endl;
	cout << "So nguyen: " << soNguyen << endl << "So nguyen dai: " << soNguyenDai << endl;
	cout << "Ki tu la: " << kiTu << endl;

	//Bài tập 4: Viết chương trình nhập vào một kí tự. In ra kí tự đó và mã ascii của nó.
	cout << "Ki tu " << kiTu << " co ma ascii la: " << (int)kiTu << endl;


	//Ví dụ 1: Nhập vào 2 số thực a và b sau đó tính tổng, hiệu, tích, thương của 2 số đó
	//Khai báo biến
	float a = 0, b = 0, tong = 0, hieu = 0, tich = 0, thuong = 0;

	//Nhập thông tin từ bàn phím
	cout << "Nhap gia tri a = ";
	cin >> a;
	cout << "Nhap gia tri b = ";
	cin >> b;

	//Tính toán
	tong = a + b;
	hieu = a - b;
	tich = a * b;
	thuong = a / b;

	//In kết quả
	cout << "Tong hai so " << a << " va " << b << " la: " << tong << endl;
	cout << "Hieu hai so " << a << " va " << b << " la: " << hieu << endl;
	cout << "Tich hai so " << a << " va " << b << " la: " << tich << endl;
	cout << "Thuong hai so " << a << " va " << b << " la: " << thuong << endl;


	//Ví dụ 2: Nhập chiều cao của Dũng và Trí sau đó kiểm tra xem ai cao hơn rồi in ra màn hình
	//Khai báo biến
	float chieuCaoDung = 0, chieuCaoTri = 0;

	cout << "Nhap chieu cao cua Dung = ";
	cin >> chieuCaoDung;

	cout << "Nhap chieu cao cua Tri = ";
	cin >> chieuCaoTri;

	if (chieuCaoDung == chieuCaoTri)//true
	{
		cout << "Chieu cao cua Dung va Tri bang nhau" << endl;
	}
	else
	{
		if (chieuCaoDung > chieuCaoTri)//true
		{
			cout << "Chieu cao cua Dung cao hon Tri" << endl;
		}
		else
		{
			cout << "Chieu cao cua Dung thap hon Tri" << endl;
		}
	}

	return 0;
}
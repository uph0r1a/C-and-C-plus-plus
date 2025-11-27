// Stanford_KieuDuLieuNCVaHamCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
//Khai báo kiểu cấu trúc
struct ToaDo
{
	int x, y;
};

struct NgayThang
{
	int Ngay, Thang, Nam;
};

struct ThiSinh
{
	long SoBD;
	string HoTen;
	string DiaChi;
	float Toan, Ly, Hoa;
};

//Định nghĩa các hàm xử lý công việc
/*
Dạng 1: Hàm không có giá trị trả về và không có tham số truyền vào
*/
void inThongTin()
{
	cout << "Hom nay troi dep qua !" << endl;
}

/*
Dạng 2: Hàm không có giá trị trả về và có tham số truyền vào
*/
void inThongTin(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "Hom nay troi dep qua - " << i << endl;
	}
}

/*
Dạng 3: Hàm có giá trị trả về và không có tham số truyền vào
*/
string LayTenCongTy()
{
	return "Stanford - Day kinh nghiem lap trinh";
}

/*
Dạng 4: Hàm có giá trị trả về và có tham số truyền vào
*/
int TongHaiSo(int a, int b)
{
	int tong = 0;
	tong = a + b;
	return tong;
}

float TongHaiSo(float a, float b)
{
	return a + b;
}

/*
Hàm hoán đổi 2 số cho nhau
*/
void HoanDoi(int &x, int &y)
{
	int t = 0;
	t = x;
	x = y;
	y = t;
}

void HoanDoi(int* x, int* y)
{
	int t = 0;
	t = *x;
	*x = *y;
	*y = t;
}

//Khai báo hàm để sử dụng
void NhapThiSinh(ThiSinh& ts);
void NhapDanhSachThiSinh(ThiSinh ds[], int n);
void InDanhSachThiSinh(ThiSinh ds[], int n);

int main()
{
	/*
   //Khai báo biến
	int x = 20;

   //Khai báo 1 biến con trỏ
	int* p;

	//Thực hiện trỏ con trỏ p vào x
	p = &x;

	cout << "Gia tri cua x = " << x << endl;
	cout << "Dia chi cua x = " << &x << endl;
	cout << "Gia tri luu tru trong con tro p = " << p << endl;
	cout << "Gia tri cua x thong qua con tro p = " << *p << endl;

	//Ví dụ 2: Sử dụng con trỏ đến mảng
	const int MAX = 3;

	int arr[MAX] = { 100, 200, 300 };

	//Khai báo con trỏ
	int* p2;

	//Thực hiện con trỏ đến mảng
	p2 = arr;//p2 = &arr[0]

	cout << "Dia chi luu tru trong con tro p2 la: " << p2 << endl;
	cout << "Gia tri luu tru trong con tro p2 la: " << *p2 << endl;

	//Sử dụng toán tử
	p2++;
	cout << "Sau khi dung toan tu p2++: " << endl;
	cout << "Dia chi luu tru trong con tro p2 la: " << p2 << endl;
	cout << "Gia tri luu tru trong con tro p2 la: " << *p2 << endl;
	p2--;
	cout << "Cac phan tu cua mang la: " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Dia chi: " << p2 << endl;
		cout << "Gia tri: " << *p2 << endl;
		p2++;
	}


	string tenCongTy = "Stanford - Day lap trinh";

	string* p3;

	//Thực hiện trỏ đến tenCongTy
	p3 = &tenCongTy;

	cout << "Dia chi trong con tro p3 la: " << p3 << endl;
	cout << "Gia tri trong con tro p3 la: " << *p3 << endl;

	char s[10];

	//Gán giá trị cho xâu
	strcpy_s(s, "Stanford");

	char* p4;

	p4 = &s[0];

	cout << "Cac ki tu cua xau s la: " << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << "Dia chi: " << (void*)p4 << endl;
		cout << "Gia tri: " << *p4 << endl;
		p4++;
	}

	//Ví dụ 5: Sử dụng mảng con trỏ

	int* p5[MAX];

	//Thực hiện trỏ từng phần tử mảng cho mảng con trỏ
	for (int i = 0; i < 3; i++)
	{
		p5[i] = &arr[i];
	}

	cout << "In cac phan tu cua mang qua mang con tro p5: " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << p5[i] << endl;
		cout << *p5[i] << endl;
	}

	//Khai báo 1 biến tham chiếu
	int& r = x;

	cout << "Gia tri cua x qua r la: " << r << endl;

	r++;

	cout << "Gia tri cua x = " << x << endl;

	//Sử dụng kiểu cấu trúc
	ToaDo A;

	//Gán giá trị
	A.x = 100;
	A.y = 200;

	cout << "Toa do cua diem A la: A(" << A.x << "," << A.y << ")" << endl;

	//Khai báo ngày tháng
	NgayThang now;
	//Gán giá trị
	now.Ngay = 4;
	now.Thang = 1;
	now.Nam = 2025;

	cout << "Ngay hom nay la: " << now.Ngay << "/" << now.Thang << "/" << now.Nam << endl;

	//Khai báo thí sinh
	ThiSinh nam;

	//Gán giá trị cho các thành phần
	nam.SoBD = 1000;
	nam.HoTen = "Vu Van Nam";
	nam.DiaChi = "Ha Noi";
	nam.Toan = 9;
	nam.Ly = 8;
	nam.Hoa = 7;

	cout << "Thong tin cua Thi sinh la: " << endl;
	cout << "So BD: " << nam.SoBD << endl;
	cout << "Ho ten: " << nam.HoTen << endl;
	cout << "Dia Chi: " << nam.DiaChi << endl;
	cout << "Toan: " << nam.Toan << endl;
	cout << "Ly: " << nam.Ly << endl;
	cout << "Hoa: " << nam.Hoa << endl;

	const int MAX = 2;
	ThiSinh ds[MAX];

	cout << "Nhap danh sach cac thi sinh: " << endl;

	for (int i = 0; i < MAX; i++)
	{
		cout << "So BD: ";
		cin >> ds[i].SoBD;

		cout << "Ho ten: ";
		cin.ignore(1);
		getline(cin, ds[i].HoTen);
		cout << "Dia chi: ";
		getline(cin, ds[i].DiaChi);

		cout << "Dien toan: ";
		cin >> ds[i].Toan;
		cout << "Dien ly: ";
		cin >> ds[i].Ly;
		cout << "Dien hoa: ";
		cin >> ds[i].Hoa;
	}

	cout << "Danh sach thi sinh: " << endl;
	cout << left<<setw(10) <<"So BD"<<setw(25)<<"Ho ten" << setw(15) << "Dia chi" << setw(10) << "Diem Toan" << setw(10) << "Diem Ly" << setw(10) << "Diem Hoa"<< endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << left << setw(10) <<ds[i].SoBD << setw(25) << ds[i].HoTen << setw(15) << ds[i].DiaChi << setw(10) << ds[i].Toan << setw(10) << ds[i].Ly << setw(10) << ds[i].Hoa<< endl;
	}

	//Sử dụng hàm
	//Gọi hàm
	inThongTin();
	//Gọi lần 2
	inThongTin();

	inThongTin(10);

	string ten = LayTenCongTy();

	cout << "Ten cong ty la: " << ten << endl;

	//Khai báo biến
	int x = 0, y = 0, tong;

	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	//Gọi hàm
	tong = TongHaiSo(x, y);

	cout << "Tong hai so " << x << " va " << y << " la: " << tong << endl;

	cout << "Truoc hoan doi, x = " << x << ", y = " << y << endl;
	//Gọi hàm hoán đổi
	HoanDoi(x, y);
	cout << "Sau hoan doi, x = " << x << ", y = " << y << endl;

	int* x1, *y1;

	//Thực hiện trỏ
	x1 = &x;
	y1 = &y;

	//Gọi hàm hoán đổi
	HoanDoi(x1, y1);

	cout << "Sau hoan doi lan 2, x = " << x << ", y = " << y << endl;*/

	//Khai báo danh sách
	const int MAX = 2;
	ThiSinh ds[MAX];

	//Gọi hàm
	NhapDanhSachThiSinh(ds, MAX);
	InDanhSachThiSinh(ds, MAX);
}

//Hàm nhập thí sinh
void NhapThiSinh(ThiSinh& ts)
{
	cout << "So BD: ";
	cin >> ts.SoBD;

	cout << "Ho ten: ";
	cin.ignore(1);
	getline(cin, ts.HoTen);
	cout << "Dia chi: ";
	getline(cin, ts.DiaChi);

	cout << "Dien toan: ";
	cin >> ts.Toan;
	cout << "Dien ly: ";
	cin >> ts.Ly;
	cout << "Dien hoa: ";
	cin >> ts.Hoa;
}

//Hàm nhập danh sách thí sinh
void NhapDanhSachThiSinh(ThiSinh ds[], int n)
{
	cout << "Nhap danh sach cac thi sinh: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Thi sinh " << (i + 1)<<": " << endl;
		NhapThiSinh(ds[i]);
	}
}

void InDanhSachThiSinh(ThiSinh ds[], int n)
{
	cout << "Danh sach thi sinh: " << endl;
	cout << left << setw(10) << "So BD" << setw(25) << "Ho ten" << setw(15) << "Dia chi" << setw(10) << "Diem Toan" << setw(10) << "Diem Ly" << setw(10) << "Diem Hoa" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << left << setw(10) << ds[i].SoBD << setw(25) << ds[i].HoTen << setw(15) << ds[i].DiaChi << setw(10) << ds[i].Toan << setw(10) << ds[i].Ly << setw(10) << ds[i].Hoa << endl;
	}
}


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
void HoanDoi(int& x, int& y)
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
	cout << left << setw(10) << "So BD" << setw(25) << "Ho ten" << setw(15) << "Dia chi" << setw(10) << "Diem Toan" << setw(10) << "Diem Ly" << setw(10) << "Diem Hoa" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << left << setw(10) << ds[i].SoBD << setw(25) << ds[i].HoTen << setw(15) << ds[i].DiaChi << setw(10) << ds[i].Toan << setw(10) << ds[i].Ly << setw(10) << ds[i].Hoa << endl;
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

	int* x1, * y1;

	//Thực hiện trỏ
	x1 = &x;
	y1 = &y;

	//Gọi hàm hoán đổi
	HoanDoi(x1, y1);

	cout << "Sau hoan doi lan 2, x = " << x << ", y = " << y << endl;

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
		cout << "Thi sinh " << (i + 1) << ": " << endl;
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



#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

int TimUocSoChungLonNhat(int a, int b)
{
	int min = a < b ? a : b;

	int t = 0;

	while (b != 0)
	{
		t = b;
		b = b % a;
		a = t;
	}
	return a;
}
int TimUocSoChungLonNhat2(int a, int b)
{
	int min = a < b ? a : b, uocChungLonNhat = 0;

	//Duyệt vòng lặp
	for (int i = min; i >= 1;i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			uocChungLonNhat = i;
			break;
		}
	}
	return uocChungLonNhat;
}

//Kiểm tra năm nhuận
bool KiemTraNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 100 == 0 && nam % 400 == 0))
	{
		return true;
	}
	return false;
}

void TimNamNhuanTheoKhoang(int tuNam, int denNam)
{
	cout << "Cac nam nhuan tu nam" << tuNam << "den nam" << denNam << ":" << endl;

	for (int i = tuNam; i <= denNam; i++)
	{
		if (KiemTraNamNhuan(i))
		{
			cout << i << endl;
		}
	}
}

void GiaiPhuongTrinhBacHai()
{
	//Khai báo biến
	double a = 0, b = 0, c = 0, delta = 0, x1 = 0, x2 = 0;

	cout << "Nhap he so a = ";
	cin >> a;
	cout << "Nhap he so b = ";
	cin >> b;
	cout << "Nhap he so c = ";
	cin >> c;

	//Tính delta
	delta = pow(b, 2) - 4 * a * c;

	if (delta < 0)
	{
		cout << "Phuong trinh vo nghiem" << endl;
	}
	else if (delta == 0)
	{
		cout << "Phuong trinh co nghiem kep la: " << -b / 2 * a << endl;
	}
	else
	{
		x1 = (-b + sqrt(delta)) / 2 * a;
		x2 = (-b - sqrt(delta)) / 2 * a;

		cout << "Phuong trinh co 2 nghiem phan biet x1 = " << x1 << " x2  = " << x2 << endl;
	}
}

void TinhDienTich()
{
	double r = 0, stron = 0, svuong = 0;
	const float pi = 3.14;

	cout << "Nhap ban kinh hinh tron: ";
	cin >> r;

	if (r > 0)
	{
		stron = pi * pow(r, 2);
		svuong = pow(r * 2, 2);

		cout << "Dien tich gioi han la: " << svuong - stron << endl;
	}
	else
	{
		cout << "Ban kinh phai lon hon 0" << endl;
	}
}

void Base10toBase2()
{
	int so = 0, i = 0, base2[32];

	cout << "Nhap so can chuyen: ";
	cin >> so;

	while (so > 0)
	{
		base2[i] = so % 2;
		so = so / 2;
		i++;
	}

	cout << "So nhi phan la: ";
	for (int j = i - 1; j >= 0; j--)
		cout << base2[j];
	cout << endl;
}

int Base2toBase10(string soNhiPhan)
{
	int soThapPhan = 0;

	for (int i = 0; i < soNhiPhan.length(); i++)
	{
		if (soNhiPhan[i] == '1')
		{
			soThapPhan += (int)pow(2, soNhiPhan.length() - i - 1);
		}
	}
	return soThapPhan;
}
int main()
{
	//Khai báo biến
	int a = 0, b = 0, uocChungLN = 0;

	cout << "Nhap so thu 1 = ";
	cin >> a;
	cout << "Nhap so thu 2 = ";
	cin >> b;

	//Gọi hàm để tìm ước chung lơn nhất
	uocChungLN = TimUocSoChungLonNhat2(a, b);

	cout << "Uoc so chung lon nhat cua " << a << " va " << b << " la: " << uocChungLN << endl;

	int tuNam = 0, denNam = 0;
	cout << "Nhap tu nam tinh nam nhuan = ";
	cin >> tuNam;

	cout << "den nam = ";
	cin >> denNam;

	//Gọi hàm
	TimNamNhuanTheoKhoang(tuNam, denNam);

	//Gọi hàm
	GiaiPhuongTrinhBacHai();

	//Gọi hàm
	TinhDienTich();

	//Gọi hàm
	Base10toBase2();

	//Xóa kí tự thừa
	cin.ignore(1);
	string soNhiPhan;
	cout << "Nhap so nhi phan can chuyen = ";
	getline(cin, soNhiPhan);

	//Gọi hàm
	int soThapPhan = 0;

	soThapPhan = Base2toBase10(soNhiPhan);

	cout << "So thap phan la: " << soThapPhan << endl;
}

#include <iostream>
using namespace std;

int main()
{
	//Sử dụng cấp phát động vs biến
	int* pr = new int;

	//Gán giá trị
	*pr = 8;

	cout << "Gia tri cua pr la: " << *pr << endl;

	//Xóa vùng nhớ cấp phát
	delete pr;

	cout << "Sau khi xoa vung nho. Gia tri cua pr la: " << *pr << endl;

	//Sử dụng cấp phát động vs mảng 
	int* p2 = new int[2];

	//Gán giá trị cho các phần tử 
	p2[0] = 2;
	p2[1] = 5;

	cout << "Gia tri cua phan tu 1 la: " << p2[0] << endl;

	cout << "Cac phan tu cua mang la: " << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << p2[i] << endl;
	}

	//Khai báo 1 mảng số thực gồm n phần tử vs n nhập từ bàn phím 
	int n = 0;
	cout << "Nhap mang gom n phan tu = ";
	cin >> n;

	//Khai báo 1 mảng động 
	float* p3 = new float[n];

	cout << "Nhap gia tri cua cac phan tu: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "p3[" << i << "] = ";
		cin >> p3[i];
	}

	cout << "Cac phan tu cua mang gom " << n << " phan tu la: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << p3[i] << "\t";
	}
	cout << endl;
}
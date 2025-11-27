//Bài tập 1: Hãy khai báo biến kí tự ch và con trỏ kiểu kí tự pc trỏ vào biến ch. Viết ra các
//cách gán giá trị ‘A’ cho biến ch.
#include <iostream>
using namespace std;

int main()
{
	char ch;

	cout << "Nhap ki tu = ";
	cin.get(ch);

	cout << "Ki tu la: " << ch << endl;
	char* pc;

	pc = &ch;

	*pc = 'A';

	cout << "Dia chi luu trong con tro pc la: " << (void*)pc << endl;
	cout << "Gia tri lay qua con tro pc la: " << *pc << endl;
	cout << "Ki tu la: " << ch << endl;
}

/*Bài tập 2: Cho mảng nguyên cost.Viết ra các cách gán giá trị 100 cho phần tử thứ 3 của
//mảng.
#include <iostream>
using namespace std;
int main()
{
	const int MAX = 3;

	int cost[MAX];

	cost[2] = 100;

	int* p2;

	p2 = &cost[2];

	cout << "Gia tri phan tu thu 3 la: " << cost[2] << endl;
	*p2 = 200;

	cout << "Gia tri cua phan tu thu 3 sau khi thay doi gia tri qua con tro p2 la: " << cost[2] << endl;
}

//Bài tập 3: Cho xâu kí tự (dạng con trỏ) s. Hãy in ngược xâu ra màn hình.
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string strChuoi;

	cout << "Nhap vao 1 chuoi: ";
	getline(cin, strChuoi);

	string* p;

	p = &strChuoi;

	cout << "Chuoi la: " << *p << endl;

	cout << "Chuoi xuoi la: " << endl;
	for (int i = strChuoi.length() - 1; i >= 0; i--)
	{
		cout << strChuoi[i];
	}

	char s[10];

	strcpy_s(s, "Standford");

	char* p2;
	p2 = &s[7];

	cout << endl << "Chuoi dao nguoc 2: " << endl;
	for (int i = 7; i >= 0; i--)
	{
		cout << *p2;
		p2--;
	}
}

//Bài tập 4: Viết hàm tìm UCLN của 2 số. áp dụng hàm này để tìm UCLN của 4 số nhập
//từ bàn phím.
#include <iostream>
using namespace std;

int UCLN(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int a, b, c, d;

	cout << "Nhap 4 so nguyen: ";
	cin >> a >> b >> c >> d;

	int ucln_ab = UCLN(a, b);
	int ucln_abc = UCLN(ucln_ab, c);
	int ucln_abcd = UCLN(ucln_abc, d);

	cout << "UCLN cua 4 so la: " << ucln_abcd << endl;

	return 0;
}


//Bài tập 5: Viết hàm kiểm tra một năm có là năm nhuận. In ra các năm nhuận từ năm
//1000 đến 2000.
#include <iostream>
using namespace std;

bool laNamNhuan(int nam) {
	return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

void inNamNhuan() {
	cout << "Cac nam nhuan tu 1000 den 2000 la:\n";
	for (int nam = 1000; nam <= 2000; nam++) {
		if (laNamNhuan(nam)) {
			cout << nam << " ";
		}
	}
	cout << endl;
}

int main() {
	inNamNhuan();
	return 0;
}


//Bài tập 6: Viết hàm tráo đổi giá trị của 2 số. Sau đó thực hiện sắp xếp dãy số cho trước.
#include <iostream>
using namespace std;

void traoDoi(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sapXep(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		traoDoi(arr[i], arr[minIndex]);
	}
}

void inDaySo(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 7, 2, 9, 1, 5, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Day so ban dau: ";
	inDaySo(arr, n);

	sapXep(arr, n);

	cout << "Day so sau khi sap xep: ";
	inDaySo(arr, n);

	return 0;
}


//Bài tập 7:
//Viết hàm giải phương trình bậc 2. Sau đó thực hiện tính toán trên giao diện cho phép
//người dùng nhập thông tin sau khi thực hiện tính toán sẽ hiển thị kết quả deltal và nghiệm
//của phương trình.
#include <iostream>
#include <cmath>
using namespace std;

void giaiPhuongTrinhBac2(float a, float b, float c) {
	if (a == 0) {
		if (b == 0) {
			cout << "Phuong trinh vo nghiem." << endl;
		}
		else {
			cout << "Phuong trinh co nghiem duy nhat: x = " << -c / b << endl;
		}
		return;
	}

	float delta = b * b - 4 * a * c;
	cout << "Delta = " << delta << endl;

	if (delta < 0) {
		cout << "Phuong trinh vo nghiem." << endl;
	}
	else if (delta == 0) {
		float x = -b / (2 * a);
		cout << "Phuong trinh co nghiem kep: x = " << x << endl;
	}
	else {
		float x1 = (-b + sqrt(delta)) / (2 * a);
		float x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "Phuong trinh co 2 nghiem phan biet:\n";
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
}

int main() {
	float a, b, c;

	cout << "GIAI PHUONG TRINH BAC 2: ax^2 + bx + c = 0\n";
	cout << "Nhap he so a: ";
	cin >> a;
	cout << "Nhap he so b: ";
	cin >> b;
	cout << "Nhap he so c: ";
	cin >> c;

	giaiPhuongTrinhBac2(a, b, c);

	return 0;
}


//Bài tập 8:
//Tính phần diện tích giới hạn bởi hình tròn bán kính R và hình vuông ngoại tiếp của nó.
#include <iostream>
#include <cmath> 
using namespace std;

#define PI 3.14159265358979323846 

double tinhDienTichGioiHan(double R) {
	double dienTichVuong = 4 * R * R;
	double dienTichTron = PI * R * R;
	return dienTichVuong - dienTichTron;
}

int main() {
	double R;

	cout << "Nhap ban kinh R: ";
	cin >> R;

	if (R <= 0) {
		cout << "Ban kinh phai lon hon 0!" << endl;
		return 1;
	}

	double dienTich = tinhDienTichGioiHan(R);
	cout << "Dien tich gioi han: " << dienTich << endl;

	return 0;
}


//Bài tập 9:
//Viết một hàm chuyển dữ liệu số thập phân sang số nhị phân
#include <iostream>
using namespace std;

void chuyenSangNhiPhan(int n) {
	if (n == 0) {
		cout << "0";
		return;
	}

	int binary[32];
	int i = 0;

	while (n > 0) {
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}

	cout << "So nhi phan: ";
	for (int j = i - 1; j >= 0; j--) {
		cout << binary[j];
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Nhap so thap phan: ";
	cin >> n;

	if (n < 0) {
		cout << "Vui long nhap so duong!" << endl;
	}
	else {
		chuyenSangNhiPhan(n);
	}

	return 0;
}


//Bài tập 10:
//Viết chương trình nhập số nguyên lớn(không quá một tỷ), hãy đọc giá trị của nó bằng
//cách in ra xâu kí tự tương ứng với giá trị của nó.Ví dụ 1094507 là “Một triệu, (không
//trăm) chín tư nghìn, năm trăm linh bảy đơn vị”.
#include <iostream>
#include <string>
using namespace std;

string soDonVi[] = { "không", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín" };

string docBaChuSo(int num) {
	string result = "";
	int tram = num / 100;
	int chuc = (num / 10) % 10;
	int donvi = num % 10;

	if (tram != 0) {
		result += soDonVi[tram] + " trăm ";
		if (chuc == 0 && donvi != 0) result += "linh ";
	}

	if (chuc != 0) {
		if (chuc == 1) result += "mười ";
		else result += soDonVi[chuc] + " mươi ";
	}

	if (donvi != 0) {
		if (chuc > 1 && donvi == 1) result += "mốt";
		else if (chuc > 1 && donvi == 5) result += "lăm";
		else result += soDonVi[donvi];
	}

	return result;
}

string docSo(int num) {
	if (num == 0) return "không";

	string result = "";
	int trieu = num / 1000000;
	int nghin = (num / 1000) % 1000;
	int donvi = num % 1000;

	if (trieu > 0) result += docBaChuSo(trieu) + " triệu, ";
	if (nghin > 0) result += docBaChuSo(nghin) + " nghìn, ";
	if (donvi > 0) result += docBaChuSo(donvi) + " đơn vị";

	return result;
}

int main() {
	int num;
	cout << "Nhap so nguyen (<= 1 ty): ";
	cin >> num;

	if (num < 0 || num > 1000000000) {
		cout << "So nhap khong hop le!" << endl;
	}
	else {
		cout << "Cach doc: " << docSo(num) << endl;
	}

	return 0;
}


//Bài tập 11: Viết chương trình sắp xếp theo tên một mảng họ tên nào đó.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void nhapDanhSach(vector<string>& danhSach, int n) {
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string hoTen;
		cout << "Nhap ho ten thu " << i + 1 << ": ";
		getline(cin, hoTen);
		danhSach.push_back(hoTen);
	}
}

void hienThiDanhSach(const vector<string>& danhSach) {
	cout << "\nDanh sach ho ten:\n";
	for (const auto& ten : danhSach) {
		cout << ten << endl;
	}
}

void sapXepTheoTen(vector<string>& danhSach) {
	sort(danhSach.begin(), danhSach.end());
}

int main() {
	int n;
	cout << "Nhap so luong ho ten: ";
	cin >> n;

	vector<string> danhSach;
	nhapDanhSach(danhSach, n);

	cout << "\nDanh sach truoc khi sap xep:";
	hienThiDanhSach(danhSach);

	sapXepTheoTen(danhSach);

	cout << "\nDanh sach sau khi sap xep:";
	hienThiDanhSach(danhSach);

	return 0;
}


//Bài tập 12:
//Viết một hàm chuyển dữ liệu từ thập phân sang nhị phân
//Yêu cầu :
//✓ Kiểm tra dữ liệu nhập vào.
//✓ Viết hàm chuyển đổi là một hàm tĩnh trên một lớp có tên “ChuyenDoi”.
//✓ Khi nhấn nút “Chuyển đổi” chương trình sẽ gọi hàm chuyển từ số nhị phân sang
//số thập phân và hiển thị kết quả trên màn hình.
#include <iostream>
#include <string>
#include "ChuyenDoi1.h"
using namespace std;

int main() {
	int soThapPhan;
	string soNhiPhan;
	int luaChon;

	do {
		cout << "\n=== CHUONG TRINH CHUYEN DOI ===\n";
		cout << "1. Chuyen tu thap phan sang nhi phan\n";
		cout << "2. Chuyen tu nhi phan sang thap phan\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> luaChon;

		switch (luaChon) {
		case 1:
			cout << "Nhap so thap phan: ";
			cin >> soThapPhan;
			if (soThapPhan < 0) {
				cout << "Vui long nhap so khong am!\n";
			}
			else {
				cout << "So nhi phan: " << ChuyenDoi::thapPhanSangNhiPhan(soThapPhan) << endl;
			}
			break;

		case 2:
			cout << "Nhap so nhi phan: ";
			cin >> soNhiPhan;
			if (soNhiPhan.find_first_not_of("01") != string::npos) {
				cout << "Loi! Chi duoc nhap so 0 hoac 1.\n";
			}
			else {
				cout << "So thap phan: " << ChuyenDoi::nhiPhanSangThapPhan(soNhiPhan) << endl;
			}
			break;

		case 0:
			cout << "Thoat chuong trinh.\n";
			break;

		default:
			cout << "Lua chon khong hop le!\n";
		}
	} while (luaChon != 0);

	return 0;
}


//Bài tập 13:
//Viết một hàm chuyển dữ liệu từ số nhị phân sang số thập phân
//Yêu cầu:
//✓ Kiểm tra dữ liệu nhập vào
//✓ Viết hàm chuyển đổi là một hàm tĩnh trên một lớp có tên “ChuyenDoi”.
//✓ Khi nhấn nút “Chuyển đổi” chương trình sẽ gọi hàm chuyển từ số nhị phân sang
//số thập phân và hiển thị kết quả trên màn hình.
#include <iostream>
#include <string>
#include "ChuyenDoi.h"
using namespace std;

int main() {
	string soNhiPhan;
	int luaChon;

	do {
		cout << "\n=== CHUONG TRINH CHUYEN DOI ===\n";
		cout << "1. Chuyen tu nhi phan sang thap phan\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> luaChon;

		switch (luaChon) {
		case 1:
			cout << "Nhap so nhi phan: ";
			cin >> soNhiPhan;

			if (soNhiPhan.find_first_not_of("01") != string::npos) {
				cout << "Loi! Chi duoc nhap so 0 hoac 1.\n";
			}
			else {
				int ketQua = ChuyenDoi::nhiPhanSangThapPhan(soNhiPhan);
				cout << "So thap phan tuong ung: " << ketQua << endl;
			}
			break;

		case 0:
			cout << "Thoat chuong trinh.\n";
			break;

		default:
			cout << "Lua chon khong hop le!\n";
		}
	} while (luaChon != 0);

	return 0;
}


//Bài tập 14: Một trường đại học tuyển sinh khối A cần lưu trữ các thông tin về thí sinh
//bao gồm : Số báo danh, Họ tên, năm sinh, điểm toán, điểm lý, điểm hóa.Sử dụng kiến
//thức đã học định nghĩa một kiểu cấu trúc sau đó viết các hàm xử lý công việc như sau :
//✓ Nhập 10 – 20 thông tin thí sinh đã dự tuyển của trường đại học trên
//✓ Lấy ra top 5 thí sinh có điểm cao nhất, không có điểm liệt
//✓ Viết hàm các sinh viên có điểm đạt từ điểm sàn 15 điểm trở lên
//✓ Viết hàm lấy ra danh sách thí sinh bị điểm liệt
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ThiSinh {
	string soBaoDanh;
	string hoTen;
	int namSinh;
	float diemToan, diemLy, diemHoa;

	float tinhTongDiem() const {
		return diemToan + diemLy + diemHoa;
	}

	bool biDiemLiet() const {
		return diemToan <= 1 || diemLy <= 1 || diemHoa <= 1;
	}
};

void nhapDanhSachThiSinh(vector<ThiSinh>& danhSach, int soLuong) {
	for (int i = 0; i < soLuong; i++) {
		ThiSinh ts;
		cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
		cout << "So bao danh: ";
		cin >> ts.soBaoDanh;
		cin.ignore(); // Xóa bộ đệm
		cout << "Ho ten: ";
		getline(cin, ts.hoTen);
		cout << "Nam sinh: ";
		cin >> ts.namSinh;
		do {
			cout << "Diem Toan: "; cin >> ts.diemToan;
		} while (ts.diemToan < 0 || ts.diemToan > 10);
		do {
			cout << "Diem Ly: "; cin >> ts.diemLy;
		} while (ts.diemLy < 0 || ts.diemLy > 10);
		do {
			cout << "Diem Hoa: "; cin >> ts.diemHoa;
		} while (ts.diemHoa < 0 || ts.diemHoa > 10);

		danhSach.push_back(ts);
	}
}

void hienThiDanhSach(const vector<ThiSinh>& danhSach) {
	cout << "\nDanh sach thi sinh:\n";
	for (const auto& ts : danhSach) {
		cout << "SBD: " << ts.soBaoDanh << ", Ho ten: " << ts.hoTen
			<< ", Nam sinh: " << ts.namSinh
			<< ", Toan: " << ts.diemToan << ", Ly: " << ts.diemLy
			<< ", Hoa: " << ts.diemHoa << ", Tong: " << ts.tinhTongDiem() << endl;
	}
}

void hienThiTop5ThiSinh(vector<ThiSinh> danhSach) {
	sort(danhSach.begin(), danhSach.end(), [](ThiSinh a, ThiSinh b) {
		return a.tinhTongDiem() > b.tinhTongDiem();
		});

	cout << "\nTop 5 thi sinh co diem cao nhat (khong bi diem liet):\n";
	int count = 0;
	for (const auto& ts : danhSach) {
		if (!ts.biDiemLiet()) {
			cout << "SBD: " << ts.soBaoDanh << ", Ho ten: " << ts.hoTen
				<< ", Tong diem: " << ts.tinhTongDiem() << endl;
			count++;
			if (count == 5) break;
		}
	}
}

void hienThiThiSinhDiemSan(const vector<ThiSinh>& danhSach) {
	cout << "\nDanh sach thi sinh dat diem san (>= 15 diem):\n";
	for (const auto& ts : danhSach) {
		if (ts.tinhTongDiem() >= 15 && !ts.biDiemLiet()) {
			cout << "SBD: " << ts.soBaoDanh << ", Ho ten: " << ts.hoTen
				<< ", Tong diem: " << ts.tinhTongDiem() << endl;
		}
	}
}

void hienThiThiSinhBiDiemLiet(const vector<ThiSinh>& danhSach) {
	cout << "\nDanh sach thi sinh bi diem liet:\n";
	for (const auto& ts : danhSach) {
		if (ts.biDiemLiet()) {
			cout << "SBD: " << ts.soBaoDanh << ", Ho ten: " << ts.hoTen
				<< ", Tong diem: " << ts.tinhTongDiem() << endl;
		}
	}
}

int main() {
	vector<ThiSinh> danhSach;
	int soLuong;

	do {
		cout << "Nhap so luong thi sinh (10 - 20): ";
		cin >> soLuong;
	} while (soLuong < 10 || soLuong > 20);

	nhapDanhSachThiSinh(danhSach, soLuong);

	hienThiDanhSach(danhSach);

	hienThiTop5ThiSinh(danhSach);

	hienThiThiSinhDiemSan(danhSach);

	hienThiThiSinhBiDiemLiet(danhSach);

	return 0;
}


//Bài 1: Khai báo kiểu số phức với hai thuộc tính : phần thực và phần ảo.
//a) Viết hàm nhập và in ra màn hình số phức.Ví dụ :
//Hàm nhập :
//Nhập số phức :
//Phần thực = 1.1
//Phần ảo = 2.1
//Hàm in ra màn hình số phức :
//Số phức là : 1.1 + 2.1 i
//b) Viết hàm cộng, trừ, nhân, chia hai số phức cho nhau.
//c) Viết hàm tính bình phương một số phức
#include <iostream>
#include <cmath>
using namespace std;

struct SoPhuc {
	double thuc;
	double ao;

	void nhap() {
		cout << "Nhap so phuc:\n";
		cout << "Phan thuc = ";
		cin >> thuc;
		cout << "Phan ao = ";
		cin >> ao;
	}

	void hienThi() const {
		cout << "So phuc: " << thuc;
		if (ao >= 0) cout << " + " << ao << "i" << endl;
		else cout << " - " << -ao << "i" << endl;
	}
};

SoPhuc cong(SoPhuc a, SoPhuc b) {
	return { a.thuc + b.thuc, a.ao + b.ao };
}

SoPhuc tru(SoPhuc a, SoPhuc b) {
	return { a.thuc - b.thuc, a.ao - b.ao };
}

SoPhuc nhan(SoPhuc a, SoPhuc b) {
	SoPhuc ketQua;
	ketQua.thuc = a.thuc * b.thuc - a.ao * b.ao;
	ketQua.ao = a.thuc * b.ao + a.ao * b.thuc;
	return ketQua;
}

SoPhuc chia(SoPhuc a, SoPhuc b) {
	SoPhuc ketQua;
	double mau = b.thuc * b.thuc + b.ao * b.ao;
	if (mau == 0) {
		cout << "Loi: Khong the chia cho 0!\n";
		return { 0, 0 };
	}
	ketQua.thuc = (a.thuc * b.thuc + a.ao * b.ao) / mau;
	ketQua.ao = (a.ao * b.thuc - a.thuc * b.ao) / mau;
	return ketQua;
}

SoPhuc binhPhuong(SoPhuc a) {
	return nhan(a, a);
}

int main() {
	SoPhuc sp1, sp2, ketQua;
	int luaChon;

	do {
		cout << "\n=== CHUONG TRINH XU LY SO PHUC ===\n";
		cout << "1. Nhap va hien thi so phuc\n";
		cout << "2. Cong hai so phuc\n";
		cout << "3. Tru hai so phuc\n";
		cout << "4. Nhan hai so phuc\n";
		cout << "5. Chia hai so phuc\n";
		cout << "6. Tinh binh phuong mot so phuc\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> luaChon;

		switch (luaChon) {
		case 1:
			sp1.nhap();
			sp1.hienThi();
			break;

		case 2:
			cout << "Nhap so phuc thu nhat:\n";
			sp1.nhap();
			cout << "Nhap so phuc thu hai:\n";
			sp2.nhap();
			ketQua = cong(sp1, sp2);
			cout << "Ket qua cong: ";
			ketQua.hienThi();
			break;

		case 3:
			cout << "Nhap so phuc thu nhat:\n";
			sp1.nhap();
			cout << "Nhap so phuc thu hai:\n";
			sp2.nhap();
			ketQua = tru(sp1, sp2);
			cout << "Ket qua tru: ";
			ketQua.hienThi();
			break;

		case 4:
			cout << "Nhap so phuc thu nhat:\n";
			sp1.nhap();
			cout << "Nhap so phuc thu hai:\n";
			sp2.nhap();
			ketQua = nhan(sp1, sp2);
			cout << "Ket qua nhan: ";
			ketQua.hienThi();
			break;

		case 5:
			cout << "Nhap so phuc thu nhat:\n";
			sp1.nhap();
			cout << "Nhap so phuc thu hai:\n";
			sp2.nhap();
			ketQua = chia(sp1, sp2);
			cout << "Ket qua chia: ";
			ketQua.hienThi();
			break;

		case 6:
			cout << "Nhap so phuc can binh phuong:\n";
			sp1.nhap();
			ketQua = binhPhuong(sp1);
			cout << "Ket qua binh phuong: ";
			ketQua.hienThi();
			break;

		case 0:
			cout << "Thoat chuong trinh.\n";
			break;

		default:
			cout << "Lua chon khong hop le!\n";
		}
	} while (luaChon != 0);

	return 0;
}


//Bài 2: Định nghĩa một phân số có kiểu dữ liệu gồm hai phần: tử số và mẫu số.
//a) Viết hàm nhập và in ra phân số.
//b) Viết hàm cộng, trừ, nhân, chia hai phân số.
//c) Viết hàm rút gọn phân số.
#include <iostream>
using namespace std;

struct PhanSo {
	int tuSo;
	int mauSo;

	void nhap() {
		cout << "Nhap tu so: ";
		cin >> tuSo;
		do {
			cout << "Nhap mau so (khac 0): ";
			cin >> mauSo;
		} while (mauSo == 0);
	}

	void hienThi() const {
		if (mauSo == 1) cout << tuSo;
		else cout << tuSo << "/" << mauSo;
	}

	int timUCLN(int a, int b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	void rutGon() {
		int ucln = timUCLN(abs(tuSo), abs(mauSo));
		tuSo /= ucln;
		mauSo /= ucln;
		if (mauSo < 0) {
			tuSo = -tuSo;
			mauSo = -mauSo;
		}
	}
};

PhanSo cong(PhanSo a, PhanSo b) {
	PhanSo kq;
	kq.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
	kq.mauSo = a.mauSo * b.mauSo;
	kq.rutGon();
	return kq;
}

PhanSo tru(PhanSo a, PhanSo b) {
	PhanSo kq;
	kq.tuSo = a.tuSo * b.mauSo - b.tuSo * a.mauSo;
	kq.mauSo = a.mauSo * b.mauSo;
	kq.rutGon();
	return kq;
}

PhanSo nhan(PhanSo a, PhanSo b) {
	PhanSo kq;
	kq.tuSo = a.tuSo * b.tuSo;
	kq.mauSo = a.mauSo * b.mauSo;
	kq.rutGon();
	return kq;
}

PhanSo chia(PhanSo a, PhanSo b) {
	PhanSo kq;
	if (b.tuSo == 0) {
		cout << "Loi: Khong the chia cho 0!\n";
		return { 0, 1 };
	}
	kq.tuSo = a.tuSo * b.mauSo;
	kq.mauSo = a.mauSo * b.tuSo;
	kq.rutGon();
	return kq;
}

int main() {
	PhanSo ps1, ps2, ketQua;
	int luaChon;

	do {
		cout << "\n=== CHUONG TRINH XU LY PHAN SO ===\n";
		cout << "1. Nhap va hien thi phan so\n";
		cout << "2. Cong hai phan so\n";
		cout << "3. Tru hai phan so\n";
		cout << "4. Nhan hai phan so\n";
		cout << "5. Chia hai phan so\n";
		cout << "6. Rut gon mot phan so\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> luaChon;

		switch (luaChon) {
		case 1:
			ps1.nhap();
			cout << "Phan so vua nhap: ";
			ps1.hienThi();
			cout << endl;
			break;

		case 2:
			cout << "Nhap phan so thu nhat:\n";
			ps1.nhap();
			cout << "Nhap phan so thu hai:\n";
			ps2.nhap();
			ketQua = cong(ps1, ps2);
			cout << "Ket qua cong: ";
			ketQua.hienThi();
			cout << endl;
			break;

		case 3:
			cout << "Nhap phan so thu nhat:\n";
			ps1.nhap();
			cout << "Nhap phan so thu hai:\n";
			ps2.nhap();
			ketQua = tru(ps1, ps2);
			cout << "Ket qua tru: ";
			ketQua.hienThi();
			cout << endl;
			break;

		case 4:
			cout << "Nhap phan so thu nhat:\n";
			ps1.nhap();
			cout << "Nhap phan so thu hai:\n";
			ps2.nhap();
			ketQua = nhan(ps1, ps2);
			cout << "Ket qua nhan: ";
			ketQua.hienThi();
			cout << endl;
			break;

		case 5:
			cout << "Nhap phan so thu nhat:\n";
			ps1.nhap();
			cout << "Nhap phan so thu hai:\n";
			ps2.nhap();
			ketQua = chia(ps1, ps2);
			cout << "Ket qua chia: ";
			ketQua.hienThi();
			cout << endl;
			break;

		case 6:
			cout << "Nhap phan so can rut gon:\n";
			ps1.nhap();
			ps1.rutGon();
			cout << "Phan so sau khi rut gon: ";
			ps1.hienThi();
			cout << endl;
			break;

		case 0:
			cout << "Thoat chuong trinh.\n";
			break;

		default:
			cout << "Lua chon khong hop le!\n";
		}
	} while (luaChon != 0);

	return 0;
}

//Bài 3: Viết chương trình nhập một chuỗi từ màn hình. Hiển thị số nguyên âm trong
//chuỗi trên(nguyên âm gồm các chữ cái : a, e, i, u, o).
#include <iostream>
#include <string>
using namespace std;

int demNguyenAm(const string& chuoi) {
	int count = 0;
	for (char c : chuoi) {
		c = tolower(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			count++;
		}
	}
	return count;
}

int main() {
	string chuoi;

	cout << "Nhap mot chuoi: ";
	getline(cin, chuoi);

	int soNguyenAm = demNguyenAm(chuoi);
	cout << "So luong nguyen am trong chuoi: " << soNguyenAm << endl;

	return 0;
}


//Bài 4: Viết chương trình nhập vào số nguyên dương N gồm k chữ số (0 < k <= 6), sắp
//xếp các chữ số của N theo thứ tự tăng dần.
//Ví dụ : Nhập vào số nnguyee8N = 132462.
//Kết quả sau khi sắp xếp : 122346.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sapXepChuSo(int n) {
	vector<int> chuSo;

	while (n > 0) {
		chuSo.push_back(n % 10);
		n /= 10;
	}

	sort(chuSo.begin(), chuSo.end());

	cout << "So sau khi sap xep: ";
	for (int cs : chuSo) {
		cout << cs;
	}
	cout << endl;
}

int main() {
	int N;

	do {
		cout << "Nhap so nguyen duong N (toi da 6 chu so): ";
		cin >> N;
	} while (N <= 0 || N > 999999);

	sapXepChuSo(N);

	return 0;
}

//Bài tập 1: Viết câu lệnh khai báo biến để lưu các giá trị sau :
//− Tuổi của một người − Số lượng cây trong thành phố
//− Độ dài cạnh một tam giác − Khoảng cách giữa các hành tinh
//− Một chữ số − Nghiệm x của phương trình bậc 1
//− Một chữ cái − Biệt thức Δ của phương trình bậc 2
#include <iostream>
using namespace std;

int main() 
{
	int tuoi;
	cout << "Nhập tuổi của người: ";
	cin >> tuoi;

	int soCay;
	cout << "Nhập số lượng cây trong thành phố: ";
	cin >> soCay;

	float doDaiCanh;
	cout << "Nhập độ dài cạnh của tam giác: ";
	cin >> doDaiCanh;

	float khoangCachHanhTinh;
	cout << "Nhập khoảng cách giữa các hành tinh (km): ";
	cin >> khoangCachHanhTinh;

	int chuSo;
	cout << "Nhập một chữ số: ";
	cin >> chuSo;

	float A, B, nghiemX;
	cout << "Nhập hệ số A: ";
	cin >> A;
	cout << "Nhập hệ số B: ";
	cin >> B;
	if (A != 0) 
	{
		nghiemX = -B / A;
		cout << "Nghiệm x của phương trình bậc 1 là: " << nghiemX << endl;
	}
	else 
	{
		cout << "Phương trình không có nghiệm (A = 0)" << endl;
	}

	char chuCai;
	cout << "Nhập một chữ cái: ";
	cin >> chuCai;

	float a, b, c, bietThucDelta;
	cout << "Nhập hệ số a: ";
	cin >> a;
	cout << "Nhập hệ số b: ";
	cin >> b;
	cout << "Nhập hệ số c: ";
	cin >> c;
	bietThucDelta = b * b - 4 * a * c;
	cout << "Biệt thức Δ của phương trình bậc 2 là: " << bietThucDelta << endl;
}

//Bài tập 2: Viết câu lệnh nhập vào 4 giá trị lần lượt là số thực, nguyên, nguyên dài và kí
//tự.In ra màn hình các giá trị này để kiểm tra.
#include <iostream>
using namespace std;

int main() 
{
	float soThuc;
	int soNguyen;
	long soNguyenDai;
	char kyTu;

	cout << "Nhập số thực: ";
	cin >> soThuc;

	cout << "Nhập số nguyên: ";
	cin >> soNguyen;

	cout << "Nhập số nguyên dài: ";
	cin >> soNguyenDai;

	cout << "Nhập một ký tự: ";
	cin >> kyTu;

	cout << "Số thực bạn nhập: " << soThuc << endl;
	cout << "Số nguyên bạn nhập: " << soNguyen << endl;
	cout << "Số nguyên dài bạn nhập: " << soNguyenDai << endl;
	cout << "Ký tự bạn nhập: " << kyTu << endl;
}

//Bài tập 3: Viết câu lệnh in ra màn hình các dòng sau (không kể các số thứ tự và dấu: ở
//đầu mỗi dòng)
//1: Bộ Giáo dục
//2 : Đào tạo Cộng hoà xã hội chủ nghĩa Việt Nam
//3 : Sở Giáo dục Hà Nội Độc lập - Tự do - Hạnh phúc
#include <iostream>
using namespace std;

int main() 
{
	cout << "Bộ Giáo dục" << endl;
	cout << "Đào tạo Cộng hoà xã hội chủ nghĩa Việt Nam" << endl;
	cout << "Sở Giáo dục Hà Nội Độc lập - Tự do - Hạnh phúc" << endl;
}

//Bài tập 4: Viết chương trình nhập vào một kí tự. In ra kí tự đó và mã ascii của nó. 
#include <iostream>
using namespace std;

int main() 
{
	char kyTu;

	cout << "Nhập một ký tự: ";
	cin >> kyTu;

	cout << "Ký tự bạn nhập là: " << kyTu << endl;
	cout << "Mã ASCII của ký tự '" << kyTu << "' là: " << int(kyTu) << endl;
}

//Bài tập 5: Viết chương trình nhập vào hai số thực. In ra hai số thực đó với 2 số lẻ và cách
//nhau 5 cột.
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
	float so1, so2;

	cout << "Nhập số thực thứ nhất: ";
	cin >> so1;
	cout << "Nhập số thực thứ hai: ";
	cin >> so2;

	cout << fixed << setprecision(2) << so1 << "     " << so2 << endl;
}
//Bài tập 6:
#include <iostream>
int main()
{
	char c1 = 200; unsigned char c2 = 200;
	cout << "c1 = " << c1 << ", c2 = " << c2 << "\n";
	cout << "c1+100 = " << c1 + 100 << ", c2+100 = " << c2 + 100;
}

//Bài tập 7: Nhập a, b, c. In ra màn hình dòng chữ phương trình có dạng ax^2 + bx + c = 0
#include <iostream>
using namespace std;

int main() 
{
	float a, b, c;

	cout << "Nhập hệ số a: ";
	cin >> a;
	cout << "Nhập hệ số b: ";
	cin >> b;
	cout << "Nhập hệ số c: ";
	cin >> c;

	cout << "Phương trình là: ";

	if (a == 1) 
	{
		cout << "x^2 ";
	}
	else if (a == -1) 
	{
		cout << "-x^2 ";
	}
	else 
	{
		cout << a << "x^2 ";
	}

	if (b > 0) 
	{
		cout << "+ " << b << "x ";
	}
	else if (b < 0) 
	{
		cout << "- " << -b << "x ";
	}

	if (c > 0) 
	{
		cout << "+ " << c;
	}
	else if (c < 0) 
	{
		cout << "- " << -c;
	}

	cout << " = 0" << endl;
}

//Bài tập 8: Viết chương trình tính và in ra giá trị các biểu thức sau với 2 số lẻ: 
#include <iostream>
#include <cmath>
#include <iomanip>  // Để sử dụng setprecision
using namespace std;

int main() {
	float a = 3;
	float b = 2;

	// Vòng lặp thực hiện 3 lần tính toán
	for (int i = 0; i < 3; i++) {
		a = sqrt(3 + a);  // Cập nhật giá trị của a
		b = 2 + 1 / b;    // Cập nhật giá trị của b
	}

	// In kết quả ra màn hình với 2 chữ số thập phân
	cout << fixed << setprecision(2);  // Đảm bảo in với 2 chữ số thập phân
	cout << "a) " << a << endl;        // In giá trị của a
	cout << "b) " << b - 2 << endl;    // In giá trị của b trừ 2

	return 0;
}

//Bài tập 9: Nhập a, b, c là các số thực. In ra giá trị của các biểu thức sau với 3 số lẻ: 
#include <iostream>
#include <cmath>  // Để sử dụng các hàm toán học như pow và sqrt
#include <iomanip>  // Để sử dụng setprecision
using namespace std;

int main() {
	// Khai báo các biến
	int a = 3;
	int b = 5;
	int c = 7;

	// Tính toán các biểu thức
	float cau_a = pow(a, 2) - 2 * b + ((a * b) / c);
	float cau_b = (pow(b, 2) - 4 * a * c) / (2 * a);
	float cau_c = 3 * a - pow(b, 3) - 2 * sqrt(c);
	float cau_d = sqrt((pow(a, 2) / b) - 4 * a / b * c + 1);

	// In ra kết quả với 6 chữ số thập phân
	cout << fixed << setprecision(6);  // Đảm bảo in ra với 6 chữ số thập phân
	cout << "a) " << cau_a << endl;
	cout << "b) " << cau_b << endl;
	cout << "c) " << cau_c << endl;
	cout << "d) " << cau_d << endl;

	return 0;
}

//Bài tập 10: In ra tổng, tích, hiệu và thương của 2 số được nhập vào từ bàn phím. 
#include <iostream>
using namespace std;

int main() {
	// Khai báo hai số thực
	float a, b;

	// Nhập hai số từ bàn phím
	cout << "Nhập số thứ nhất: ";
	cin >> a;
	cout << "Nhập số thứ hai: ";
	cin >> b;

	// Tính tổng, tích, hiệu, và thương
	float tong = a + b;
	float tich = a * b;
	float hieu = a - b;
	float thuong = (b != 0) ? (a / b) : 0;  // Kiểm tra chia cho 0 để tránh lỗi

	// In kết quả ra màn hình
	cout << "Tổng của hai số: " << tong << endl;
	cout << "Tích của hai số: " << tich << endl;
	cout << "Hiệu của hai số: " << hieu << endl;

	// Kiểm tra nếu b != 0 mới in ra thương
	if (b != 0) {
		cout << "Thương của hai số: " << thuong << endl;
	}
	else {
		cout << "Không thể chia cho 0!" << endl;
	}

	return 0;
}

//Bài tập 11: In ra trung bình cộng, trung bình nhân của 3 số được nhập vào từ bàn phím. 
#include <iostream>
#include <cmath>  // Để sử dụng hàm pow (căn bậc 3)
#include <iomanip>  // Để sử dụng setprecision
using namespace std;

int main() {
	// Khai báo ba số thực
	float a, b, c;

	// Nhập ba số từ bàn phím
	cout << "Nhập số thứ nhất: ";
	cin >> a;
	cout << "Nhập số thứ hai: ";
	cin >> b;
	cout << "Nhập số thứ ba: ";
	cin >> c;

	// Tính trung bình cộng
	float tb_c = (a + b + c) / 3;

	// Tính trung bình nhân (căn bậc 3 của tích)
	float tb_n = pow(a * b * c, 1.0 / 3);  // pow(x, 1.0 / 3) tính căn bậc 3 của x

	// In kết quả ra màn hình với 2 chữ số thập phân
	cout << fixed << setprecision(2);  // Đảm bảo in với 2 chữ số thập phân
	cout << "Trung bình cộng của ba số: " << tb_c << endl;
	cout << "Trung bình nhân của ba số: " << tb_n << endl;

	return 0;
}

//Bài tập 12: Viết chương trình nhập cạnh, bán kính và in ra diện tích, chu vi của các hình:
//hình vuông, hình chữ nhật, hình tròn.
#include <iostream>
#include <cmath>  // Để sử dụng hằng số M_PI (pi)
#include <iomanip>  // Để sử dụng setprecision
using namespace std;

int main() {
	// Khai báo các biến
	float a, l, w, r;

	// Nhập cạnh hình vuông, chiều dài và chiều rộng hình chữ nhật, bán kính hình tròn
	cout << "Nhập cạnh hình vuông: ";
	cin >> a;

	cout << "Nhập chiều dài hình chữ nhật: ";
	cin >> l;

	cout << "Nhập chiều rộng hình chữ nhật: ";
	cin >> w;

	cout << "Nhập bán kính hình tròn: ";
	cin >> r;

	// Tính diện tích và chu vi hình vuông
	float dienTichVuong = a * a;
	float chuViVuong = 4 * a;

	// Tính diện tích và chu vi hình chữ nhật
	float dienTichChuNhat = l * w;
	float chuViChuNhat = 2 * (l + w);

	// Tính diện tích và chu vi hình tròn
	float dienTichTron = M_PI * r * r;
	float chuViTron = 2 * M_PI * r;

	// In kết quả ra màn hình với 2 chữ số thập phân
	cout << fixed << setprecision(2);  // Đảm bảo in ra với 2 chữ số thập phân

	// In diện tích và chu vi của các hình
	cout << "\nHình vuông:\n";
	cout << "Diện tích: " << dienTichVuong << endl;
	cout << "Chu vi: " << chuViVuong << endl;

	cout << "\nHình chữ nhật:\n";
	cout << "Diện tích: " << dienTichChuNhat << endl;
	cout << "Chu vi: " << chuViChuNhat << endl;

	cout << "\nHình tròn:\n";
	cout << "Diện tích: " << dienTichTron << endl;
	cout << "Chu vi: " << chuViTron << endl;

	return 0;
}
//Bài tập 13: Nhập a, b, c là độ dài 3 cạnh của tam giác (chú ý đảm bảo tổng 2 cạnh phải
//lớn hơn cạnh còn lại).Tính chu vi, diện tích, độ dài 3 đường cao, 3 đường trung tuyến, 3
//đường phân giác, bán kính đường tròn nội tiếp, ngoại tiếp lần lượt
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// Khai báo các biến
	float a, b, c;

	// Nhập độ dài 3 cạnh của tam giác
	cout << "Nhập cạnh a: ";
	cin >> a;
	cout << "Nhập cạnh b: ";
	cin >> b;
	cout << "Nhập cạnh c: ";
	cin >> c;

	// Kiểm tra tính hợp lệ của tam giác
	if (a + b <= c || a + c <= b || b + c <= a) {
		cout << "Ba cạnh này không tạo thành tam giác hợp lệ!" << endl;
		return 0;
	}

	// Tính nửa chu vi
	float s = (a + b + c) / 2;

	// Tính diện tích của tam giác theo công thức Heron
	float S = sqrt(s * (s - a) * (s - b) * (s - c));

	// Tính chu vi
	float P = a + b + c;

	// Tính độ dài ba đường cao
	float h_a = (2 * S) / a;
	float h_b = (2 * S) / b;
	float h_c = (2 * S) / c;

	// Tính độ dài ba đường trung tuyến
	float m_a = sqrt((2 * b * b + 2 * c * c - a * a) / 4);
	float m_b = sqrt((2 * a * a + 2 * c * c - b * b) / 4);
	float m_c = sqrt((2 * a * a + 2 * b * b - c * c) / 4);

	// Tính độ dài ba đường phân giác
	float l_a = sqrt((b * c * (s - a)) / s);
	float l_b = sqrt((a * c * (s - b)) / s);
	float l_c = sqrt((a * b * (s - c)) / s);

	// Tính bán kính đường tròn nội tiếp
	float r = S / s;

	// Tính bán kính đường tròn ngoại tiếp
	float R = (a * b * c) / (4 * S);

	// In kết quả
	cout << fixed;
	cout.precision(2);

	cout << "Chu vi tam giác: " << P << endl;
	cout << "Diện tích tam giác: " << S << endl;
	cout << "Độ dài đường cao:\n";
	cout << "h_a: " << h_a << endl;
	cout << "h_b: " << h_b << endl;
	cout << "h_c: " << h_c << endl;
	cout << "Độ dài đường trung tuyến:\n";
	cout << "m_a: " << m_a << endl;
	cout << "m_b: " << m_b << endl;
	cout << "m_c: " << m_c << endl;
	cout << "Độ dài đường phân giác:\n";
	cout << "l_a: " << l_a << endl;
	cout << "l_b: " << l_b << endl;
	cout << "l_c: " << l_c << endl;
	cout << "Bán kính đường tròn nội tiếp: " << r << endl;
	cout << "Bán kính đường tròn ngoại tiếp: " << R << endl;

	return 0;
}

//Bài tập 14: Tính diện tích và thể tích của hình cầu bán kính R theo công thức: 
#include <iostream>
#include <cmath>  // Để sử dụng hằng số M_PI và các hàm toán học
#include <iomanip> // Để sử dụng setprecision để kiểm soát số chữ số thập phân

using namespace std;

int main() {
	// Khai báo bán kính của hình cầu
	float R;

	// Nhập bán kính từ người dùng
	cout << "Nhập bán kính R của hình cầu: ";
	cin >> R;

	// Kiểm tra nếu bán kính không hợp lệ (bán kính phải lớn hơn 0)
	if (R <= 0) {
		cout << "Bán kính không hợp lệ! Bán kính phải lớn hơn 0." << endl;
		return 0;
	}

	// Tính diện tích bề mặt của hình cầu
	float dienTich = 4 * M_PI * R * R;

	// Tính thể tích của hình cầu
	float theTich = (4.0 / 3) * M_PI * R * R * R;

	// In kết quả ra màn hình với 2 chữ số thập phân
	cout << fixed << setprecision(2);  // Đảm bảo kết quả có 2 chữ số thập phân
	cout << "Diện tích bề mặt của hình cầu: " << dienTich << endl;
	cout << "Thể tích của hình cầu: " << theTich << endl;

	return 0;
}

//Bài tập 15: Nhập vào 4 chữ số. In ra tổng của 4 chữ số này và chữ số hàng chục, hàng
//đơn vị của tổng(ví dụ 4 chữ số 3, 1, 8, 5 có tổng là 17 và chữ số hàng chục là 1 và hàng
//đơn vị là 7, cần in ra 17, 1, 7).
#include <iostream>
using namespace std;

int main() {
	// Khai báo các biến cho 4 chữ số
	int a, b, c, d;

	// Nhập 4 chữ số
	cout << "Nhập chữ số thứ nhất: ";
	cin >> a;
	cout << "Nhập chữ số thứ hai: ";
	cin >> b;
	cout << "Nhập chữ số thứ ba: ";
	cin >> c;
	cout << "Nhập chữ số thứ tư: ";
	cin >> d;

	// Tính tổng của 4 chữ số
	int sum = a + b + c + d;

	// Lấy chữ số hàng đơn vị (sum % 10)
	int unit = sum % 10;

	// Lấy chữ số hàng chục (sum / 10 % 10)
	int tens = (sum / 10) % 10;

	// In kết quả
	cout << "Tổng của 4 chữ số là: " << sum << endl;
	cout << "Chữ số hàng chục: " << tens << endl;
	cout << "Chữ số hàng đơn vị: " << unit << endl;

	return 0;
}

//Bài tập 16: Nhập vào một số nguyên (có 4 chữ số). In ra tổng của 4 chữ số này và chữ số
//đầu, chữ số cuối(ví dụ số 3185 có tổng các chữ số là 17, đầu và cuối là 3 và 5, kết quả in
//ra là : 17, 3, 5).
#include <iostream>
using namespace std;

int main() {
	// Khai báo biến để lưu số nguyên có 4 chữ số
	int num;

	// Nhập số nguyên có 4 chữ số
	cout << "Nhập một số nguyên có 4 chữ số: ";
	cin >> num;

	// Kiểm tra tính hợp lệ của số nhập vào (phải có 4 chữ số)
	if (num < 1000 || num > 9999) {
		cout << "Số nhập vào không phải là số có 4 chữ số!" << endl;
		return 0;
	}

	// Tính tổng các chữ số của số nguyên
	int sum = (num / 1000) + (num / 100 % 10) + (num / 10 % 10) + (num % 10);

	// Lấy chữ số đầu (hàng nghìn) và chữ số cuối (hàng đơn vị)
	int firstDigit = num / 1000;   // Chữ số đầu
	int lastDigit = num % 10;      // Chữ số cuối

	// In kết quả
	cout << "Tổng các chữ số của số " << num << " là: " << sum << endl;
	cout << "Chữ số đầu: " << firstDigit << endl;
	cout << "Chữ số cuối: " << lastDigit << endl;

	return 0;
}

//Bài tập 17: Hãy nhập 2 số a và b. Viết chương trình đổi giá trị của a và b theo 2 cách:
//− Dùng biến phụ t : t = a; a = b; b = t;
//− Không dùng biến phụ : a = a + b; b = a - b; a = a - b;
//In kết quả ra màn hình để kiểm tra.
#include <iostream>
using namespace std;

int main() {
	// Khai báo hai biến a và b
	int a, b;

	// Nhập vào hai số a và b
	cout << "Nhập số a: ";
	cin >> a;
	cout << "Nhập số b: ";
	cin >> b;

	// In ra giá trị ban đầu của a và b
	cout << "Trước khi đổi: a = " << a << ", b = " << b << endl;

	// Cách 1: Dùng biến phụ t
	int t = a;
	a = b;
	b = t;
	cout << "Sau khi đổi (dùng biến phụ): a = " << a << ", b = " << b << endl;

	// Cách 2: Không dùng biến phụ
	// Đổi lại giá trị a và b bằng cách cộng trừ
	a = a + b;  // a chứa tổng của a và b
	b = a - b;  // b sẽ là giá trị ban đầu của a
	a = a - b;  // a sẽ là giá trị ban đầu của b
	cout << "Sau khi đổi (không dùng biến phụ): a = " << a << ", b = " << b << endl;

	return 0;
}

//Bài tập 18: Một sinh viên gồm có các thông tin: họ tên, tuổi, điểm toán (hệ số 2), điểm
//tin(hệ số 1).Hãy nhập các thông tin trên cho 2 sinh viên.In ra bảng điểm gồm các chi tiết
//nêu trên và điểm trung bình của mỗi sinh viên.
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc sinh viên
struct SinhVien {
	string hoTen;
	int tuoi;
	float diemToan;
	float diemTin;
	float diemTB;  // Điểm trung bình
};

int main() {
	// Khai báo mảng lưu thông tin 2 sinh viên
	SinhVien sv[2];

	// Nhập thông tin cho từng sinh viên
	for (int i = 0; i < 2; i++) {
		cout << "Nhập thông tin cho sinh viên thứ " << i + 1 << ":\n";
		cout << "Họ tên: ";
		cin.ignore();  // Để bỏ qua dấu newline còn sót lại trong bộ đệm
		getline(cin, sv[i].hoTen);
		cout << "Tuổi: ";
		cin >> sv[i].tuoi;
		cout << "Điểm toán: ";
		cin >> sv[i].diemToan;
		cout << "Điểm tin: ";
		cin >> sv[i].diemTin;

		// Tính điểm trung bình
		sv[i].diemTB = (sv[i].diemToan * 2 + sv[i].diemTin * 1) / 3.0;
	}

	// In bảng điểm của 2 sinh viên
	cout << "\nBảng điểm:\n";
	cout << "Họ tên             Tuổi  Điểm Toán  Điểm Tin  Điểm TB\n";

	// In thông tin của từng sinh viên
	for (int i = 0; i < 2; i++) {
		cout << sv[i].hoTen << "  "
			<< sv[i].tuoi << "     "
			<< sv[i].diemToan << "      "
			<< sv[i].diemTin << "      "
			<< sv[i].diemTB << endl;
	}

	return 0;
}

//Bài tập 19: Một nhân viên gồm có các thông tin: họ tên, hệ số lương, phần trăm phụ cấp
//(theo lưong) và phần trăm phải đóng BHXH.Hãy nhập các thông tin trên cho 2 nhân viên.
//In ra bảng lương gồm các chi tiết nêu trên và tổng số tiền cuối cùng mỗi nhân viên được
//nhận.
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc nhân viên
struct NhanVien {
	string hoTen;
	float heSoLuong;
	float phuCap;      // Phần trăm phụ cấp theo lương
	float phanTramBHXH; // Phần trăm phải đóng BHXH
	float tongTien;    // Tổng số tiền cuối cùng nhận được
};

int main() {
	// Khai báo mảng lưu thông tin 2 nhân viên
	NhanVien nv[2];

	// Lương cơ bản giả định là 1 triệu đồng cho mỗi hệ số
	const float LUONG_CO_BAN = 1000000.0;

	// Nhập thông tin cho từng nhân viên
	for (int i = 0; i < 2; i++) {
		cout << "Nhập thông tin cho nhân viên thứ " << i + 1 << ":\n";
		cout << "Họ tên: ";
		cin.ignore();  // Để bỏ qua dấu newline còn sót lại trong bộ đệm
		getline(cin, nv[i].hoTen);
		cout << "Hệ số lương: ";
		cin >> nv[i].heSoLuong;
		cout << "Phần trăm phụ cấp (theo lương): ";
		cin >> nv[i].phuCap;
		cout << "Phần trăm đóng BHXH: ";
		cin >> nv[i].phanTramBHXH;

		// Tính lương cơ bản
		float luongCoBan = nv[i].heSoLuong * LUONG_CO_BAN;

		// Tính phụ cấp và BHXH
		float phuCapTien = luongCoBan * (nv[i].phuCap / 100);
		float bhxh = luongCoBan * (nv[i].phanTramBHXH / 100);

		// Tính tổng số tiền nhân viên nhận được
		nv[i].tongTien = luongCoBan + phuCapTien - bhxh;
	}

	// In bảng lương của các nhân viên
	cout << "\nBảng lương:\n";
	cout << "Họ tên                Hệ số lương   Phụ cấp (%)   BHXH (%)   Tổng tiền\n";

	// In thông tin của từng nhân viên
	for (int i = 0; i < 2; i++) {
		cout << nv[i].hoTen << "  "
			<< nv[i].heSoLuong << "         "
			<< nv[i].phuCap << "        "
			<< nv[i].phanTramBHXH << "        "
			<< nv[i].tongTien << endl;
	}

	return 0;
}

//Bài 1: Viết chương trình nhập vào một số thực. Đơn vị tính cho số này là centimet (cm).
//Hãy in ra số tương đương tính bằng foot(số thực, có 2 số lẻ thập phân) và inch(số thực,
//có 2 số lẻ thập phân).
//Với 1 inch = 2.54 cm và 1 foot = 12 inches.
#include <iostream>
#include <cmath>  // Để sử dụng hàm round()
using namespace std;

int main() {
	float cm;

	// Nhập vào số thực tính bằng centimet
	cout << "Nhập vào số chiều dài (cm): ";
	cin >> cm;

	// Chuyển đổi từ cm sang inch và foot
	float inch = cm / 2.54;              // 1 inch = 2.54 cm
	float foot = inch / 12;              // 1 foot = 12 inches

	// Làm tròn kết quả đến 2 chữ số thập phân
	inch = round(inch * 100) / 100;
	foot = round(foot * 100) / 100;

	// In kết quả ra màn hình
	cout << "Số tương đương trong inch: " << inch << " inches" << endl;
	cout << "Số tương đương trong foot: " << foot << " feet" << endl;

	return 0;
}

//Bài 2: Viết chương trình nhập vào 1 số nguyên, hiển thị số đó dưới hệ 8 và hệ 16.
#include <iostream>
using namespace std;

int main() {
	int num;

	// Nhập vào một số nguyên
	cout << "Nhập vào một số nguyên: ";
	cin >> num;

	// Hiển thị số đó dưới hệ 8
	cout << "Số trong hệ 8 (octal): " << oct << num << endl;

	// Hiển thị số đó dưới hệ 16
	cout << "Số trong hệ 16 (hexadecimal): " << hex << num << endl;

	return 0;
}

//Bài 3: Viết chương trình nhập vào số giây từ 0 tới 68399, đổi số giây này thành dạng
//[giờ:phút:giây], mỗi thành phần là một số nguyên có 2 chữ số.
#include <iostream>
using namespace std;

int main() {
	int totalSeconds;

	// Nhập vào số giây
	cout << "Nhập vào số giây (từ 0 đến 68399): ";
	cin >> totalSeconds;

	// Tính số giờ, phút, giây
	int hours = totalSeconds / 3600;            // 1 giờ = 3600 giây
	int minutes = (totalSeconds % 3600) / 60;   // 1 phút = 60 giây
	int seconds = totalSeconds % 60;            // Số giây còn lại

	// In kết quả theo định dạng [giờ:phút:giây] với 2 chữ số cho mỗi thành phần
	// In giờ
	if (hours < 10) cout << "0"; // Thêm số 0 vào trước nếu giờ < 10
	cout << hours << ":";

	// In phút
	if (minutes < 10) cout << "0"; // Thêm số 0 vào trước nếu phút < 10
	cout << minutes << ":";

	// In giây
	if (seconds < 10) cout << "0"; // Thêm số 0 vào trước nếu giây < 10
	cout << seconds << endl;

	return 0;
}

//Bài 4: Viết chương trình nhập vào 4 số nguyên, Hiển thị ra số lớn nhất và nhỏ nhất.
//Ví dụ : nhập vào 4 số 1, 2, 3, 4 thì kết quả là
//Số lớn nhất là : 4
//Số nhỏ nhất là : 1
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;

	// Nhập vào 4 số nguyên
	cout << "Nhập vào 4 số nguyên: ";
	cin >> a >> b >> c >> d;

	// Tìm số lớn nhất
	int maxNum = a; // Giả sử a là số lớn nhất
	if (b > maxNum) maxNum = b;
	if (c > maxNum) maxNum = c;
	if (d > maxNum) maxNum = d;

	// Tìm số nhỏ nhất
	int minNum = a; // Giả sử a là số nhỏ nhất
	if (b < minNum) minNum = b;
	if (c < minNum) minNum = c;
	if (d < minNum) minNum = d;

	// In kết quả
	cout << "Số lớn nhất là: " << maxNum << endl;
	cout << "Số nhỏ nhất là: " << minNum << endl;

	return 0;
}

//Bài 5: Nhập vào hai số tự nhiên a và b. Tính hiệu của hai số đó. Nếu hiệu số nhỏ hơn 0 thì
//in ra dòng chữ[Số thứ nhất bé hơn số thứ hai].Nếu hiệu số lớn hơn 0 thì in ra dòng chữ
//[số thứ nhất nhỏ hơn số thứ hai]
#include <iostream>
using namespace std;

int main() {
	int a, b;

	// Nhập vào hai số tự nhiên a và b
	cout << "Nhập vào hai số tự nhiên a và b: ";
	cin >> a >> b;

	// Tính hiệu của hai số
	int difference = a - b;

	// Kiểm tra và in kết quả
	if (difference < 0) {
		cout << "Số thứ nhất bé hơn số thứ hai" << endl;
	}
	else if (difference > 0) {
		cout << "Số thứ nhất lớn hơn số thứ hai" << endl;
	}
	else {
		cout << "Hai số bằng nhau" << endl;
	}

	return 0;
}

//Bài 6: Nhập vào 2 số tự nhiên a và b. Kiểm tra xem a có chia hết cho b không ?
#include <iostream>
using namespace std;

int main() {
	int a, b;

	// Nhập vào hai số tự nhiên a và b
	cout << "Nhập vào hai số tự nhiên a và b: ";
	cin >> a >> b;

	// Kiểm tra xem a có chia hết cho b không
	if (b == 0) {
		// Kiểm tra trường hợp chia cho 0
		cout << "Không thể chia cho 0!" << endl;
	}
	else if (a % b == 0) {
		cout << a << " chia hết cho " << b << endl;
	}
	else {
		cout << a << " không chia hết cho " << b << endl;
	}

	return 0;
}

//Bài 7: Xếp loại sinh viên theo các qui luật dưới đây:
//Nếu điểm >= 9.0 - Loại xuất sắc
//Nếu 8.0 <= điểm < 9.0 - Loại giỏi
//Nếu 7.0 <= điểm < 8.0 - Loại khá
//Nếu 6.0 <= điểm < 7.0 - Loại trung bình khá
//Nếu 5.0 <= điểm < 6.0 - Loại trung bình
//Nếu điểm < 5.0 - Loại kém
//Với điểm = ((điểm toán) * 2 + điểm lý + điểm hóa) / 4.
//a.Nhập vào điểm 3 môn học
//b.Tính điểm trung bình
//c.Xác định học lực của học sinh dựa trên điểm trung bình
//d.Hiển thị học lực của học sinh
#include <iostream>
using namespace std;

int main() {
	float diemToan, diemLy, diemHoa, diemTrungBinh;

	// Nhập vào điểm 3 môn học
	cout << "Nhập điểm Toán: ";
	cin >> diemToan;
	cout << "Nhập điểm Lý: ";
	cin >> diemLy;
	cout << "Nhập điểm Hóa: ";
	cin >> diemHoa;

	// Tính điểm trung bình
	diemTrungBinh = ((diemToan * 2) + diemLy + diemHoa) / 4;

	// Xác định học lực
	string hocLuc;

	if (diemTrungBinh >= 9.0) {
		hocLuc = "Xuất sắc";
	}
	else if (diemTrungBinh >= 8.0) {
		hocLuc = "Giỏi";
	}
	else if (diemTrungBinh >= 7.0) {
		hocLuc = "Khá";
	}
	else if (diemTrungBinh >= 6.0) {
		hocLuc = "Trung bình khá";
	}
	else if (diemTrungBinh >= 5.0) {
		hocLuc = "Trung bình";
	}
	else {
		hocLuc = "Kém";
	}

	// Hiển thị kết quả
	cout << "Điểm trung bình: " << diemTrungBinh << endl;
	cout << "Học lực: " << hocLuc << endl;

	return 0;
}

//Bài 8: Hãy sử dụng kiến thức đã được học về C++ để giải phương trình bậc 2 có dạng ax2
//+ bx + c = 0 (a # 0)
#include <iostream>
#include <cmath>  // Thư viện math để sử dụng hàm sqrt
using namespace std;

int main() {
	float a, b, c, delta, x1, x2;

	// Nhập vào các hệ số a, b, c
	cout << "Nhập hệ số a: ";
	cin >> a;
	cout << "Nhập hệ số b: ";
	cin >> b;
	cout << "Nhập hệ số c: ";
	cin >> c;

	// Kiểm tra điều kiện a phải khác 0
	if (a == 0) {
		cout << "Giá trị a phải khác 0 để là phương trình bậc 2!" << endl;
		return 1; // Thoát chương trình nếu a = 0
	}

	// Tính biệt thức delta
	delta = b * b - 4 * a * c;

	// Xử lý các trường hợp dựa trên giá trị của delta
	if (delta > 0) {
		// Hai nghiệm phân biệt
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "Phương trình có hai nghiệm phân biệt:\n";
		cout << "Nghiệm thứ nhất: x1 = " << x1 << endl;
		cout << "Nghiệm thứ hai: x2 = " << x2 << endl;
	}
	else if (delta == 0) {
		// Nghiệm kép
		x1 = -b / (2 * a);
		cout << "Phương trình có một nghiệm kép: x = " << x1 << endl;
	}
	else {
		// Vô nghiệm
		cout << "Phương trình vô nghiệm (delta < 0)" << endl;
	}

	return 0;
}

//Bài 1: Viết chương trình nhập vào 1 ký tự bất kỳ từ bàn phím, kiểm tra xem ký tự đó có
//nằm trong khoảng từ ‘a’ tới ‘z’ không.Nếu thuộc khoảng đó thì chuyển thành ký tự hoa
//rồi in ra màn hình.Nếu không thuộc khoảng đó thì in ra dòng chữ[Ký tự vừa nhập không
//thuộc khoảng từ ‘a’ tới ‘z’]
//Gợi ý : #include “ctype.h”
//int tolower(char c); int toupper(char c);
#include <iostream>
#include <cctype>  // Thư viện cctype để sử dụng hàm toupper()

using namespace std;

int main() {
	char c;

	// Nhập vào ký tự
	cout << "Nhập vào một ký tự: ";
	cin >> c;

	// Kiểm tra nếu ký tự nằm trong khoảng 'a' đến 'z'
	if (c >= 'a' && c <= 'z') {
		// Chuyển ký tự thành chữ hoa và in ra
		c = toupper(c);
		cout << "Ký tự hoa: " << c << endl;
	}
	else {
		// Ký tự không nằm trong khoảng 'a' đến 'z'
		cout << "Ký tự vừa nhập không thuộc khoảng từ 'a' tới 'z'" << endl;
	}

	return 0;
}

//Bài 2: Viết chương trình tính lương cho nhân viên trong 1 tuần. Biết rằng:
//Một tuần nhân viên phải làm 40h với mức lương 10$ / 1h.
//Nếu làm thêm giờ vào các ngày từ thứ 2 tới thứ 6 thì được hưởng 12$ / h.
//Nếu làm thêm vào thứ 7 và chủ nhật thì lương là 18$ / h.
//VD: Chương trình nhập số giờ theo format :
//Số giờ làm thêm từ thứ 2 tới thứ 6 : 10
//Số giờ làm thêm thứ 7 và chủ nhật : 10
//Kết quả :
//Tổng số tiền được nhận là : 700$
#include <iostream>
using namespace std;

int main() {
	// Khai báo các biến
	int extraWeekdays, extraWeekend;
	const int baseHours = 40;
	const int baseRate = 10;
	const int weekdayExtraRate = 12;
	const int weekendExtraRate = 18;

	// Nhập số giờ làm thêm
	cout << "Số giờ làm thêm từ thứ 2 tới thứ 6: ";
	cin >> extraWeekdays;

	cout << "Số giờ làm thêm thứ 7 và chủ nhật: ";
	cin >> extraWeekend;

	// Tính lương cơ bản cho 40 giờ
	int baseSalary = baseHours * baseRate;

	// Tính lương làm thêm giờ
	int extraSalaryWeekdays = extraWeekdays * weekdayExtraRate;
	int extraSalaryWeekend = extraWeekend * weekendExtraRate;

	// Tổng lương = lương cơ bản + lương làm thêm
	int totalSalary = baseSalary + extraSalaryWeekdays + extraSalaryWeekend;

	// In kết quả
	cout << "Tổng số tiền được nhận là: " << totalSalary << "$" << endl;

	return 0;
}

//Bài 3: Viết chương trình nhập vào 3 giá trị nguyên dương a, b, c. Kiểm tra xem a, b, c có
//phải là 3 cạnh của tam giác không.Nếu là 3 cạnh của tam giác thì tính diện tích của tam
//giác theo công thức :
//S = √𝑝. (𝑝 − 𝑎). (𝑝 − 𝑏). (𝑝 − 𝑐) với p là nửa chu vi của tam giác
#include <iostream>
#include <cmath>  // Để sử dụng hàm sqrt() tính căn bậc hai
using namespace std;

int main() {
	// Khai báo 3 cạnh a, b, c
	int a, b, c;

	// Nhập vào 3 giá trị nguyên dương a, b, c
	cout << "Nhập vào cạnh a: ";
	cin >> a;
	cout << "Nhập vào cạnh b: ";
	cin >> b;
	cout << "Nhập vào cạnh c: ";
	cin >> c;

	// Kiểm tra điều kiện tam giác
	if (a + b > c && a + c > b && b + c > a) {
		// Tính nửa chu vi p
		double p = (a + b + c) / 2.0;

		// Tính diện tích theo công thức Heron
		double area = sqrt(p * (p - a) * (p - b) * (p - c));

		// In kết quả diện tích
		cout << "Diện tích tam giác là: " << area << endl;
	}
	else {
		cout << "a, b, c không phải là 3 cạnh của một tam giác hợp lệ!" << endl;
	}

	return 0;
}

//Bài 4: Viết chương trình nhập vào 3 số nguyên rồi in ra màn hình theo thứ tự tăng dần và
//theo thứ tự giảm dần.
#include <iostream>
#include <algorithm>  // Để sử dụng hàm sort()
using namespace std;

int main() {
	// Khai báo 3 số nguyên
	int a, b, c;

	// Nhập vào ba số nguyên
	cout << "Nhập vào số nguyên a: ";
	cin >> a;
	cout << "Nhập vào số nguyên b: ";
	cin >> b;
	cout << "Nhập vào số nguyên c: ";
	cin >> c;

	// Sắp xếp 3 số theo thứ tự tăng dần
	int arr[3] = { a, b, c };
	sort(arr, arr + 3);

	// In ra các số theo thứ tự tăng dần
	cout << "Thứ tự tăng dần: " << arr[0] << " " << arr[1] << " " << arr[2] << endl;

	// In ra các số theo thứ tự giảm dần
	cout << "Thứ tự giảm dần: " << arr[2] << " " << arr[1] << " " << arr[0] << endl;

	return 0;
}

//Bài 5: Viết chương trình tỉnh giai thừa của một số tự nhiên nhập từ bàn phím.
#include <iostream>
using namespace std;

int main() {
	int n;
	unsigned long long factorial = 1;  // Sử dụng kiểu dữ liệu unsigned long long để chứa kết quả lớn

	// Nhập vào số nguyên n
	cout << "Nhập vào một số tự nhiên n: ";
	cin >> n;

	// Kiểm tra điều kiện đầu vào
	if (n < 0) {
		cout << "Giai thừa không tồn tại với số âm." << endl;
	}
	else {
		// Tính giai thừa của n
		for (int i = 1; i <= n; ++i) {
			factorial *= i;
		}

		// In ra kết quả giai thừa
		cout << "Giai thừa của " << n << " là: " << factorial << endl;
	}

	return 0;
}

//Bài 6: Viết chương trình nhập vào số tự nhiên n rồi in ra tất cả các ước của số đó và tính
//tổng các ước đó.
#include <iostream>
using namespace std;

int main() {
	int n;
	int sum = 0;  // Biến lưu tổng các ước

	// Nhập vào số tự nhiên n
	cout << "Nhập vào một số tự nhiên n: ";
	cin >> n;

	cout << "Các ước của " << n << " là: ";
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {  // Nếu i là ước của n
			cout << i << " ";  // In ước ra màn hình
			sum += i;  // Cộng ước vào tổng
		}
	}

	// In ra tổng các ước
	cout << "\nTổng các ước của " << n << " là: " << sum << endl;

	return 0;
}

//Bài 7: Viết chương trình tính tổng bình phương các số lẻ từ 1 tới N. N được nhập từ bàn
//phím.
#include <iostream>
using namespace std;

int main() {
	int N, sum = 0;

	// Nhập vào số N
	cout << "Nhập vào số tự nhiên N: ";
	cin >> N;

	// Tính tổng bình phương của các số lẻ từ 1 đến N
	for (int i = 1; i <= N; i++) {
		if (i % 2 != 0) {  // Kiểm tra nếu i là số lẻ
			sum += i * i;  // Cộng bình phương của i vào tổng
		}
	}

	// In kết quả
	cout << "Tổng bình phương các số lẻ từ 1 tới " << N << " là: " << sum << endl;

	return 0;
}

//Bài 8: Viết chương trình nhập vào N số nguyên(N được người dùng nhập vào), đếm xem
//có bao nhiêu số âm, số dương vào bao nhiêu số không.Tính tổng các số âm, tính tổng các
//số dương và hiển thị ra màn hình.
#include <iostream>
using namespace std;

int main() {
	int N;
	int num;
	int negativeCount = 0, positiveCount = 0, zeroCount = 0;
	int sumNegative = 0, sumPositive = 0;

	// Nhập số lượng các số nguyên
	cout << "Nhập vào số lượng các số nguyên N: ";
	cin >> N;

	// Nhập các số nguyên và kiểm tra các điều kiện
	for (int i = 0; i < N; ++i) {
		cout << "Nhập số nguyên thứ " << i + 1 << ": ";
		cin >> num;

		if (num < 0) {  // Nếu là số âm
			negativeCount++;
			sumNegative += num;  // Cộng dồn tổng các số âm
		}
		else if (num > 0) {  // Nếu là số dương
			positiveCount++;
			sumPositive += num;  // Cộng dồn tổng các số dương
		}
		else {  // Nếu là số không
			zeroCount++;
		}
	}

	// In kết quả
	cout << "\nSố lượng số âm: " << negativeCount << endl;
	cout << "Số lượng số dương: " << positiveCount << endl;
	cout << "Số lượng số không: " << zeroCount << endl;
	cout << "Tổng các số âm: " << sumNegative << endl;
	cout << "Tổng các số dương: " << sumPositive << endl;

	return 0;
}

//Bài 9: Viết chương trình nhập vào tháng, in ra tháng đó có bao nhiêu ngày. Nếu tháng đã
//nhập không đúng thì hiển thị dòng thông báo[Không phải tháng]
#include <iostream>
using namespace std;

int main() {
	int month;

	// Nhập tháng
	cout << "Nhập vào tháng (1-12): ";
	cin >> month;

	// Kiểm tra tháng hợp lệ và in số ngày tương ứng
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		cout << "Tháng " << month << " có 31 ngày." << endl;
		break;
	case 4: case 6: case 9: case 11:
		cout << "Tháng " << month << " có 30 ngày." << endl;
		break;
	case 2:
		cout << "Tháng " << month << " có 28 ngày." << endl;  // Giả sử tháng 2 có 28 ngày
		break;
	default:
		cout << "Không phải tháng" << endl;  // Nếu tháng không hợp lệ
		break;
	}

	return 0;
}

//Bài 10: Viết chương trình xác định biến ký tự color rồi in ra thông báo:
//RED: nếu color = ‘R’ hoặc ‘r’
//GREEN : nếu color = ‘G’ hoặc ‘g’
//BLUE : nếu color = ‘B’ hoặc ‘b’
//BLACK : nếu color có giá trị khác.
#include <iostream>
using namespace std;

int main() {
	char color;

	// Nhập ký tự màu
	cout << "Nhập vào ký tự màu: ";
	cin >> color;

	// Kiểm tra và in ra thông báo tương ứng với màu
	if (color == 'R' || color == 'r') {
		cout << "RED" << endl;
	}
	else if (color == 'G' || color == 'g') {
		cout << "GREEN" << endl;
	}
	else if (color == 'B' || color == 'b') {
		cout << "BLUE" << endl;
	}
	else {
		cout << "BLACK" << endl;
	}

	return 0;
}

//Bài 11: Viết chương trình nhập vào 2 số x , y và 1 trong 4 toán tử +, -, *, /. Nếu là + thì in
//ra kết quả x + y, nếu là – thì in ra x – y, nếu là* thì in ra x* y, nếu là / thì in ra x / y(nếu y =
//0 thì thông báo không chia được.).
#include <iostream>
using namespace std;

int main() {
	float x, y;
	char op;

	// Nhập vào hai số x, y và một toán tử
	cout << "Nhập vào số x: ";
	cin >> x;
	cout << "Nhập vào số y: ";
	cin >> y;
	cout << "Nhập vào toán tử (+, -, *, /): ";
	cin >> op;

	// Kiểm tra toán tử và thực hiện phép toán
	if (op == '+') {
		cout << "Kết quả: " << x + y << endl;
	}
	else if (op == '-') {
		cout << "Kết quả: " << x - y << endl;
	}
	else if (op == '*') {
		cout << "Kết quả: " << x * y << endl;
	}
	else if (op == '/') {
		if (y == 0) {
			cout << "Không chia được." << endl;
		}
		else {
			cout << "Kết quả: " << x / y << endl;
		}
	}
	else {
		cout << "Toán tử không hợp lệ." << endl;
	}

	return 0;
}

//Bài 12: Viết chương trình nhập vào 1 số tự nhiên và in ra thông báo xem đó là thứ mấy
//trong tuần.Nếu thứ không hợp lệ thì in ra dòng thông báo[Không phải thứ trong tuần.]
#include <iostream>
using namespace std;

int main() {
	int day;

	// Nhập số tự nhiên
	cout << "Nhập vào số tự nhiên (1 đến 7): ";
	cin >> day;

	// Kiểm tra và in ra thứ trong tuần
	switch (day) {
	case 1:
		cout << "Thứ 2" << endl;
		break;
	case 2:
		cout << "Thứ 3" << endl;
		break;
	case 3:
		cout << "Thứ 4" << endl;
		break;
	case 4:
		cout << "Thứ 5" << endl;
		break;
	case 5:
		cout << "Thứ 6" << endl;
		break;
	case 6:
		cout << "Thứ 7" << endl;
		break;
	case 7:
		cout << "Chủ Nhật" << endl;
		break;
	default:
		cout << "Không phải thứ trong tuần." << endl;
	}

	return 0;
}

//Bài 1: Nhập một kí tự. Cho biết kí tự đó có phải là chữ cái hay không.
#include <iostream>
#include <cctype> // Thư viện để sử dụng isalpha()
using namespace std;

int main() {
	char c;

	// Nhập ký tự
	cout << "Nhập một kí tự: ";
	cin >> c;

	// Kiểm tra xem ký tự có phải là chữ cái không
	if (isalpha(c)) {
		cout << "Là chữ cái" << endl;
	}
	else {
		cout << "Không phải chữ cái" << endl;
	}

	return 0;
}

//Bài 2: Tính giá trị hàm
#include <iostream>
#include <cmath> // Thư viện cho các hàm toán học như sqrt và exp

using namespace std;

double fx_a(double x) {
	if (x > 0) {
		return 3 * x + sqrt(x);
	}
	else {
		return exp(x) + 4;
	}
}

double fx_b(double x) {
	if (x >= 1) {
		return sqrt(x * x + 1);
	}
	else if (x > -1 && x < 1) {
		return 3 * x + 5;
	}
	else { // x <= -1
		return x * x + 2 * x - 1;
	}
}

int main() {
	// Test phần a
	double x1 = 2.0;
	double x2 = -1.0;
	cout << "f_a(" << x1 << ") = " << fx_a(x1) << endl;
	cout << "f_a(" << x2 << ") = " << fx_a(x2) << endl;

	// Test phần b
	double x3 = 2.0;
	double x4 = 0.0;
	double x5 = -2.0;
	cout << "f_b(" << x3 << ") = " << fx_b(x3) << endl;
	cout << "f_b(" << x4 << ") = " << fx_b(x4) << endl;
	cout << "f_b(" << x5 << ") = " << fx_b(x5) << endl;

	return 0;
}

//Bài 3: Nhập vào tuổi cha và tuổi con hiện nay sao cho tuổi cha lớn hơn 2 lần tuổi con. Tìm
//xem bao nhiêu năm nữa tuổi cha sẽ bằng đúng 2 lần tuổi con(ví dụ 30 và 12, sau 6 năm
//nữa tuổi cha là 36 gấp đôi tuổi con là 18).
#include <iostream>
using namespace std;

int main() {
	int ageFather, ageSon;
	int years = 0;

	// Nhập tuổi cha và tuổi con
	cout << "Nhập tuổi cha: ";
	cin >> ageFather;
	cout << "Nhập tuổi con: ";
	cin >> ageSon;

	// Kiểm tra điều kiện ban đầu, tuổi cha phải lớn hơn 2 lần tuổi con
	if (ageFather <= 2 * ageSon) {
		cout << "Tuổi cha phải lớn hơn 2 lần tuổi con." << endl;
		return 0; // Nếu điều kiện không thỏa mãn thì kết thúc chương trình
	}

	// Tính số năm để tuổi cha gấp đôi tuổi con
	while (ageFather != 2 * ageSon) {
		ageFather++;
		ageSon++;
		years++;
	}

	// In kết quả
	cout << "Số năm nữa tuổi cha sẽ bằng đúng 2 lần tuổi con là: " << years << " năm." << endl;

	return 0;
}

//Bài 4: Nhập số nguyên dương N. Tính:
#include <iostream>
#include <cmath> // Thư viện cho hàm sqrt

using namespace std;

int main() {
	int N;
	cout << "Nhap so nguyen duong N: ";
	cin >> N;

	// Tính S1
	int sum1 = 0;
	for (int i = 1; i <= N; ++i) {
		sum1 += i;
	}
	double S1 = static_cast<double>(sum1) / N;

	// Tính S2
	int sum2 = 0;
	for (int i = 1; i <= N; ++i) {
		sum2 += i * i;
	}
	double S2 = sqrt(sum2);

	// In kết quả
	cout << "S1 = " << S1 << endl;
	cout << "S2 = " << S2 << endl;

	return 0;
}

//Bài 5: In ra màn hình các số có 2 chữ số sao cho tích của 2 chữ số này bằng 2 lần tổng của
//2 chữ số đó(ví dụ số 36 có tích 3 * 6 = 18 gấp 2 lần tổng của nó là 3 + 6 = 9).
#include <iostream>
using namespace std;

int main() {
	// Duyệt qua tất cả các số có 2 chữ số từ 10 đến 99
	for (int num = 10; num <= 99; num++) {
		// Tách chữ số hàng chục và hàng đơn vị
		int a = num / 10;  // Chữ số hàng chục
		int b = num % 10;  // Chữ số hàng đơn vị

		// Kiểm tra điều kiện: tích của 2 chữ số = 2 lần tổng của 2 chữ số
		if (a * b == 2 * (a + b)) {
			cout << num << endl;
		}
	}

	return 0;
}

//Bài 6: Tìm số nguyên dương n lớn nhất thoả mãn điều kiện:
#include <iostream>
#include <cmath> // Thư viện cho các hàm toán học như log, exp

using namespace std;

// Hàm tính tổng của dãy cho phần a
double sum_series_a(int n) {
	double sum = 1.0; // Bắt đầu từ 1
	for (int i = 1; i < n; ++i) {
		sum += 1.0 / (2 * i + 1);
	}
	return sum;
}

// Hàm kiểm tra điều kiện phần b
bool check_condition_b(int n) {
	double result = exp(n) - 1999 * log10(n);
	return result < 2000;
}

int main() {
	// Tìm số nguyên dương n lớn nhất thỏa mãn điều kiện phần a
	int n_a = 1;
	while (sum_series_a(n_a + 1) < 2.101999) {
		++n_a;
	}
	cout << "So nguyen duong n lon nhat thoa man dieu kien phan a la: " << n_a << endl;

	// Tìm số nguyên dương n lớn nhất thỏa mãn điều kiện phần b
	int n_b = 1;
	while (check_condition_b(n_b + 1)) {
		++n_b;
	}
	cout << "So nguyen duong n lon nhat thoa man dieu kien phan b la: " << n_b << endl;

	return 0;
}

//Bài 1: Sử dụng for, while, do while để cho ra kết quả a, b, c, d như ảnh
#include <iostream>
using namespace std;

// Hàm in tam giác vuông cân (kích thước tam giác là 8)
void printTriangle(int n) {
	// In tam giác vuông cân có cạnh là n
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "#";
		}
		cout << endl;
	}
}

// Hàm in tam giác quay 90 độ
void printRotated90(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "#";
		}
		cout << endl;
	}
}

// Hàm in tam giác quay 180 độ
void printRotated180(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			cout << "#";
		}
		cout << endl;
	}
}

// Hàm in tam giác quay 270 độ
void printRotated270(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";  // In khoảng trắng
		}
		for (int j = 1; j <= i; j++) {
			cout << "#";  // In dấu '#'
		}
		cout << endl;
	}
}

int main() {
	int n = 8;  // Cạnh tam giác vuông cân

	// In hình tam giác 4 lần: lần lượt theo các góc 0, 90, 180, 270 độ
	cout << "Tam giác vuông cân (ban đầu):" << endl;
	printTriangle(n);  // In tam giác vuông cân ban đầu
	cout << endl;

	cout << "Tam giác vuông cân quay 90 độ:" << endl;
	printRotated90(n);  // Quay 90 độ
	cout << endl;

	cout << "Tam giác vuông cân quay 180 độ:" << endl;
	printRotated180(n);  // Quay 180 độ
	cout << endl;

	cout << "Tam giác vuông cân quay 270 độ:" << endl;
	printRotated270(n);  // Quay 270 độ
	cout << endl;

	return 0;
}

//Bài 2:
//Xây dựng chương trình c / c++ cho phép người dùng nhập thông tin :
//✓ Tổng số tiền ăn cần phải trả
//✓ Số người đi ăn
//✓ Tiền thuế(% VAT)
//✓ Tiền bo
//Sau đó thực hiện tính toán gồm các thông tin : Tổng tiền trước VAT, tiền VAT, Tổng
// sau VAT = (Tổng tiền trước VAT + Tiền bo + Tiền VAT).
#include <iostream>
using namespace std;

int main() {
	// Khai báo các biến
	double totalAmount, taxRate, tip, totalBeforeVAT, VATAmount, totalAfterVAT;
	int numPeople;

	// Nhập thông tin từ người dùng
	cout << "Nhập tổng số tiền ăn cần phải trả: ";
	cin >> totalAmount;

	cout << "Nhập số người đi ăn: ";
	cin >> numPeople;

	cout << "Nhập tỷ lệ thuế VAT (%): ";
	cin >> taxRate;

	cout << "Nhập tiền bo: ";
	cin >> tip;

	// Tính toán
	// Tính tổng tiền trước VAT (bằng tổng số tiền ăn chia cho 1 + tỷ lệ VAT)
	totalBeforeVAT = totalAmount / (1 + taxRate / 100);

	// Tính tiền VAT
	VATAmount = totalBeforeVAT * (taxRate / 100);

	// Tính tổng tiền sau VAT (bao gồm tiền bo và tiền VAT)
	totalAfterVAT = totalBeforeVAT + VATAmount + tip;

	// In kết quả
	cout << "Tổng tiền trước VAT: " << totalBeforeVAT << endl;
	cout << "Tiền VAT: " << VATAmount << endl;
	cout << "Tổng tiền sau VAT: " << totalAfterVAT << endl;

	return 0;
}

//Bài 3:Viết chương trình liệt kê tất cả các số nguyên tố có 5 chữ số sao cho tổng của các
//chữ số
//trong mỗi số nguyên tố đều bằng S cho trước.
//Chỉ cần kiểm tra đến sqrt(n).Đó là vì nếu n là hợp số thì nó chắc chắn có ước số
//không vượt quá sqrt(n)
#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra một số có phải là số nguyên tố không
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// Hàm tính tổng các chữ số của một số
int sumOfDigits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int S;
	cout << "Nhập tổng các chữ số S: ";
	cin >> S;

	// Duyệt các số nguyên tố có 5 chữ số
	for (int num = 10000; num <= 99999; num++) {
		if (isPrime(num) && sumOfDigits(num) == S) {
			cout << num << " ";
		}
	}

	return 0;
}

//Bài 4: Một người gửi tiết kiệm không kì hạn với số tiền X đồng với lãi suất 0.5% mỗi tháng.
//Hỏi sau n tháng, người đó rút hết tiền thì sẽ được số tiền là bao nhiêu ? Biết rằng với
//việc gửi tiết kiệm không kì hạn thì lãi được cộng vào vốn theo từng tháng.
#include <iostream>
#include <cmath> // Thư viện để tính lũy thừa
using namespace std;

int main() {
	double X, S;
	int n;
	const double r = 0.005; // Lãi suất 0.5% mỗi tháng

	// Nhập số tiền gốc và số tháng
	cout << "Nhập số tiền gốc (X): ";
	cin >> X;
	cout << "Nhập số tháng (n): ";
	cin >> n;

	// Tính số tiền sau n tháng với lãi suất 0.5% mỗi tháng
	S = X * pow(1 + r, n);

	// In kết quả
	cout << "Số tiền sau " << n << " tháng là: " << S << " đồng." << endl;

	return 0;
}

//Bài 5:
//Viết chương trình tính n!với n là số tự nhiên không âm nhập vào từ bàn phím.
//Trong đó :
//0!= 1
//n!= 1.2.3…n
#include <iostream>
using namespace std;

int main() {
	int n;
	long long factorial = 1;  // Dùng long long để tránh tràn số khi tính giai thừa lớn

	// Nhập số n
	cout << "Nhập số tự nhiên n: ";
	cin >> n;

	// Kiểm tra nếu n là số âm (giai thừa không xác định cho số âm)
	if (n < 0) {
		cout << "Không thể tính giai thừa cho số âm." << endl;
		return 0;
	}

	// Tính giai thừa n!
	for (int i = 1; i <= n; ++i) {
		factorial *= i;
	}

	// In kết quả
	cout << "Giai thừa của " << n << " là: " << factorial << endl;

	return 0;
}

//Bài 6:
//Viết chương trình kiểm tra mật khẩu người dùng khi đăng nhập.Người dùng phải
//đăng nhập khi đến khi nào đúng username và password thì thôi. (username và
//password được định nghĩa trước trong chương trình)
#include <iostream>
#include <string>
using namespace std;

int main() {
	string correct_username = "user123";  // Username đúng
	string correct_password = "pass456";  // Mật khẩu đúng

	string username, password;  // Biến để lưu username và password nhập vào

	// Kiểm tra việc nhập username và password
	while (true) {
		// Nhập username và password từ người dùng
		cout << "Nhập username: ";
		cin >> username;

		cout << "Nhập password: ";
		cin >> password;

		// Kiểm tra username và password
		if (username == correct_username && password == correct_password) {
			cout << "Đăng nhập thành công!" << endl;
			break;  // Thoát khỏi vòng lặp nếu đúng
		}
		else {
			cout << "Username hoặc password không đúng, vui lòng thử lại." << endl;
		}
	}

	return 0;
}
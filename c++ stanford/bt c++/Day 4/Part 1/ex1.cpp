#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
using namespace std;

class TinhToan
{
private:
	static constexpr double PI = 3.14;

	static void kiemTraDuong(double val, const string &tenThamSo)
	{
		if (val <= 0)
			throw invalid_argument(tenThamSo + " phai la so duong.");
	}

public:
	double chuViHCN(double dai, double rong)
	{
		kiemTraDuong(dai, "Chieu dai");
		kiemTraDuong(rong, "Chieu rong");
		return 2.0 * (dai + rong);
	}

	double dienTichHCN(double dai, double rong)
	{
		kiemTraDuong(dai, "Chieu dai");
		kiemTraDuong(rong, "Chieu rong");
		return dai * rong;
	}

	double chuViHinhTron(double r)
	{
		kiemTraDuong(r, "Ban kinh");
		return 2.0 * PI * r;
	}

	double dienTichHinhTron(double r)
	{
		kiemTraDuong(r, "Ban kinh");
		return PI * r * r;
	}

	double dienTichHinhThang(double dayLon, double dayBe, double chieuCao)
	{
		kiemTraDuong(dayLon, "Day lon");
		kiemTraDuong(dayBe, "Day be");
		kiemTraDuong(chieuCao, "Chieu cao");
		return (dayLon + dayBe) * chieuCao / 2.0;
	}

	long long giaiThua(int n)
	{
		if (n < 0)
			throw invalid_argument("Giai thua khong xac dinh voi so am.");
		long long ketQua = 1;
		for (int i = 2; i <= n; i++)
			ketQua *= i;
		return ketQua;
	}
};

double nhapSoDuong(const string &loi)
{
	double val;
	while (true)
	{
		cout << loi;
		cin >> val;
		if (cin.fail() || val <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Gia tri phai la so duong. Nhap lai.\n";
		}
		else
		{
			return val;
		}
	}
}

int nhapSoNguyen(const string &loi)
{
	int val;
	while (true)
	{
		cout << loi;
		cin >> val;
		if (cin.fail() || val < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Gia tri phai >= 0. Nhap lai.\n";
		}
		else
		{
			return val;
		}
	}
}

void menu()
{
	cout << "\n====================================\n";
	cout << "          TINH TOAN HINH HOC\n";
	cout << "====================================\n";
	cout << "1. Hinh chu nhat (chu vi + dien tich)\n";
	cout << "2. Hinh tron (chu vi + dien tich)\n";
	cout << "3. Hinh thang (dien tich)\n";
	cout << "4. Giai thua n!\n";
	cout << "0. Thoat\n";
	cout << "Chon: ";
}

int main(int argc, char const *argv[])
{
	TinhToan tt;
	cout << fixed << setprecision(4);

	int lua;
	do
	{
		menu();
		cin >> lua;
		cout << endl;

		try
		{
			switch (lua)
			{
			case 1:
			{
				double dai = nhapSoDuong("Chieu dai : ");
				double rong = nhapSoDuong("Chieu rong : ");
				cout << "Chu vi = " << tt.chuViHCN(dai, rong) << endl;
				cout << "Dien tich = " << tt.dienTichHCN(dai, rong) << endl;
				break;
			}
			case 2:
			{
				double r = nhapSoDuong("Ban kinh r: ");
				cout << "Chu vi = " << tt.chuViHinhTron(r) << endl;
				cout << "Dien tich = " << tt.dienTichHinhTron(r) << endl;
				break;
			}
			case 3:
			{
				double dayLon = nhapSoDuong("Day lon: ");
				double dayBe = nhapSoDuong("Day be: ");
				double chieuCao = nhapSoDuong("Chieu cao: ");
				cout << "Dien tich = " << tt.dienTichHinhThang(dayLon, dayBe, chieuCao) << endl;
				break;
			}
			case 4:
			{
				int n = nhapSoNguyen("Nhap n: ");
				cout << n << "! = " << tt.giaiThua(n) << endl;
				break;
			}
			case 0:
				cout << "Tam biet!\n";
				break;
			default:
				cout << "Lua chon khong hop le!\n";
			}
		}
		catch (const exception &e)
		{
			cout << "Loi: " << e.what() << endl;
		}
	} while (lua != 0);

	return 0;
}
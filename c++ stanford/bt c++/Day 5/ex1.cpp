#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;

class TinhToan
{
protected:
	static void kiemTraDuong(double val, const string &ten)
	{
		if (val <= 0)
			throw invalid_argument(ten + " phai la so duong.");
	}

public:
	virtual ~TinhToan() = default;

	virtual double chuVi() const = 0;
	virtual double dienTich() const = 0;

	virtual void inThongTin() const
	{
		cout << fixed << setprecision(4);
		cout << "Chu vi: " << chuVi() << endl;
		cout << "Dien tich: " << dienTich() << endl;
	}
};

class HinhTron : public TinhToan
{
private:
	static constexpr double PI = 3.14;
	double r;

public:
	explicit HinhTron(double banKinh)
	{
		kiemTraDuong(banKinh, "Ban kinh");
		r = banKinh;
	}

	double chuVi() const override { return 2.0 * PI * r; }
	double dienTich() const override { return PI * r * r; }

	void inThongTin() const override
	{
		cout << "[Hinh Tron] ban kinh = " << r << endl;
		TinhToan::inThongTin();
	}
};

class HinhChuNhat : public TinhToan
{
private:
	double dai, rong;

public:
	HinhChuNhat(double chieuDai, double chieuRong)
	{
		kiemTraDuong(chieuDai, "Chieu dai");
		kiemTraDuong(chieuRong, "Chieu rong");
		dai = chieuDai;
		rong = chieuRong;
	}

	double chuVi() const override { return 2.0 * (dai + rong); }
	double dienTich() const override { return dai * rong; }

	void inThongTin() const override
	{
		cout << "[Hinh Chu Nhat] dai = " << dai << ", rong = " << rong << endl;
		TinhToan::inThongTin();
	}
};

class HinhThang : public TinhToan
{
private:
	double dayLon, dayBe, chieuCao;
	double canh1, canh2;

public:
	HinhThang(double dl, double db, double cc,
			  double c1 = 0.0, double c2 = 0.0)
	{
		kiemTraDuong(dl, "Day lon");
		kiemTraDuong(db, "Day be");
		kiemTraDuong(cc, "Chieu cao");
		dayLon = dl;
		dayBe = db;
		chieuCao = cc;
		canh1 = c1;
		canh2 = c2;
	}

	double dienTich() const override
	{
		return (dayLon + dayBe) * chieuCao / 2.0;
	}

	double chuVi() const override
	{
		if (canh1 <= 0 || canh2 <= 0)
			return -1;
		return dayLon + dayBe + canh1 + canh2;
	}

	void inThongTin() const override
	{
		cout << "[Hinh Thang] day lon = " << dayLon
			 << ", day be = " << dayBe
			 << ", chieu cao = " << chieuCao << endl;
		cout << fixed << setprecision(4);
		cout << "Dien tich: " << dienTich() << endl;
		if (chuVi() > 0)
			cout << "Chu vi: " << chuVi() << endl;
		else
			cout << "Chu vi: (khong du du lieu canh ben)" << endl;
	}
};

double nhapSoDuong(const string &loi)
{
	double val;
	while (true)
	{
		cout << loi;
		if (cin >> val && val > 0)
			return val;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Phai la so duong. Nhap lai.\n";
	}
}

void inThongTinQua(const TinhToan *h)
{
	h->inThongTin();
}

void menu()
{
	cout << "\n====================================\n";
	cout << "     TINH DIEN TICH HINH HOC\n";
	cout << "====================================\n";
	cout << "1. Hinh Tron\n";
	cout << "2. Hinh Chu Nhat\n";
	cout << "3. Hinh Thang\n";
	cout << "0. Thoat\n";
	cout << "Chon: ";
}

int main(int argc, char const *argv[])
{
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
				double r = nhapSoDuong("Ban kinh r: ");
				HinhTron ht(r);
				inThongTinQua(&ht);
				break;
			}
			case 2:
			{
				double dai = nhapSoDuong("Chieu dai: ");
				double rong = nhapSoDuong("Chieu rong: ");
				HinhChuNhat hcn(dai, rong);
				inThongTinQua(&hcn);
				break;
			}
			case 3:
			{
				double dl = nhapSoDuong("Day lon: ");
				double db = nhapSoDuong("Day be: ");
				double cc = nhapSoDuong("Chieu cao: ");
				cout << "(Nhap 0 neu khong biet canh ben)\n";
				double c1 = nhapSoDuong("Canh ben 1: ");
				double c2 = nhapSoDuong("Canh ben 2: ");
				HinhThang hthang(dl, db, cc, c1, c2);
				inThongTinQua(&hthang);
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
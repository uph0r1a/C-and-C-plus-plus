#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
using namespace std;

class ConNguoi
{
protected:
	string mauMat;
	string mauDa;
	double chieuCao;
	double canNang;

public:
	ConNguoi(const string &mat = "Chua ro",
			 const string &da = "Chua ro",
			 double cc = 0.0,
			 double cn = 0.0)
		: mauMat(mat),
		  mauDa(da),
		  chieuCao(cc),
		  canNang(cn) {}

	virtual ~ConNguoi() = default;

	string getMauMat() const
	{
		return mauMat;
	}

	string getMauDa() const
	{
		return mauDa;
	}

	double getChieuCao() const
	{
		return chieuCao;
	}

	double getCanNang() const
	{
		return canNang;
	}

	void setMauMat(const string &s)
	{
		mauMat = s;
	}

	void setMauDa(const string &s)
	{
		mauDa = s;
	}

	void setChieuCao(double v)
	{
		chieuCao = v;
	}

	void setCanNang(double v)
	{
		canNang = v;
	}

	virtual string tiengNoi() const = 0;

	virtual double chieuCaoTrungBinh() const = 0;

	virtual double canNangTrungBinh() const = 0;

	virtual string quocTich() const = 0;

	virtual void inThongTin() const
	{
		cout << fixed << setprecision(2);
		cout << "Quoc tich: " << quocTich() << "\n";
		cout << "Mau mat: " << mauMat << "\n";
		cout << "Mau da: " << mauDa << "\n";
		cout << "Chieu cao: " << chieuCao << " m"
			 << "(TB chau: " << chieuCaoTrungBinh() << " m)\n";
		cout << "Can nang: " << canNang << " kg"
			 << "(TB chau: " << canNangTrungBinh() << " kg)\n";
		cout << "Tieng noi: " << tiengNoi() << "\n";
		cout << "Chieu cao so TB: "
			 << (chieuCao >= chieuCaoTrungBinh() ? "Dat" : "Chua dat") << "\n";
		cout << "Can nang so TB: "
			 << (canNang >= canNangTrungBinh() ? "Dat" : "Chua dat") << "\n";
	}
};

class NguoiChauA : public ConNguoi
{
public:
	NguoiChauA(const string &mat = "Mau nau",
			   const string &da = "Da vang",
			   double cc = 1.60, double cn = 60.0)
		: ConNguoi(mat, da, cc, cn) {}

	double chieuCaoTrungBinh() const override
	{
		return 1.60;
	}

	double canNangTrungBinh() const override
	{
		return 60.0;
	}

	virtual bool tetNguyenDan() const
	{
		return false;
	}
};

class NguoiChauAu : public ConNguoi
{
public:
	NguoiChauAu(const string &mat = "Mau xanh",
				const string &da = "Da trang",
				double cc = 1.75, double cn = 70.0)
		: ConNguoi(mat, da, cc, cn) {}

	double chieuCaoTrungBinh() const override
	{
		return 1.75;
	}

	double canNangTrungBinh() const override
	{
		return 70.0;
	}
};

class NguoiViet : public NguoiChauA
{
	string phongTucTet;

public:
	NguoiViet(const string &mat = "Mau den",
			  const string &da = "Da vang",
			  double cc = 1.60,
			  double cn = 60.0,
			  const string &ptTet = "Chuc Tet, an banh chung, li xi")
		: NguoiChauA(mat, da, cc, cn),
		  phongTucTet(ptTet) {}

	string tiengNoi() const override
	{
		return "Tieng Viet";
	}

	string quocTich() const override
	{
		return "Viet Nam";
	}

	bool tetNguyenDan() const override
	{
		return true;
	}

	void inThongTin() const override
	{
		cout << "\n--- NGUOI VIET ---\n";
		ConNguoi::inThongTin();
		cout << "Tet Nguyen Dan: Co to chuc\n";
		cout << "Phong tuc Tet: " << phongTucTet << "\n";
	}
};

class NguoiNhat : public NguoiChauA
{
	string phongTucNamMoi;

public:
	NguoiNhat(const string &mat = "Mau den",
			  const string &da = "Da vang",
			  double cc = 1.60,
			  double cn = 60.0,
			  const string &ptNamMoi = "Don Oshogatsu (1/1 duong lich), an Osechi")
		: NguoiChauA(mat, da, cc, cn),
		  phongTucNamMoi(ptNamMoi) {}

	string tiengNoi() const override
	{
		return "Tieng Nhat";
	}

	string quocTich() const override
	{
		return "Nhat Ban";
	}

	bool tetNguyenDan() const override
	{
		return false;
	}

	void inThongTin() const override
	{
		cout << "\n--- NGUOI NHAT ---\n";
		ConNguoi::inThongTin();
		cout << "Tet Nguyen Dan: Khong to chuc\n";
		cout << "Nam moi rieng: " << phongTucNamMoi << "\n";
	}
};

void inThongTinDa(const ConNguoi *nguoi)
{
	nguoi->inThongTin();
}

int main(int argc, char const *argv[])
{
	NguoiViet nam("Mau den", "Da vang", 1.70, 65.0,
				  "Chuc Tet, an banh chung, li xi");

	cout << "Thong tin cua Nam:\n";
	nam.inThongTin();

	cout << "\n========== DANH SACH ==========\n";

	vector<unique_ptr<ConNguoi>> ds;
	ds.push_back(make_unique<NguoiViet>(
		"Mau den", "Da vang", 1.55, 50.0, "Tet am lich, banh chung"));
	ds.push_back(make_unique<NguoiNhat>(
		"Mau den", "Da vang", 1.68, 62.0, "Oshogatsu, Osechi Ryori"));
	ds.push_back(make_unique<NguoiViet>(
		"Mau nau", "Da vang", 1.65, 58.0, "Tet am lich, li xi tre em"));

	for (const auto &nguoi : ds)
	{
		inThongTinDa(nguoi.get());
	}

	cout << "\n====== KIEM TRA TET NGUYEN DAN ======\n";
	for (const auto &nguoi : ds)
	{
		const NguoiChauA *ca = dynamic_cast<const NguoiChauA *>(nguoi.get());
		if (ca)
		{
			cout << ca->quocTich()
				 << "— Tet Nguyen Dan: "
				 << (ca->tetNguyenDan() ? "Co" : "Khong") << "\n";
		}
	}

	return 0;
}
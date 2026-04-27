#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

const long long LUONG_CO_BAN = 4'000'000;
const int NAM_XET_TANG = 2;
const int NAM_HIEN_TAI = 2024;
const double BAC_LUONG[] = {1.5, 2.0, 2.8, 3.2, 4.0, 5.0};
const int SO_BAC = 6;

int timChiSoBac(double hs)
{
	for (int i = 0; i < SO_BAC; i++)
		if (BAC_LUONG[i] == hs)
			return i;
	return -1;
}

class NhanVien
{
private:
	string maNV;
	string hoTen;
	string diaChi;
	int namVao;
	double heSoLuong;
	long long phuCap;
	string phongBan;

public:
	NhanVien()
		: namVao(0),
		  heSoLuong(BAC_LUONG[0]),
		  phuCap(0) {}

	NhanVien(const string &ma, const string &ten, const string &dia, int nam, double hs, long long pc, const string &pb)
		: maNV(ma),
		  hoTen(ten),
		  diaChi(dia),
		  namVao(nam),
		  heSoLuong(hs),
		  phuCap(pc),
		  phongBan(pb) {}

	string getMaNV() const
	{
		return maNV;
	}

	string getHoTen() const
	{
		return hoTen;
	}

	string getDiaChi() const
	{
		return diaChi;
	}

	int getNamVao() const
	{
		return namVao;
	}

	double getHeSoLuong() const
	{
		return heSoLuong;
	}

	long long getPhuCap() const
	{
		return phuCap;
	}

	string getPhongBan() const
	{
		return phongBan;
	}

	void setNamVao(int n)
	{
		namVao = n;
	}

	void setHeSoLuong(double hs)
	{
		heSoLuong = hs;
	}

	void setPhuCap(long long pc)
	{
		phuCap = pc;
	}

	long long tongLuong() const
	{
		return static_cast<long long>(LUONG_CO_BAN * heSoLuong) + phuCap;
	}

	static int tinhNamVao(double hs)
	{
		int bac = timChiSoBac(hs);
		if (bac < 0)
			return NAM_HIEN_TAI;
		return NAM_HIEN_TAI - bac * NAM_XET_TANG;
	}

	double heSoLuongMoi() const
	{
		int bac = timChiSoBac(heSoLuong);
		if (bac < 0 || bac >= SO_BAC - 1)
			return heSoLuong;
		return BAC_LUONG[bac + 1];
	}

	void nhap()
	{
		cin.ignore(1000, '\n');

		cout << "Ma NV: ";
		getline(cin, maNV);
		cout << "Ho ten: ";
		getline(cin, hoTen);
		cout << "Dia chi: ";
		getline(cin, diaChi);

		while (true)
		{
			cout << "He so luong (1.5/2.0/2.8/3.2/4.0/5.0): ";
			cin >> heSoLuong;
			if (timChiSoBac(heSoLuong) >= 0)
				break;
			cout << "Loi: He so luong khong hop le!\n";
		}

		while (true)
		{
			cout << "Phu cap (>= 0): ";
			cin >> phuCap;
			if (phuCap >= 0)
				break;
			cout << "Loi: Phu cap khong duoc am!\n";
		}

		cin.ignore(1000, '\n');
		cout << "Phong ban (CNTT/KD/KT): ";
		getline(cin, phongBan);

		namVao = tinhNamVao(heSoLuong);
	}
};

vector<NhanVien> taoMauDuLieu()
{
	return {
		{"SF1000", "Tran Quoc Tuan", "Ha Noi", 0, 2.0, 300000, "CNTT"},
		{"SF1001", "Nguyen Minh Son", "Nam Dinh", 0, 3.2, 500000, "CNTT"},
		{"SF1002", "Cao Ba Cuong", "Thai Binh", 0, 3.2, 500000, "KT"},
		{"SF1003", "Bui Minh Khue", "Hai Duong", 0, 1.5, 200000, "CNTT"},
		{"SF1004", "Le Hai Ha", "Ha Noi", 0, 2.8, 400000, "KT"},
		{"SF1005", "Dang Hai Nam", "Thai Binh", 0, 1.5, 200000, "KD"},
		{"SF1006", "Vu Phuong Thao", "Ha Nam", 0, 3.2, 500000, "KD"},
		{"SF1007", "Pham Thanh Tung", "Hai Duong", 0, 4.0, 1000000, "CNTT"},
		{"SF1008", "Tran Duc Minh", "Ha Nam", 0, 2.0, 300000, "CNTT"},
		{"SF1009", "Le Minh Huy", "Hai Phong", 0, 2.0, 300000, "KD"},
	};
}

void tinhNamVaoTatCa(vector<NhanVien> &ds)
{
	for (auto &nv : ds)
		nv.setNamVao(NhanVien::tinhNamVao(nv.getHeSoLuong()));
}

const string HEADER =
	"Ma NV      Ho Ten              Dia Chi         NamVao  HeSo    PhuCap      TongLuong   PhongBan";
const string SEPARATOR(98, '-');

string dongNhanVien(const NhanVien &nv, long long phuCapOverride = -1)
{
	long long pc = (phuCapOverride >= 0) ? phuCapOverride : nv.getPhuCap();
	long long tl = static_cast<long long>(LUONG_CO_BAN * nv.getHeSoLuong()) + pc;

	char buf[200];
	snprintf(buf, sizeof(buf),
			 "%-10s %-20s %-15s %-7d %-7.1f %-11lld %-11lld %s",
			 nv.getMaNV().c_str(),
			 nv.getHoTen().c_str(),
			 nv.getDiaChi().c_str(),
			 nv.getNamVao(),
			 nv.getHeSoLuong(),
			 pc, tl,
			 nv.getPhongBan().c_str());
	return string(buf);
}

void inBang(const vector<NhanVien> &ds, long long phuCapExtra = 0)
{
	cout << HEADER << "\n"
		 << SEPARATOR << "\n";
	for (const auto &nv : ds)
		cout << dongNhanVien(nv, nv.getPhuCap() + phuCapExtra) << "\n";
	cout << SEPARATOR << "\n";
}

void hienThiGiamDan(vector<NhanVien> ds)
{
	sort(ds.begin(), ds.end(), [](const NhanVien &a, const NhanVien &b)
		 { return a.tongLuong() > b.tongLuong(); });
	cout << "\n=== 1.3: DANH SACH LUONG GIAM DAN (NAM 2024) ===\n";
	inBang(ds);
}

void timCaoNhatThapNhat(const vector<NhanVien> &ds)
{
	if (ds.empty())
		return;
	auto [itMin, itMax] = minmax_element(ds.begin(), ds.end(),
										 [](const NhanVien &a, const NhanVien &b)
										 {
											 return a.tongLuong() < b.tongLuong();
										 });

	cout << "\n=== 1.4: LUONG CAO NHAT VA THAP NHAT ===\n";
	cout << "\nNhan vien luong CAO NHAT:\n";
	cout << HEADER << "\n"
		 << SEPARATOR << "\n";
	cout << dongNhanVien(*itMax) << "\n";

	cout << "\nNhan vien luong THAP NHAT:\n";
	cout << HEADER << "\n"
		 << SEPARATOR << "\n";
	cout << dongNhanVien(*itMin) << "\n";
}

vector<NhanVien> taoBangLuong2025(const vector<NhanVien> &ds)
{
	vector<NhanVien> ds2025 = ds;
	for (auto &nv : ds2025)
	{
		nv.setHeSoLuong(nv.heSoLuongMoi());
		nv.setPhuCap(nv.getPhuCap() + 500'000);
		nv.setNamVao(NhanVien::tinhNamVao(nv.getHeSoLuong()));
	}
	return ds2025;
}

void hienThiBangLuong2025(vector<NhanVien> ds)
{
	sort(ds.begin(), ds.end(), [](const NhanVien &a, const NhanVien &b)
		 {
        if (a.getPhongBan() != b.getPhongBan())
            return a.getPhongBan() < b.getPhongBan();
        return a.tongLuong() > b.tongLuong(); });

	cout << "\n=== 1.5: BANG LUONG MOI NAM 2025 (THEO PHONG BAN, LUONG GIAM DAN) ===\n";
	string phongHienTai = "";
	for (const auto &nv : ds)
	{
		if (nv.getPhongBan() != phongHienTai)
		{
			phongHienTai = nv.getPhongBan();
			cout << "\n--- Phong ban: " << phongHienTai << " ---\n";
			cout << HEADER << "\n"
				 << SEPARATOR << "\n";
		}
		cout << dongNhanVien(nv) << "\n";
	}
	cout << SEPARATOR << "\n";
}

bool hoiLuuFile()
{
	int chon;
	cout << "\nBan co muon luu ra file? (1 = Co, khac = Khong): ";
	cin >> chon;
	return chon == 1;
}

void luuRaFile(const string &tenFile, const vector<NhanVien> &ds, const string &tieuDe)
{
	ofstream f(tenFile);
	if (!f.is_open())
	{
		cout << "Loi: Khong mo duoc file " << tenFile << "\n";
		return;
	}
	f << tieuDe << "\n";
	f << HEADER << "\n"
	  << string(98, '-') << "\n";
	for (const auto &nv : ds)
		f << dongNhanVien(nv) << "\n";
	f.close();
	cout << "Da luu thanh cong: " << tenFile << "\n";
}

int main(int argc, char const *argv[])
{
	cout << string(80, '*') << "\n";
	cout << "      QUAN LY NHAN SU - BAI KIEM TRA CUOI KHOA C++ \n";
	cout << string(80, '*') << "\n";

	vector<NhanVien> danhSach;
	int luaChon;
	cout << "\n1. Dung du lieu mau\n2. Nhap du lieu tu ban phim\nChon: ";
	cin >> luaChon;

	if (luaChon == 2)
	{
		int soLuong;
		do
		{
			cout << "So luong nhan vien (1-50): ";
			cin >> soLuong;
		} while (soLuong < 1 || soLuong > 50);

		for (int i = 0; i < soLuong; i++)
		{
			cout << "\n--- Nhan vien " << i + 1 << " ---\n";
			NhanVien nv;
			nv.nhap();
			danhSach.push_back(nv);
		}
	}
	else
	{
		danhSach = taoMauDuLieu();
		tinhNamVaoTatCa(danhSach);
		cout << "Da tai du lieu mau (" << danhSach.size() << " nhan vien).\n";
	}

	vector<NhanVien> ds2024 = danhSach;
	sort(ds2024.begin(), ds2024.end(), [](const NhanVien &a, const NhanVien &b)
		 { return a.tongLuong() > b.tongLuong(); });
	hienThiGiamDan(danhSach);

	timCaoNhatThapNhat(danhSach);

	vector<NhanVien> ds2025 = taoBangLuong2025(danhSach);
	hienThiBangLuong2025(ds2025);

	if (hoiLuuFile())
	{
		sort(ds2024.begin(), ds2024.end(), [](const NhanVien &a, const NhanVien &b)
			 { return a.tongLuong() > b.tongLuong(); });
		luuRaFile("files/danhsach_2024.txt", ds2024,
				  "DANH SACH LUONG NAM 2024 (GIAM DAN)");

		vector<NhanVien> ds2025_sorted = ds2025;
		sort(ds2025_sorted.begin(), ds2025_sorted.end(),
			 [](const NhanVien &a, const NhanVien &b)
			 {
				 if (a.getPhongBan() != b.getPhongBan())
					 return a.getPhongBan() < b.getPhongBan();
				 return a.tongLuong() > b.tongLuong();
			 });
		luuRaFile("files/bangluong_2025.txt", ds2025_sorted,
				  "BANG LUONG MOI NAM 2025 (THEO PHONG BAN, LUONG GIAM DAN)");
	}

	cout << "\nChuong trinh ket thuc. Cam on!\n";
	return 0;
}
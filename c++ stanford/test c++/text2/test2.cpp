#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

static constexpr double BASE_SALARY = 4'000'000.0;
static constexpr double MIN_HE_SO = 1.5;
static constexpr double LUONG_2025_PC = 500'000.0;

class NhanVien
{
private:
	string m_maNV, m_hoTen, m_diaChi, m_phongBan;
	int m_namVaoCongTy = 0;
	double m_heSoLuong = 0.0;
	double m_phuCap = 0.0;

public:
	const string &maNV() const
	{
		return m_maNV;
	}

	const string &hoTen() const
	{
		return m_hoTen;
	}

	const string &diaChi() const
	{
		return m_diaChi;
	}

	const string &phongBan() const
	{
		return m_phongBan;
	}

	int namVaoCongTy() const
	{
		return m_namVaoCongTy;
	}

	double heSoLuong() const
	{
		return m_heSoLuong;
	}
	
	double phuCap() const
	{
		return m_phuCap;
	}

	double tongLuong() const
	{
		return BASE_SALARY * m_heSoLuong + m_phuCap;
	}

	void tangPhuCap(double amount)
	{
		m_phuCap += amount;
	}

	bool nhapThongTin()
	{
		cout << "  Ma nhan vien       : ";
		cin >> m_maNV;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "  Ho ten             : ";
		getline(cin, m_hoTen);
		cout << "  Dia chi            : ";
		getline(cin, m_diaChi);

		cout << "  Nam vao cong ty    : ";
		while (!(cin >> m_namVaoCongTy) || m_namVaoCongTy < 1900)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "  [!] Nhap lai nam (>= 1900): ";
		}

		cout << "  He so luong (>=1.5): ";
		while (!(cin >> m_heSoLuong) || m_heSoLuong < MIN_HE_SO)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "  [!] Nhap lai (>= 1.5): ";
		}

		cout << "  Phu cap (>= 0)     : ";
		while (!(cin >> m_phuCap) || m_phuCap < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "  [!] Nhap lai (>= 0): ";
		}

		const vector<string> validDepts = {"CNTT", "KT", "KD"};
		cout << "  Phong ban (CNTT/KT/KD): ";
		while (true)
		{
			cin >> m_phongBan;
			if (find(validDepts.begin(), validDepts.end(), m_phongBan) != validDepts.end())
				break;
			cout << "  [!] Nhap lai (CNTT, KT, KD): ";
		}

		return true;
	}
};

static void printHeader()
{
	cout << '\n'
		 << left
		 << setw(8) << "Ma NV"
		 << setw(22) << "Ho ten"
		 << setw(18) << "Dia chi"
		 << setw(6) << "Nam"
		 << setw(10) << "He so"
		 << setw(14) << "Phu cap"
		 << setw(16) << "Tong luong"
		 << setw(10) << "Phong ban"
		 << '\n'
		 << string(104, '-') << '\n';
}

static void printRow(const NhanVien &nv)
{
	cout << left
		 << setw(8) << nv.maNV()
		 << setw(22) << nv.hoTen()
		 << setw(18) << nv.diaChi()
		 << setw(6) << nv.namVaoCongTy()
		 << setw(10) << nv.heSoLuong()
		 << setw(14) << fixed << setprecision(0) << nv.phuCap()
		 << setw(16) << nv.tongLuong()
		 << setw(10) << nv.phongBan()
		 << '\n';
}

static void hienThiDanhSach(const vector<NhanVien> &ds, const string &title)
{
	cout << '\n'
		 << title << '\n';
	printHeader();
	for (const auto &nv : ds)
		printRow(nv);
}

static vector<NhanVien> sapXepGiamDan(vector<NhanVien> ds)
{
	sort(ds.begin(), ds.end(), [](const NhanVien &a, const NhanVien &b)
		 { return a.tongLuong() > b.tongLuong(); });
	return ds;
}

static void timLuongCaoThap(const vector<NhanVien> &ds)
{
	if (ds.empty())
		return;

	const NhanVien *maxNV = &ds[0];
	const NhanVien *minNV = &ds[0];
	for (const auto &nv : ds)
	{
		if (nv.tongLuong() > maxNV->tongLuong())
			maxNV = &nv;
		if (nv.tongLuong() < minNV->tongLuong())
			minNV = &nv;
	}

	cout << "\nNhan vien co tong luong CAO NHAT:\n";
	printHeader();
	printRow(*maxNV);

	cout << "\nNhan vien co tong luong THAP NHAT:\n";
	printHeader();
	printRow(*minNV);
}

static bool luuVaoFile(const vector<NhanVien> &ds, const string &tenFile)
{
	ofstream file("files/" + tenFile);
	if (!file)
	{
		cerr << "[!] Khong the mo file: " << tenFile << '\n';
		return false;
	}
	file << left
		 << setw(8) << "Ma NV"
		 << setw(22) << "Ho ten"
		 << setw(18) << "Dia chi"
		 << setw(6) << "Nam"
		 << setw(10) << "He so"
		 << setw(14) << "Phu cap"
		 << setw(16) << "Tong luong"
		 << setw(10) << "Phong ban"
		 << '\n'
		 << string(104, '-') << '\n';

	for (const auto &nv : ds)
	{
		file << left
			 << setw(8) << nv.maNV()
			 << setw(22) << nv.hoTen()
			 << setw(18) << nv.diaChi()
			 << setw(6) << nv.namVaoCongTy()
			 << setw(10) << nv.heSoLuong()
			 << setw(14) << fixed << setprecision(0) << nv.phuCap()
			 << setw(16) << nv.tongLuong()
			 << setw(10) << nv.phongBan()
			 << '\n';
	}
	cout << "[+] Da luu vao file: " << tenFile << '\n';
	return true;
}

int main(int argc, char const *argv[])
{
	vector<NhanVien> ds;
	constexpr int MAX_NV = 10;
	char tiepTuc;

	do
	{
		if (static_cast<int>(ds.size()) >= MAX_NV)
		{
			cout << "[!] Danh sach da day (" << MAX_NV << " nhan vien).\n";
			break;
		}
		cout << "\n=== Nhan vien thu " << (ds.size() + 1) << " ===\n";
		NhanVien nv;
		if (nv.nhapThongTin())
			ds.push_back(move(nv));

		cout << "Nhap tiep? (C/K): ";
		cin >> tiepTuc;
	} while (tiepTuc == 'C' || tiepTuc == 'c');

	if (ds.empty())
	{
		cout << "Khong co nhan vien nao duoc nhap.\n";
		return 0;
	}

	hienThiDanhSach(ds, "Danh sach nhan vien (theo thu tu nhap):");

	auto dsSorted = sapXepGiamDan(ds);
	hienThiDanhSach(dsSorted, "Danh sach nhan vien (theo tong luong giam dan):");

	timLuongCaoThap(ds);

	char luaChon;
	cout << "\nLuu danh sach vao file? (C/K): ";
	cin >> luaChon;
	if (luaChon == 'C' || luaChon == 'c')
	{
		luuVaoFile(dsSorted, "Luong2024.txt");

		for (auto &nv : ds)
			nv.tangPhuCap(LUONG_2025_PC);

		auto ds2025 = sapXepGiamDan(ds);
		hienThiDanhSach(ds2025, "Bang luong nam 2025 (sau khi tang phu cap):");
		luuVaoFile(ds2025, "Luong2025.txt");
	}

	return 0;
}

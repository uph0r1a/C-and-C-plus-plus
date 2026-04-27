#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool docFile(const string &duongDan)
{
	ifstream f(duongDan);
	if (!f.is_open())
	{
		cerr << "[Loi] Khong mo duoc file de doc: " << duongDan << "\n";
		return false;
	}

	cout << "=== NOI DUNG FILE: " << duongDan << " ===\n";
	string dong;
	int soDong = 0;
	while (getline(f, dong))
	{
		cout << "  " << ++soDong << " | " << dong << "\n";
	}
	if (soDong == 0)
		cout << "  (File rong)\n";
	cout << "=== " << soDong << " DONG ===\n";

	f.close();
	return true;
}

bool ghiFile(const string &duongDan, const string &noiDung, ios::openmode mode = ios::app)
{
	ofstream f(duongDan, mode);
	if (!f.is_open())
	{
		cerr << "[Loi] Khong mo duoc file de ghi: " << duongDan << "\n";
		return false;
	}

	f << noiDung;
	if (!f)
	{
		cerr << "[Loi] Xay ra loi khi ghi du lieu.\n";
		f.close();
		return false;
	}

	f.close();
	cout << "[OK] Ghi thanh cong vao: " << duongDan << "\n";
	return true;
}

bool kiemTraFile(const string &duongDan)
{
	ifstream f(duongDan);
	return f.good();
}

int demSoDong(const string &duongDan)
{
	ifstream f(duongDan);
	if (!f.is_open())
		return -1;
	int count = 0;
	string dong;
	while (getline(f, dong))
		count++;
	return count;
}

void timKiemTrongFile(const string &duongDan, const string &tuKhoa)
{
	ifstream f(duongDan);
	if (!f.is_open())
	{
		cerr << "[Loi] Khong mo duoc file: " << duongDan << "\n";
		return;
	}

	cout << "=== TIM KIEM \"" << tuKhoa << "\" TRONG " << duongDan << " ===\n";
	string dong;
	int soDong = 0, soKetQua = 0;
	while (getline(f, dong))
	{
		soDong++;
		if (dong.find(tuKhoa) != string::npos)
		{
			cout << "  Dong " << soDong << ": " << dong << "\n";
			soKetQua++;
		}
	}
	cout << "Tim thay " << soKetQua << " ket qua.\n";
	f.close();
}

int main(int argc, char const *argv[])
{
	const string FILE_PATH = "/storage/Coding/C-and-C-plus-plus/c++ stanford/stanford work/inclass c++/Day 6/files/dulieu.txt";

	ghiFile(FILE_PATH,
			"Lam viec voi lap trinh huong doi tuong C++\n"
			"Stanford - Day kinh nghiem lap trinh\n"
			"Bai hoc: File I/O trong C++\n",
			ios::out);

	docFile(FILE_PATH);

	ghiFile(FILE_PATH, "Dong them moi: C++ rat thu vi!\n", ios::app);

	docFile(FILE_PATH);

	int soDong = demSoDong(FILE_PATH);
	if (soDong >= 0)
		cout << "File co " << soDong << " dong.\n";

	timKiemTrongFile(FILE_PATH, "C++");

	cout << "File \"" << FILE_PATH << "\": "
		 << (kiemTraFile(FILE_PATH) ? "TON TAI" : "KHONG TON TAI") << "\n";
	cout << "File \"khongco.txt\": "
		 << (kiemTraFile("khongco.txt") ? "TON TAI" : "KHONG TON TAI") << "\n";

	return 0;
}
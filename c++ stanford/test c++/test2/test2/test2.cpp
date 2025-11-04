#include <iostream>
#include "NhanVien.h"
#include <string.h>
#include <iomanip>
using namespace std;

void hienThiThongTin(NhanVien nv) {
	cout << left << setw(10) << nv.maNV << setw(25) << nv.hoTen << setw(15) << nv.diaChi << setw(10) << nv.heSoLuong << setw(15) << fixed << setprecision(0) << nv.phuCap << setw(10) << nv.phongBan << endl;
}

void hienThiDanhSach1(NhanVien ds[], int n) {
	cout << left << setw(10) << "Ma NV" << setw(25) << "Ho ten" << setw(15) << "Dia chi" << setw(10) << "He so luong" << setw(15) << "Phu cap (VND)" << setw(10) << "Phong ban" << endl;

	for (int i = 0; i < n; i++) {
		hienThiThongTin(ds[i]);
	}
}

void sapXepNhanVien(NhanVien ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ds[i].tinhTongLuong() < ds[j].tinhTongLuong()) {
				swap(ds[i], ds[j]);
			}
		}
	}
}

void hienThiDanhSach2(NhanVien ds[], int n) {
	sapXepNhanVien(ds, n);
	cout << "\nDanh sach nhan vien theo tong luong giam dan:\n";
	for (int i = 0; i < n; i++) {
		cout << ds[i].maNV << " - " << ds[i].hoTen << " - " << ds[i].diaChi << " - " << " nam - " << ds[i].heSoLuong << " - " << ds[i].phuCap << " - " << ds[i].tinhTongLuong() << " - " << ds[i].phongBan << endl;
	}
}

void timKiemLuongCaoNhatThapNhat(NhanVien ds[], int n) {
	NhanVien maxNV = ds[0], minNV = ds[0];
	for (int i = 1; i < n; i++) {
		if (ds[i].tinhTongLuong() > maxNV.tinhTongLuong()) maxNV = ds[i];
		if (ds[i].tinhTongLuong() < minNV.tinhTongLuong()) minNV = ds[i];
	}
	cout << "\nNhan vien co tong luong cao nhat:\n";
	cout << maxNV.maNV << " - " << maxNV.hoTen << " - " << maxNV.tinhTongLuong() << endl;

	cout << "\nNhan vien co tong luong thap nhat:\n";
	cout << minNV.maNV << " - " << minNV.hoTen << " - " << minNV.tinhTongLuong() << endl;
}

void capNhatLuong2025(NhanVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		ds[i].phuCap += 500000;
	}
	sapXepNhanVien(ds, n);
	cout << "\nBang luong nam 2025:\n";
	hienThiDanhSach2(ds, n);
}

void luuVaoFile(NhanVien ds[], int n, const string& tenFile) {
	ofstream file(tenFile);
	for (int i = 0; i < n; i++) {
		file << ds[i].maNV << " - " << ds[i].hoTen << " - " << ds[i].heSoLuong << " - " << ds[i].phuCap << " - " << ds[i].tinhTongLuong() << " - " << ds[i].phongBan << endl;
	}
	file.close();
	cout << "Da luu danh sach vao file " << tenFile << endl;
}

void xuLyLuuFile(NhanVien ds[], int n) {
	int luaChon;
	cout << "\nBan co muon luu danh sach vao file? (1: Co, 0: Khong): ";
	cin >> luaChon;
	if (luaChon == 1) {
		luuVaoFile(ds, n, "Luong2024.txt");
		capNhatLuong2025(ds, n);
		luuVaoFile(ds, n, "Luong2025.txt");
	}
}

int main() {
	NhanVien ds[10];
	int n = 0;
	char tiepTuc;

	do {
		if (n >= 10) {
			cout << "Danh sach da day!" << endl;
			break;
		}

		cout << "\nNhap thong tin nhan vien thu " << (n + 1) << ":" << endl;
		if (ds[n].NhapThongTinNhanVien()) {
			n++;
		}

		cout << "Ban co muon nhap tiep? (C/K): ";
		cin >> tiepTuc;
	} while (tiepTuc == 'C' || tiepTuc == 'c');

	hienThiDanhSach1(ds, n);
	hienThiDanhSach2(ds, n);
	timKiemLuongCaoNhatThapNhat(ds, n);
	capNhatLuong2025(ds, n);
	xuLyLuuFile(ds, n);
}
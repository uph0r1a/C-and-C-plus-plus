#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
class NhanVien
{
private:
	double a[6];
	int sonamxettangluong;
public:
	string MaNv = "";
	string HoTen = "";
	string DiaChi = "";
	int NamVao = 0;
	double HeSoLuong = 0;
	float PhuCap = 0;
	string PhongBan = "";
	int Tongluong()
	{
		return(4000000 * HeSoLuong + PhuCap);
	}



public:
	NhanVien(void);
	~NhanVien(void);
	void NhapDuLieu();
	void NhapDuLieu(NhanVien ds[], int n);
	void Nhapdanhsach(NhanVien arr[]);
	int  LayViTriCuaHeSoLuong(double hs);
	int  HeSoLuongMoi(double hs);
	int  NamVaoCongTy(double hs);
	void HienThi(NhanVien arr[], int n);
	void InDanhSachRaFile(NhanVien arr[], int n);
	void TimKiem(NhanVien arr[], int n);
	void Sapxep2025(NhanVien arr[], int n);
	void InBangLuongMoiNam2025(NhanVien arr[], int n);
};


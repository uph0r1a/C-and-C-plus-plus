#include "NhanVien.h"
NhanVien::NhanVien()
{
	sonamxettangluong = 2;
	//Gán các bậc lương
	a[0] = 1.5;
	a[1] = 2;
	a[2] = 2.8;
	a[3] = 3.2;
	a[4] = 4.0;
	a[5] = 5.0;

}


NhanVien::~NhanVien()
{
}

void NhanVien::NhapDuLieu()
{
	cout << "Nhap Ma Nhan Vien: ";
	getline(cin, MaNv);

	cout << "Nhap Ho Ten Nhan Vien: ";
	getline(cin, HoTen);

	cout << "Nhap Dia Chi Nhan Vien: ";
	getline(cin, DiaChi);
	cout << "Nhap Nam vao cong ty: ";
	cin >> NamVao;
nhaplaihsl:
	cout << "Nhap he so luong nhan vien: ";
	cin >> HeSoLuong;
	if ((HeSoLuong != 1.5) && (HeSoLuong != 2) && (HeSoLuong != 2.8) && (HeSoLuong != 3.2) && (HeSoLuong != 4.0) && (HeSoLuong != 5.0))
	{
		cout << "He So Luong Khong Hop Le" << endl;
		goto nhaplaihsl;
	}
nhappc:
	cout << "Nhap phu cap cua nhan vien: ";
	cin >> PhuCap;
	if (PhuCap < 0)
	{
		cout << "So lieu khong hop le" << endl;
		goto nhappc;
	}

	//Loại bỏ kí tự xuống dòng do lệnh cin
	cin.ignore(1);
	cout << "Nhap Phong Ban cua nhan Vien: ";
	getline(cin, PhongBan);
}

void NhanVien::NhapDuLieu(NhanVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
		ds[i].NhapDuLieu();

	}
}

void NhanVien::Nhapdanhsach(NhanVien arr[])
{
	arr[0].MaNv = "SF1000";
	arr[0].HoTen = "Tran Quoc Tuan";
	arr[0].DiaChi = "Ha Noi";
	arr[0].HeSoLuong = 2.0;
	arr[0].PhuCap = 300000;
	arr[0].PhongBan = "CNTT";


	arr[1].MaNv = "SF1001";
	arr[1].HoTen = "Nguyen Minh Son";
	arr[1].DiaChi = "Nam Dinh";
	arr[1].HeSoLuong = 3.2;
	arr[1].PhuCap = 500000;
	arr[1].PhongBan = "CNTT";

	arr[2].MaNv = "SF1002";
	arr[2].HoTen = "Cao Ba Cuong";
	arr[2].DiaChi = "Thai Binh";
	arr[2].HeSoLuong = 3.2;
	arr[2].PhuCap = 500000;
	arr[2].PhongBan = "KT";

	arr[3].MaNv = "SF1003";
	arr[3].HoTen = "Bui Minh Khue";
	arr[3].DiaChi = "Hai Duong";
	arr[3].HeSoLuong = 1.5;
	arr[3].PhuCap = 200000;
	arr[3].PhongBan = "CNTT";


	arr[4].MaNv = "SF1004";
	arr[4].HoTen = "Le Hai Ha";
	arr[4].DiaChi = "Ha Noi";
	arr[4].HeSoLuong = 2.8;
	arr[4].PhuCap = 400000;
	arr[4].PhongBan = "KT";


	arr[5].MaNv = "SF1005";
	arr[5].HoTen = "Dang Hai Nam";
	arr[5].DiaChi = "Thai Binh";
	arr[5].HeSoLuong = 1.5;
	arr[5].PhuCap = 200000;
	arr[5].PhongBan = "KD";


	arr[6].MaNv = "SF1006";
	arr[6].HoTen = "Vu Phuong Thao";
	arr[6].DiaChi = "Ha Nam";
	arr[6].HeSoLuong = 3.2;
	arr[6].PhuCap = 500000;
	arr[6].PhongBan = "KD";


	arr[7].MaNv = "SF1007";
	arr[7].HoTen = "Pham Thanh Tung";
	arr[7].DiaChi = "Hai Duong";
	arr[7].HeSoLuong = 4.0;
	arr[7].PhuCap = 1000000;
	arr[7].PhongBan = "CNTT";

	arr[8].MaNv = "SF1008";
	arr[8].HoTen = "Tran Duc Minh";
	arr[8].DiaChi = "Ha Nam";
	arr[8].HeSoLuong = 2.0;
	arr[8].PhuCap = 300000;
	arr[8].PhongBan = "CNTT";


	arr[9].MaNv = "SF1009";
	arr[9].HoTen = "Le Minh Huy";
	arr[9].DiaChi = "Hai Phong";
	arr[9].HeSoLuong = 2.0;
	arr[9].PhuCap = 300000;
	arr[9].PhongBan = "KD";
}

int NhanVien::LayViTriCuaHeSoLuong(double hs)
{
	int vitri = 0;

	for (int i = 0; i < 6; i++)
	{
		if (a[i] == hs)
		{
			vitri = i;
			break;
		}
	}

	return vitri;
}

int NhanVien::NamVaoCongTy(double hs)
{
	int dolech = 0;

	for (int i = 0; i < 6; i++)
	{
		if (a[i] == hs)
		{
			dolech = i + 1;
			break;
		}
	}

	return 2024 - (sonamxettangluong * dolech);

}

int NhanVien::HeSoLuongMoi(double hs)
{
	//Lấy vị trí của hệ số lương hiện tại
	int vitri = LayViTriCuaHeSoLuong(hs);

	return a[vitri + 1];//Trả về hệ số lương mới

}

void NhanVien::HienThi(NhanVien arr[], int n)
{
	NhanVien temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].Tongluong() < arr[j].Tongluong())
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	cout << setw(10) << "Ma Nhan Vien" << setw(20) << "Ho Ten\t" << setw(15) << "Dia Chi" << setw(10) << "Nam Vao Cong Ty" << setw(10) << "He So Luong" << setw(15) << "Phu Cap" << setw(15) << "Tong Luong" << setw(10) << "Phong Ban" << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i].NamVao = NamVaoCongTy(arr[i].HeSoLuong);

		cout << setw(10) << arr[i].MaNv << setw(20) << arr[i].HoTen << setw(15) << arr[i].DiaChi << setw(10) << arr[i].NamVao << setw(10) << arr[i].HeSoLuong << setw(15) << arr[i].PhuCap << setw(15) << arr[i].Tongluong() << setw(10) << arr[i].PhongBan << endl;
	}
}

void NhanVien::InDanhSachRaFile(NhanVien arr[], int n)
{
	int t;
	cout << "Ban co muon luu danh sach ra file khong ? Nhan phim 1 de in file: ";
	cin >> t;
	if (t == 1)
	{
		ofstream w("danhsach.txt");
		if (w.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				w << arr[i].MaNv << " \t " << arr[i].HoTen << " \t " << arr[i].DiaChi << " \t " << arr[i].NamVao << " \t " << arr[i].HeSoLuong << " \t " << arr[i].PhuCap << " \t " << arr[i].Tongluong() << " \t " << arr[i].PhongBan << "\n";
			}
			w.close();

			cout << endl << "Luu du lieu ra file thanh cong" << endl;
		}
	}

}
void NhanVien::TimKiem(NhanVien arr[], int n)
{
	NhanVien temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].Tongluong() < arr[j].Tongluong())
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	cout << "Nhan vien Co tong luong cao nhat la: " << endl;
	cout << left << setw(10) << "Ma NV" << setw(20) << "Ho Ten\t" << setw(15) << "Dia Chi" << setw(10) << "Nam Vao Cong Ty" << setw(10) << "He So Luong" << setw(15) << "Phu Cap" << setw(15) << "Tong Luong" << setw(10) << "Phong Ban" << endl;

	cout << left << setw(10) << arr[0].MaNv << setw(20) << arr[0].HoTen << setw(15) << arr[0].DiaChi << setw(10) << arr[0].NamVao << setw(10) << arr[0].HeSoLuong << setw(15) << arr[0].PhuCap << setw(15) << arr[0].Tongluong() << setw(10) << arr[0].PhongBan << endl;



	cout << endl << "Nhan vien co tong luong thap nhat la: " << endl;
	cout << left << setw(10) << "Ma NV" << setw(20) << "Ho Ten\t" << setw(15) << "Dia Chi" << setw(10) << "Nam Vao Cong Ty" << setw(10) << "He So Luong" << setw(15) << "Phu Cap" << setw(15) << "Tong Luong" << setw(10) << "Phong Ban" << endl;
	cout << left << setw(10) << arr[n - 1].MaNv << setw(20) << arr[n - 1].HoTen << setw(15) << arr[n - 1].DiaChi << setw(10) << arr[n - 1].NamVao << setw(10) << arr[n - 1].HeSoLuong << setw(15) << arr[n - 1].PhuCap << setw(15) << arr[n - 1].Tongluong() << setw(10) << arr[n - 1].PhongBan << endl;

}

void NhanVien::Sapxep2025(NhanVien arr[], int n)
{
	NhanVien temp;

	//Duyet de tinh lai he so luong
	for (int i = 0; i < n; i++)
	{
		arr[i].HeSoLuong = HeSoLuongMoi(arr[i].HeSoLuong);

	}

	cout << "Danh sach nhan vien thuoc phong CNTT:" << endl;

	for (int i = 0; i < n; i++) {

		if (arr[i].PhongBan == "CNTT")
		{
			cout << left << setw(10) << arr[i].MaNv << setw(20) << arr[i].HoTen << setw(15) << arr[i].DiaChi << setw(10) << arr[i].NamVao << setw(10) << arr[i].HeSoLuong << setw(15) << arr[i].PhuCap + 200000 << setw(15) << arr[i].Tongluong() << setw(10) << arr[i].PhongBan << endl;

		}
	}

	cout << "Danh sach nhan vien thuoc phong KD:" << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i].PhongBan == "KD")
		{
			cout << left << setw(10) << arr[i].MaNv << setw(20) << arr[i].HoTen << setw(15) << arr[i].DiaChi << setw(10) << arr[i].NamVao << setw(10) << arr[i].HeSoLuong << setw(15) << arr[i].PhuCap + 200000 << setw(15) << arr[i].Tongluong() << setw(10) << arr[i].PhongBan << endl;
		}
	}

	cout << "Danh sach nhan vien thuoc phong KT:" << endl;

	for (int i = 0; i < n; i++) {
		if (arr[i].PhongBan == "KT")
		{
			cout << left << setw(10) << arr[i].MaNv << setw(20) << arr[i].HoTen << setw(15) << arr[i].DiaChi << setw(10) << arr[i].NamVao << setw(10) << arr[i].HeSoLuong << setw(15) << arr[i].PhuCap + 200000 << setw(15) << arr[i].Tongluong() << setw(10) << arr[i].PhongBan << endl;

		}
	}

}

void NhanVien::InBangLuongMoiNam2025(NhanVien arr[], int n)
{
	int t;
	cout << "Ban co muon luu danh sach ra file khong? Nhan phim 1 de in file: ";
	cin >> t;
	if (t == 1)
	{
		ofstream w("bangluongmoinam2025.txt");
		if (w.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				w << arr[i].MaNv << " \t " << arr[i].HoTen << " \t " << arr[i].DiaChi << " \t " << arr[i].NamVao << " \t " << arr[i].HeSoLuong << " \t " << arr[i].PhuCap << " \t " << arr[i].Tongluong() << " \t " << arr[i].PhongBan << "\n";
			}
			w.close();

			cout << endl << "Luu du lieu ra file thanh cong" << endl;
		}
	}
}


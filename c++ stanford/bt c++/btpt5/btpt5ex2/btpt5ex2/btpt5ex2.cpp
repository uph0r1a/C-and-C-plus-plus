//Bài tập 2
//Cho một lớp cơ sở ConNguoi bao gồm các đặc tính sau : Màu mắt, màu da, chiều cao, cân
//nặng, tiếng nói.Hãy sử dụng kiến thức kế thừa và đa hình đã được học thực hiện các yêu
//cầu sau :
//✓ Lớp thông tin về NguoiChauA, NguoiChauAu kế thừa từ lớp cơ sở ở trên.Trong
// biết rằng :
//o Chiều cao trung bình của người châu á là 1.6 m và người châu âu là 1.75
//o Cân nặng trung bình của người châu á là 60 kg và người châu âu là 70 kg
//✓ Xây dựng lớp NguoiViet, NguoiNhat kế thừa từ những lớp tương ứng và phát triển
//thêm thông tin Tiếng nói và thông tin Tết nguyên đán.

#include <iostream>
#include "NguoiViet.h"
#include "NguoiNhat.h"
int main()
{
	//Khai báo đối tượng
	NguoiViet nam;

	//Gán giá trị cho các thuộc tính
	nam.mauMat = "Mau den";
	nam.mauDa = "Da vang";
	nam.chieuCao = 1.7;
	nam.canNang = 65;

	//In thông tin
	cout << "Thong tin cua Nam: " << endl;
	nam.inThongTin();
	if (nam.tetNguyenDan())
	{
		cout << "Tet nguyen dan: Co" << endl;
	}

	if (nam.chieuCao > nam.chieuCaoTrungBinh())
	{
		cout << "Chieu cao: Dat yeu cau" << endl;
	}
	else
	{
		cout << "Chieu cao: Khong dat yeu cau" << endl;
	}

	if (nam.canNang < 70 && nam.canNang >= nam.canNangTrungBinh())
	{
		cout << "Can nang: Dat yeu cau" << endl;
	}
	else
	{
		cout << "Can nang: Khong dat yeu cau" << endl;
	}
}
#include "ConNguoi.h"

string ConNguoi::tiengNoi()
{
	return "";
}

double ConNguoi::chieuCaoTrungBinh()
{
	return 0;
}

double ConNguoi::canNangTrungBinh()
{
	return 0;
}

void ConNguoi::inThongTin()
{
	cout << "Mau mat: " << this->mauMat << endl;
	cout << "Mau da: " << this->mauDa << endl;
	cout << "Chieu cao: " << this->chieuCao << endl;
	cout << "Can nang: " << this->canNang << endl;
	cout << "Tieng noi: " << this->tiengNoi() << endl;
}

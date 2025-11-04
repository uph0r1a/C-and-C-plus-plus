#include <iostream>
#include "Cat.h"
#include "Dog.h"

int main()
{
	//Khai báo đối tượng mèo tom
	Cat tom;

	//Gán giá trị cho các thuọc tính
	tom.SoMat = 2;
	tom.SoChan = 4;
	tom.MauLong = "Mau xam";

	//Gọi hàm in thong tin
	cout << "Thong tin cua meo Tom: " << endl;
	tom.InThongTin();

	cout << "Tieng keu: " << tom.TiengKeu() << endl;

	//Khai báo đối tượng chó minu
	Dog minu;

	//Gán giá trị cho cho các thuọc tính
	minu.SoMat = 2;
	minu.SoChan = 4;
	minu.MauLong = "Mau den";

	cout << "Thong tin cho Minu: " << endl;
	minu.InThongTin();
	cout << "Tieng keu: " << minu.TiengKeu() << endl;
}
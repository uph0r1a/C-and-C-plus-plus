#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Doc thong tin cua file: " << endl;

	string dong;
	ifstream myfile("D:\\coding\\c and c++\\inclass c++\\inclasspt6\\inclasspt6.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, dong))
		{
			cout << dong << endl;
		}
		myfile.close();
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
	}

	cout << "Ghi du lieu ra file: " << endl;

	ofstream writer("D:\\coding\\c and c++\\inclass c++\\inclasspt6\\inclasspt6.txt", ios::app);

	if (writer.is_open())
	{
		writer << "Lam viec vs lap trinh doi tuong C++" << endl;
		writer << "Standford" << endl;

		writer.close();
		cout << "Ghi du lieu ra file thanh cong" << endl;
	}
	else
	{
		cout << "Khong tim thay file can ghi" << endl;
	}
}

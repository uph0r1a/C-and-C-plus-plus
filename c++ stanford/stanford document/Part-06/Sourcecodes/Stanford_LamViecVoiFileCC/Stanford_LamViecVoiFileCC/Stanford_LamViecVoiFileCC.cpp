// Stanford_LamViecVoiFileCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    cout << "Doc thong tin tu file: " << endl;
    /*string dong;

    ifstream myfile("C:\\Stanford\\Data\\cc1124.txt");

    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, dong);
            cout << dong << endl;
        }

        //Đóng luồng
        myfile.close();
    }
    else
    {
        cout << "Khong mo duoc file can doc" << endl;
    }*/

    //Vi du 2:
    string dong;

    ifstream myfile("C:\\Stanford\\Data\\HinhChuNhat.cpp", ios::binary);

    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, dong);
            cout << dong << endl;
        }

        //Đóng luồng
        myfile.close();
    }
    else
    {
        cout << "Khong mo duoc file can doc" << endl;
    }

    cout << "Ghi du lieu ra file: " << endl;

    ofstream writer("C:\\Stanford\\Data\\cc1124_2.txt", ios::app);

    if (writer.is_open())
    {
        writer << "Lam viec voi Lap trinh huong doi tuong C++"<<endl;
        writer << "Stanford - Day kinh nghiem lap trinh"<<endl;

        //Đóng luồng
        writer.close();
        cout << "Ghi du lieu ra file thanh cong" << endl;
    }
    else
    {
        cout << "Khong tim thay file can ghi" << endl;
    }


}


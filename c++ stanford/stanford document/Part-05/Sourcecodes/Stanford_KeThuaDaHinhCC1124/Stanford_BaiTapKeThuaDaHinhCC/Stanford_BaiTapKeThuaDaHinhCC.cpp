// Stanford_BaiTapKeThuaDaHinhCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


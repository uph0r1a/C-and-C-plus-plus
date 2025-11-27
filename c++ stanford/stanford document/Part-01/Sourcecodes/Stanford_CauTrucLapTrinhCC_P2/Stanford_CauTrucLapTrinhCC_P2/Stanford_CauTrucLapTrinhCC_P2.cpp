// Stanford_CauTrucLapTrinhCC_P2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    //Bài tập 10: In ra tổng, tích, hiệu và thương của 2 số được nhập vào từ bàn phím.
    //Khai báo biến
    char phepTinh;
    double soa = 0, sob = 0, ketQua = 0;

    cout << "Nhap so a = ";
    cin >> soa;

    cout << "Nhap so b = ";
    cin >> sob;

    //Xóa kí tự thừa
    cin.ignore(1);
    cout << "Nhap phep tinh (+, -, *, /): ";
    cin.get(phepTinh);

    //Sử dụng switch case
    switch (phepTinh)
    {
        case '+': ketQua = soa + sob;
            break;
        case '-': ketQua = soa - sob;
            break;
        case '*': ketQua = soa * sob;
            break;
        case '/':
            if (sob != 0)
            {
                ketQua = soa / sob;
            }
            else
            {
                cout << "Ban can phai nhap so b khac 0";
                return 0;
            }
            break;
    }

    //In kết quả
    cout << "Ket qua thuc hien " << soa << phepTinh << sob << " la: " << ketQua << endl;

    //Dừng màn hình đến khi nhấn phím tiếp theo
    system("pause");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Stanford_BaiTapKieuDLNangCaoCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>

int main()
{
    /*
    //Bài tập 1: Hãy khai báo biến kí tự ch và con trỏ kiểu kí tự pc trỏ vào biến ch.Viết ra các cách gán giá trị ‘A’ cho biến ch.
    char ch;

    cout << "Nhap ki tu = ";
    cin.get(ch);

    cout << "Ki tu la: " << ch << endl;
    char* pc;

    pc = &ch;

    *pc = 'A';

    cout << "Dia chi luu trong con tro pc la: " << (void*)pc << endl;
    cout << "Gia tri lay qua con tro pc la: " << *pc << endl;
    cout << "Ki tu la: " << ch << endl;

   //Bài tập 2 : Cho mảng nguyên cost.Viết ra các cách gán giá trị 100 cho phần tử thứ 3 của mảng.
    const int MAX = 3;

    int cost[MAX];

    cost[2] = 100;

    int* p2;
    //Trỏ đến phần tử thứ 3
    p2 = &cost[2];

    cout << "Gia tri phan tu thu 3 la: " << cost[2] << endl;
    *p2 = 200;

    cout << "Gia tri cua phan tu thu 3 sau khi thay doi gia tri qua con tro p2: " << cost[2] << endl;
    */
   //Bài tập 3 : Cho xâu kí tự(dạng con trỏ) s.Hãy in ngược xâu ra màn hình.

    string strChuoi;

    cout << "Nhap vao 1 chuoi: ";
    getline(cin, strChuoi);

    string* p;

    p = &strChuoi;

    cout << "Chuoi la: " << *p << endl;

    cout << "Chuoi nguoc la: " << endl;
    for (int i = strChuoi.length()-1; i >= 0; i--)
    {
        cout << strChuoi[i];
    }

    char s[10];

    strcpy_s(s, "Stanford");

    char* p2;
    p2 = &s[7];

    cout <<endl<< "Chuoi dao nguoc 2: " << endl;
    for (int i = 7; i >= 0; i--)
    {
        cout << *p2;
        p2--;
    }
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

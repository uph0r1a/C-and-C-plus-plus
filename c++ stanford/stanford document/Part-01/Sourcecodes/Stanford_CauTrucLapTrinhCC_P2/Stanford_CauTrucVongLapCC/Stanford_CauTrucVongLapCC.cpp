// Stanford_CauTrucVongLapCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    //Khai báo biến
    int i = 1;
    cout << "Su dung vong lap while: " << endl;

    while (i < 10)//true
    {
        cout << "Hom nay troi dep qua - " << i << endl;
        i++;
    }

    cout << "Su dung vong lap do while: " << endl;
    do
    {
        cout << "Gia tri cua i = " << i << endl;
        i++;
    } while (i <= 20);

    //In 1 dãy số chẵn từ 80 đến 90
    cout << "Su dung vong lap for: " << endl;

    cout << "Cac so chan tu 80 - 90 la: " << endl;
    for (int j = 80; j <= 90; j += 2)//j = j + 2
    {
        cout << j << "\t";
    }

    cout << endl;
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

// Stanford_GameRanSanMoiCC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "GameRanSanMoi.h"

int main()
{
    /*
    //In chữ ra vị trí bất kỳ trên màn hình
    char s[50];
    strcpy_s(s, "stanford.com.vn");

    while (true) {
        gotoxy(rand() % 120, rand() % 30);

        cout << s;

        Sleep(1000);

        system("cls");
    }*/

    //Khai báo đối tượng
    GameRanSanMoi game;

    //Gọi hàm
    game.Play();
}


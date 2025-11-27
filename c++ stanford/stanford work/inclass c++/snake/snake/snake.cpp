#include <iostream>
#include "GameSnake.h"
using namespace std;

int main()
{
	/*char s[50];
	strcpy_s(s, "stanford.con.vn");

	while (true)
	{
		gotoxy(rand() % 120, rand() % 30);
		cout << s;
		Sleep(1000);
		system("cls");
	}*/

	//Khai báo đối tượng
	GameSnake game;

	//Gọi hàm
	game.Play();
}
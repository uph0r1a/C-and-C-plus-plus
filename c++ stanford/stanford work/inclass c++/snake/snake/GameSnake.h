#pragma once
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <string>
using namespace std;
class GameSnake
{
private:
	//Thiết lập kích thước của giao diện con rắn
	const int WIDTH = 30;
	const int HEIGHT = 20;
	//Khai báo trạng thái di chuyển của con rắn
	enum TrangThai
	{
		LEFT = 0,
		RIGHT = 1,
		UP = 2,
		DOWN = 3
	};
	//Khai báo tọa độ
	struct ToaDo
	{
		int x, y;
	};
	struct HoaQua
	{
		int x, y;
	};
	//Định nghĩa con rắn
	static const int MAX = 30;
	struct Snake
	{
		ToaDo dot[MAX];
		int n;
		TrangThai status;
	};
	//Khai báo con rắn
	Snake snake;
	HoaQua fruit;
	bool gameOver = false;
	void gotoxy(int x, int y);
public:
	void ThietLapGame();
	void VeManHinhChoi();
	void DieuKhien();
	void XuLyLogic();
	void Play();
};
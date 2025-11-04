#include "GameSnake.h"
void GameSnake::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}
void GameSnake::ThietLapGame()
{
	gameOver = false;
	//Khai báo trạng thái và thông số ban đầu của con rắn
	snake.n = 1;
	snake.dot[0].x = 10;
	snake.dot[0].y = 10;
	//Vị trí con mồi
	fruit.x = 15;
	fruit.y = 15;
}
void GameSnake::VeManHinhChoi()
{
	//Xóa dữ liệu màn hình đi nếu có
	system("cls");
	//Vẽ đường ngang đầu tiên
	for (int i = 0; i < WIDTH; i++)
	{
		cout << "*";
	}
	cout << endl;
	//Vẽ 2 cột
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0 || j == WIDTH - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	//Vẽ đường ngang thứ 2
	for (int i = 0; i < WIDTH; i++)
	{
		cout << "*";
	}
	cout << endl;
	//Vẽ rắn
	for (int i = 0; i < snake.n; i++)
	{
		//Di chuyển vị trí con rắn cần vẽ
		gotoxy(snake.dot[i].x, snake.dot[i].y);
		if (i == 0)
		{
			putchar('0');
		}
		else
		{
			putchar('o');
		}
	}
	//Vẽ mồi
	gotoxy(fruit.x, fruit.y);
	putchar('F');
}
void GameSnake::DieuKhien()
{
	//Xóa vị trí cũ của con rắn
	for (int i = 0; i < snake.n; i++)
	{
		gotoxy(snake.dot[i].x, snake.dot[i].y);
		putchar(' ');
	}
	//Cập nhật di chuyển thân theo đầu rắn
	for (int i = snake.n - 1; i > 0; i--)
	{
		snake.dot[i] = snake.dot[i - 1];
	}
	//Kiểm tra xem có nhấn phím hay không
	if (_kbhit())
	{
		//Thay đổi hướng di chuyển của con rắn
		switch ((int)_getch())
		{
		case 75: snake.status = LEFT;
			break;
		case 76: snake.status = RIGHT;
			break;
		case 72: snake.status = UP;
			break;
		case 80: snake.status = DOWN;
			break;
		default:
			snake.status = RIGHT;
			break;
		}
	}
}
void GameSnake::XuLyLogic()
{
	//Di chuyển rắn theo hướng
	switch (snake.status)
	{
	case LEFT: snake.dot[0].x--;
		break;
	case RIGHT: snake.dot[0].x++;
		break;
	case UP: snake.dot[0].y--;
		break;
	case DOWN: snake.dot[0].y++;
		break;
	default:
		break;
	}
	//Vẽ rắn
	for (int i = 0; i < snake.n; i++)
	{
		//Di chuyển vị trí con rắn cần vẽ
		gotoxy(snake.dot[i].x, snake.dot[i].y);
		if (i == 0)
		{
			putchar('0');
		}
		else
		{
			putchar('o');
		}
	}

	//Nếu rắn cắn mồi
	if (snake.dot[0].x == fruit.x && snake.dot[0].y == fruit.y)
	{
		//Thêm đốt 
		snake.n++;
		//Hiển thị vị trí con mồi mới
		fruit.x = rand() % (WIDTH - 1);
		fruit.y = rand() % (HEIGHT - 1);

		//Nếu chạm thành
		if (fruit.x == 0)
		{
			fruit.x = 3;
		}
		if (fruit.x == WIDTH)
		{
			fruit.x = WIDTH - 3;
		}
		if (fruit.y == 0)
		{
			fruit.y = 3;
		}
		if (fruit.y == HEIGHT)
		{
			fruit.y = HEIGHT - 3;
		}

		//Vẽ con mồi ở vị trí mới 
		gotoxy(fruit.x, fruit.y);
		putchar('F');
	}//end if

	//Xử lý khi rắn chạm thành thì game kết thúc
	if (snake.dot[0].x == 0 || snake.dot[0].x == WIDTH || snake.dot[0].y == 0 || snake.dot[0].y == HEIGHT)
	{
		gameOver = true;
		gotoxy(WIDTH / 3, HEIGHT / 2);
		cout << "GAME OVER !";
	}
}
void GameSnake::Play()
{
	//Thiết lập thông số ban đầu
	ThietLapGame();
	VeManHinhChoi();
	while (!gameOver)
	{
		DieuKhien();
		XuLyLogic();
		Sleep(500);
	}
}
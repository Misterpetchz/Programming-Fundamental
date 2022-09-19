#include <stdio.h>
#include <windows.h>
#include <conio.h>
int _kbhit();
int _getch();

void gotoxy(int x, int y)
{
	COORD c = { x ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

//set color
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

//draw_ship
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
	setcolor(7, 0);
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
}

//bullet
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	printf("^");
}

//clear_bullet
void clear_bullet(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

int main()
{
	char ch = ' ';
	int x = 38, y = 20, bullet = 0, ammo = 5;
	int	bx ,by ,move = 0;
	setcursor(0);
	draw_ship(x, y);
	

	do
	{
		if (_kbhit())
		{
			ch = _getch();
			
			if (ch == 'a')
			{
				move = 1;
			}
			if (ch == 'd')
			{
				move = 2;
			}
			if (ch == 's')
			{
				move = 3;
			}
			if (ch == ' ' && bullet != 1 && ammo > 0)
			{
				bullet = 1;
				bx = x + 3;
				by = y - 1;

			}
			fflush(stdin);
		}
		//check move
		if (move != 0)
		{
			if (move == 1 && x > 0)
			{
				erase_ship(x, y);
				draw_ship(--x, y);
			}
			if (move == 2 && x < 73)
			{
				erase_ship(x, y);
				draw_ship(++x, y);
			}
			if (move == 3)
			{
				draw_ship(x, y);
			}
		}

		//shoot
		if (bullet == 1)
		{
			clear_bullet(bx, by);
			if (by == 2)
			{
				bullet = 0;
				ammo -= 1;
			}
			else
			{
				draw_bullet(bx, --by);
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
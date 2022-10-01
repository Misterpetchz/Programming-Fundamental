#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

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

void bullet_shoot(int x, int y)
{
	if (y > 0)
	{
		clear_bullet(x, y);
		draw_bullet(x, --y);
	}
	else
		clear_bullet(x, y);
}

void draw_star(int x, int y)
{
	gotoxy(x, y);
	printf("*");
}

int Random1()
{
	int min1 = 10;
	int max1 = 70;
	int num = (rand() % (max1 - min1 + 1)) + min1;
	return num;
}

int Random2()
{
	int min2 = 2;
	int max2 = 5;
	int num = (rand() % (max2 - min2 + 1)) + min2;
	return num;
}

void draw_point()
{
	gotoxy(67, 0);
	printf(" ");
}
char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x ,y }; DWORD num_read;
	if (
	!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}

int main()
{
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		draw_star(Random1(), Random2());
	}
	char ch = ' ';
	int x = 38, y = 20, st_bull[5];
	int	bx[5], by[5], move = 0, i = 0;
	int point = 0;
	setcursor(0);
	draw_ship(x, y);
	

	do
	{
		draw_point();
		printf("Points : %d", point);
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
			if (ch == ' ' && i < 5)
			{
				
				bx[i] = x + 3;
				by[i] = y - 1;
				st_bull[i] = 1;
				i++;
			}
			else if (i <= 5 && st_bull[i - 1] == 0)
			{
				i = 0;
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
		for (int j = 0; j < i; j++)
		{
			if (cursor(bx[j], by[j] - 1) == '*')
			{
				clear_bullet(bx[j], by[j] - 1);
				clear_bullet(bx[j], by[j]);
				st_bull[j] = 0;
				draw_star(Random1(), Random2());
				bx[j] = 0, by[j] = 0;
				point++;
				draw_point();
				printf("Points : %d", point);
				Beep(500, 100);
			}
			if (st_bull[j] == 1)
			{
				bullet_shoot(bx[j], by[j]--);
				if (by[j] < 0)
				{
					st_bull[j] = 0;
					clear_bullet(bx[j], by[j]);
				}
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
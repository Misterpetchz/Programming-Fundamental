#include <stdio.h>
#include <windows.h>
#include <conio.h>
int _kbhit();
int _getch();

void draw_ship(int x ,int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("       ");
}

int main()
{
	char ch = ' ';
	int x = 57, y = 30;
	draw_ship(x, y);
	
	do 
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' && x != 0)
			{
				draw_ship(--x, y);
			}
			if (ch == 'd' && x != 0)
			{
				draw_ship(++x, y);
			}
			if (ch == 'w' && x != 0)
			{
				erase_ship(x, y);
				draw_ship(x, --y);
				
			}
			if (ch == 's' && x != 0)
			{
				erase_ship(x, y);
				draw_ship(x, ++y);
				
			}

			fflush(stdin);
		}
		Sleep(50);
	} 
	while (ch != 'x');
	return 0;
}
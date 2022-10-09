#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define scount 40
#define screen_x 80
#define screen_y 25

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
int life = 10;
int rand_color = 7;

struct Ship
{
	int x;
	int y;
};
struct Ship ship;

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

void clear_buffer()
{
	for (int y = 0; y < screen_y; y++)
	{
		for (int x = 0; x < screen_x; x++)
		{
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = rand_color;
		}
	}
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void init_star()
{
	int x, y;
	for (int i = 0; i < scount; i++)
	{
		x = rand() % screen_x;
		y = rand() % screen_y;
		star[i].X = x, star[i].Y = y;
	}
}

void star_fall()
{
	for (int i = 0; i < scount; i++)
	{
		if (star[i].Y >= screen_y - 1)
		{
			star[i].X = rand() % screen_x;
			star[i].Y = 1;
		}
		else
			star[i].Y = star[i].Y + 1;
	}
}

void fill_star_to_buffer()
{
	for (int i = 0; i <= scount; i++)
	{
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = rand_color;
	}
}

void draw_ship()
{
	consoleBuffer[ship.x + screen_x * ship.y].Char.AsciiChar = '<';
	consoleBuffer[ship.x + 1 + screen_x * ship.y].Char.AsciiChar = '-';
	consoleBuffer[ship.x + 2 + screen_x * ship.y].Char.AsciiChar = '0';
	consoleBuffer[ship.x + 3 + screen_x * ship.y].Char.AsciiChar = '-';
	consoleBuffer[ship.x + 4 + screen_x * ship.y].Char.AsciiChar = '>';
	consoleBuffer[ship.x + screen_x * ship.y].Attributes = rand_color;
	consoleBuffer[ship.x + 1 + screen_x * ship.y].Attributes = rand_color;
	consoleBuffer[ship.x + 2 + screen_x * ship.y].Attributes = rand_color;
	consoleBuffer[ship.x + 3 + screen_x * ship.y].Attributes = rand_color;
	consoleBuffer[ship.x + 4 + screen_x * ship.y].Attributes = rand_color;
}

void collision()
{
	for (int i = 0; i < scount; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (star[i].X == ship.x + j && star[i].Y == ship.y)
			{
				star[i].X = rand() % screen_x;
				star[i].Y = 1;
				life--;
				break;
			}
		}
	}
}


int main()
{
	bool play = true;
	char ch = ' ';
	srand(time(NULL));
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	setConsole(screen_x, screen_y);
	setMode();
	init_star();
	while (play)
	{
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0)
		{
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i)
			{
				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true)
				{
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
					{
						play = false;
					}
					if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
					{
						rand_color = rand() % 255;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT)
				{
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						rand_color = rand() % 255;
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED && posx > 2 && posx < screen_x - 2)
					{
						ship.x = posx - 2;
						ship.y = posy;
					}
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		clear_buffer();
		draw_ship();
		collision();
		fill_star_to_buffer();
		fill_buffer_to_console();
		if (life == 0)
		{
			play = false;
		}
		Sleep(100);
	}
	return 0;
}
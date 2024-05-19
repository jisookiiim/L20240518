#include <iostream>
#include <conio.h>

using namespace std;

	int PlayerX;
	int PlayerY;
	char PlayerShape = 'P';

	int MonsterX = 5;
	int MonsterY = 5;
	char MonsterShape = 'M';

	int GoalX = 8;
	int GoalY = 8;
	char GoalShape = 'G';

	char FloorShape = ' ';
	char WallShape = '*';

	int Key = 0;

	int World[10][10] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	
	bool IsRunning = true; 

	void Input()
	{
		Key = _getch();
	}

	void Tick()
	{
		if (Key == 'w')
		{
			PlayerY--;
		}
		if (Key == 's')
		{
			PlayerY++;
		}
		if (Key == 'a')
		{
			PlayerX--;
		}
		if (Key == 'd')
		{
			PlayerX++;
		}
		if (Key == 'u')
		{
			MonsterY--;
		}
		if (Key == 'j')
		{
			MonsterY++;
		}
		if (Key == 'h')
		{
			MonsterX--;
		}
		if (Key == 'k')
		{
			MonsterX++;
		}
		if (Key == 27)
		{
			IsRunning = false;
		}
	}

	void Render()
	{
		system("cls");

		for (int Y = 0; Y < 10; Y++)
		{
			for (int X = 0; X < 10; X++)
			{
				if (PlayerX == X && PlayerY == Y)
				{
					cout << PlayerShape;
				}
				else if (GoalX == X && GoalY == Y)
				{
					cout << GoalShape;
				}
				else if (MonsterX == X && MonsterY == Y)
				{
					cout << MonsterShape;
				}
				else if (World[Y][X] == 0)
				{
					cout << FloorShape;
				}
				else if (World[Y][X] == 1)
				{
					cout << WallShape;
				}
				
			}
			cout << endl;

		}
	}

	int main()
	{
		while (IsRunning)
		{
			Input();

			Tick();

			Render();
		}
	
		return 0;
}


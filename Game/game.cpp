#include "game.h"



bool game::chekPosition(COORD coordTank, eDiretion dir)
{
	char** map = area.getMapArea();
	switch (dir)
	{
	case UP:
		coordTank.Y--;
		break;
	case DOWN:
		coordTank.Y++;
		break;
	case LEFT:
		coordTank.X--;
		break;
	case RIGHT:
		coordTank.X++;
		break;
	}
	if (map[coordTank.Y][coordTank.X] == '#')
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

void game::setStartPositionPlayer()
{
	int X = MAPSIZE / 2;
	int Y = MAPSIZE - 2;
	char** map = area.getMapArea();
	while ((map[X][Y] == '#'))
	{
		X++;
		if (X >= MAPSIZE)
		{
			Y--;
			X = MAPSIZE / 2;
		}
	} 
	tankPlayer.setCoord(X, Y);
}

void game::setStartPositionEnemy()
{
		int X = MAPSIZE / 2;
		int Y = 1;
		
	char** map = area.getMapArea();
	while ((map[X][Y] == '#'))
	{
		X++;
		if (X >= MAPSIZE)
		{
			Y++;
			X = MAPSIZE / 2;
		}
	}
	tankEnemy.setCoord(X, Y);
}
game::game()
	:area()
	, tankPlayer()
	, gameOver(false)
	, dir(UP)
{
	area.showMap();
}
eDiretion game::getRouteToTankPlayer()
{
	COORD player= tankPlayer.getCoord();
	COORD enemy = tankEnemy.getCoord();
	Sleep(300);
	if ((player.X < enemy.X) && chekPosition(enemy, LEFT))
	{
		return LEFT;
	}
	else if ((player.X > enemy.X) && chekPosition(enemy, RIGHT))
	{
		return RIGHT;
	}
	else if ((player.Y > enemy.Y) && chekPosition(enemy, DOWN))
	{
		return DOWN;
	}
	else if ((player.Y < enemy.Y) && chekPosition(enemy, UP))
	{
		return UP;
	}
	else if ((player.Y == enemy.Y) && (player.X == enemy.X))
	{
		gameOver = true;
		return GAMEOVER;
	}


}

void game::gaming()
{
	setStartPositionPlayer();
	setStartPositionEnemy();
	tankEnemy.show();
	tankPlayer.show();
	do
	{

		tankEnemy.move(getRouteToTankPlayer());
		if (inputKey())
		{
			if (chekPosition(tankPlayer.getCoord(), dir))
			{
				tankPlayer.move(dir);
				
				//Sleep(500);
			}
		}
		
	} while (!gameOver);
}

bool game::inputKey() 
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			return true;
			break;
		case 'd':
			dir = RIGHT;
			return true;
			break;
		case 'w':
			dir = UP;
			return true;
			break;
		case 's':
			dir = DOWN;
			return true;
			break;
		case ' ':
			showBull(dir);
			return true;
			break;
		}
		return false;
	}

}

void game::showBull(eDiretion dir)
{
	bull.setCoordBullet(tankPlayer.getCoord(), dir);
	COORD test;
	char** map = area.getMapArea();
	test = bull.getCoordBullet();
	if (test.X < MAPSIZE - 1 && test.Y < MAPSIZE - 1 && map[test.Y][test.X] != '#')
	{
		bull.show();
		while (chekPosition(bull.getCoordBullet(), dir))
		{
			bull.move(dir);
			Sleep(100);
		}
		SetConsoleCursorPosition(handl, bull.getCoordBullet());
		cout << ' ';
	}
	
}
game::~game()
{
}

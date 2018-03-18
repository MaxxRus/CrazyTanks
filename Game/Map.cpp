
#include "Map.h"


void Map::showMap()
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			cout << map_array[i][j];
		}
		cout << endl;
	}
}
void Map::createMap()
{
	map_array = new char*[MAPSIZE];
	for (int i = 0; i < MAPSIZE; i++)
	{
		map_array[i] = new char[MAPSIZE];
	}
	createBorder();
	for (int i = 0; i < 30; i++)
	{
		creareWall();
	}
	
	
}

void Map::createBorder()
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			map_array[i][j] = ' ';
			if (i == 0 || i == MAPSIZE - 1 || j == 0 || j == MAPSIZE - 1)
			{
				map_array[i][j] = '#';
			}
		}
	}
}

void Map::creareWall()
{
	int vector, x, y;
	bool rightOrDown;
	
	rightOrDown = rand() % 2;
	x = rand() % (MAPSIZE-1);
	y = rand() % (MAPSIZE-1);
	if (rightOrDown) 
	{
		do
		{
			vector = rand() % 5 + 1;
		} while ((x + vector)>=MAPSIZE);
		for (int i = x; i < (x+vector); i++)
		{
			map_array[i][y] = '#';
		}
	}
	else
	{
		do
		{
			vector = rand() % 5 + 1;
		} while ((y + vector)>=MAPSIZE);
		for (int i = y; i < (y + vector); i++)
		{
			map_array[x][i] = '#';
		}
	}
		
}
Map::Map()
	:map_array(nullptr)
{

	createMap();
}


Map::~Map()
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		delete[] map_array[i];
	}
	delete[] map_array;
}

char** Map::getMapArea() 
{
	return map_array;
}

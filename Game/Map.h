#pragma once
#include <iostream>

#define MAPSIZE 25
using namespace std;

class Map
{
	
	
	char** map_array;
	void createMap();
	void createBorder();
	void creareWall();
public:
	void showMap();
	
	Map();
	~Map();
	char** getMapArea();
};




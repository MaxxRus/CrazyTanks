#pragma once
#include "Header.h"



using namespace std;
class bullet
{
	COORD coordBullet;
public:
	void show();
	void move(int code);
	bullet();
	~bullet();

	void setCoordBullet(COORD XY, eDiretion dir);

	COORD getCoordBullet()
	{
		return coordBullet;
	}
};




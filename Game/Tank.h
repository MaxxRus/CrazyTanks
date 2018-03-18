#pragma once
#include "Header.h"
#include <iostream>
using namespace std;

class Tank
{
	
	
	
	void fire();
	bool chekPosition();
protected:
	COORD coordTank;
	int tankColor;
public:
	
	Tank();
	~Tank();
	Tank(int color);
	void move(const int code);
	virtual void show();


	COORD getCoord()
	{
		return coordTank;
	}

	void setCoord(int x, int y) 
	{
		coordTank.X = x;
		coordTank.Y = y;
	}
};


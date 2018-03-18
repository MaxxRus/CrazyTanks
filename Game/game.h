#pragma once
#include "Map.h"
#include "TankPlyer.h"
#include "TankEnemy.h"
#include <conio.h>
#include "Header.h"
#include "bullet.h"

class game
{
	Map area;
	TankPlyer tankPlayer;
	TankEnemy tankEnemy;
	bullet bull;
	bool chekPosition(COORD coordTank, eDiretion dir);
	bool inputKey();
	eDiretion dir;
	bool gameOver;
	void setStartPositionPlayer();
	void showBull(eDiretion dir);
	void setStartPositionEnemy();
	eDiretion getRouteToTankPlayer();
	//setStartPositionBull(eDiretion dir);
public:
	void gaming();
	game();
	~game();
};


#include "TankEnemy.h"



TankEnemy::TankEnemy()
{
}


TankEnemy::~TankEnemy()
{
}


void TankEnemy::show()
{
	SetConsoleCursorPosition(handl, coordTank);
	SetConsoleTextAttribute(handl, RED);
	cout << "$";
	SetConsoleTextAttribute(handl, WHIETE);
}


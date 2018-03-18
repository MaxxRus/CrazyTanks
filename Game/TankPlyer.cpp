#include "TankPlyer.h"



TankPlyer::TankPlyer():Tank(GREN)
{

}

void TankPlyer::show()
{
	SetConsoleCursorPosition(handl, coordTank);
	SetConsoleTextAttribute(handl, GREN);
	cout << "$";
	SetConsoleTextAttribute(handl, WHIETE);
}

TankPlyer::~TankPlyer()
{
}

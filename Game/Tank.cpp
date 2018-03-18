#include "Tank.h"

void Tank::move(const int code)
{
	switch (code)
	{
	case UP:
		SetConsoleCursorPosition(handl, coordTank);
		cout << " ";
		coordTank.Y--;
		show();
		break;
	case DOWN:
		SetConsoleCursorPosition(handl, coordTank);
		cout << " ";
		coordTank.Y++;
		show();
		break;
	case LEFT:
		SetConsoleCursorPosition(handl, coordTank);
		cout << " ";
		coordTank.X--;
		show();
		break;
	case RIGHT:
		SetConsoleCursorPosition(handl, coordTank);
		cout << " ";
		coordTank.X++;
		show();
		break;
				
	}
}



void Tank::show()
{
	SetConsoleCursorPosition(handl, coordTank);
	cout << "$";
}
void fire();

Tank::Tank()
{
	
}
Tank::Tank(int color):tankColor(color)
{

}


Tank::~Tank()
{
}

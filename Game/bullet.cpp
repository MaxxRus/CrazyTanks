#include "bullet.h"



bullet::bullet()
{
}

void bullet::setCoordBullet(COORD XY, eDiretion dir)
{
	coordBullet.X = XY.X;
	coordBullet.Y = XY.Y;
	switch (dir)
	{
	case UP:
		coordBullet.Y--;
		break;
	case DOWN:
		coordBullet.Y++;
		break;
	case LEFT:
		coordBullet.X--;
		break;
	case RIGHT:
		coordBullet.X++;
		break;
	}

}

void bullet::move(int code)
{
	switch (code)
	{
	case UP:
		SetConsoleCursorPosition(handl, coordBullet);
		cout << " ";
		coordBullet.Y--;
		show();

		break;
	case DOWN:
		SetConsoleCursorPosition(handl, coordBullet);
		cout << " ";
		coordBullet.Y++;
		show();
		break;
	case LEFT:
		SetConsoleCursorPosition(handl, coordBullet);
		cout << " ";
		coordBullet.X--;
		show();
		break;
	case RIGHT:
		SetConsoleCursorPosition(handl, coordBullet);
		cout << " ";
		coordBullet.X++;
		show();
		break;

	}
}
void bullet::show()
{
	SetConsoleCursorPosition(handl, coordBullet);
	SetConsoleTextAttribute(handl, RED);
	cout << "*";
	SetConsoleTextAttribute(handl, WHIETE);
}

bullet::~bullet()
{
}

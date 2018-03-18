#include "game.h"
#include <ctime>


int main()
{
	
	srand(time(NULL));
	game worldOfTanks;
	worldOfTanks.gaming();
	system("PAUSE");
	return 0;
}


#pragma once
#include <Windows.h>
#include <iostream>

enum color { RED = 4, GREN = 2, WHIETE = 7 };

static HANDLE handl = GetStdHandle(STD_OUTPUT_HANDLE);
enum eDiretion { LEFT = 97, RIGHT= 100, UP = 119, DOWN = 115, GAMEOVER = 0};


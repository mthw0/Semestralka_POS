#pragma once
#include "plocha.hpp"


class Mravec
{
private:
	Plocha* board;
	int xcoord, ycoord, direction;

public:
	Mravec(Plocha*, int, int);
	int getRiadok();
	int getStlpec();
	void moveAnt(int, int);
};

#pragma once
#include "plocha.hpp"


class Mravec
{
private:
	Plocha* board;
	int xcoord, ycoord, smer, inverse;

public:
	Mravec(Plocha*, int, int, int);
	int getRiadok();
	int getStlpec();
	int getInverzna();
	void moveAnt(int, int);
    void moveAnt2(int, int);
};

#include "mravec.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Mravec::Mravec(Plocha* b, int x, int y)
{
	board = b;
	xcoord = x;
	ycoord = y;
	direction = 1;
}

int Mravec::getRiadok()
{
	return xcoord;
}

int Mravec::getStlpec()
{
	return ycoord;
}

void Mravec::moveAnt(int x, int y)
{
	if (board->getColor(x, y) == ' ')
	{	
		if (direction == 1)
			direction = 4;
		else if (direction == 2)
			direction = 3;
		else if (direction == 3)
			direction = 1;
		else if (direction == 4)
			direction = 2;
	} 

	else 
	{
		if (direction == 1)
			direction = 3;
		else if (direction == 2)
			direction = 4;
		else if (direction == 3)
			direction = 2;
		else if (direction == 4)
			direction = 1;
	}

	board->changeColor(x, y);

	if (direction == 1)
		xcoord = x - 1;
	if (direction == 2)
		xcoord = x + 1;
	if (direction == 3)
		ycoord = y - 1;
	if (direction == 4)
		ycoord = y + 1;

	if (board->isWall(xcoord, ycoord))
	{
		if (direction == 1)
		{
			xcoord += 2;
			direction = 2;
		}

		else if (direction == 2)
		{
			xcoord -= 2;
			direction = 1;
		}

		else if (direction == 3)
		{
			ycoord += 2;
			direction = 4;
		}

		else if (direction == 4)
		{
			ycoord -= 2;
			direction = 3;
		}
	}
}

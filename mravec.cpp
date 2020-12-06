#include "mravec.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Mravec::Mravec(Plocha* b, int x, int y, int inverse)
{
	board = b;
	xcoord = x;
	ycoord = y;
    smer = 1;
    inverse = inverse;
}

int Mravec::getRiadok()
{
	return xcoord;
}

int Mravec::getStlpec()
{
	return ycoord;
}

int Mravec::getInverzna() {
    return inverse;
}

void Mravec::moveAnt(int x, int y)
{
	if (board->getColor(x, y) == ' ')
	{	
		if (smer == 1)
            smer = 4;
		else if (smer == 2)
            smer = 3;
		else if (smer == 3)
            smer = 1;
		else if (smer == 4)
            smer = 2;
	} 

	else 
	{
		if (smer == 1)
            smer = 3;
		else if (smer == 2)
            smer = 4;
		else if (smer == 3)
            smer = 2;
		else if (smer == 4)
            smer = 1;
	}

	board->changeColor(x, y);

	if (smer == 1)
		xcoord = x - 1;
	if (smer == 2)
		xcoord = x + 1;
	if (smer == 3)
		ycoord = y - 1;
	if (smer == 4)
		ycoord = y + 1;

	if (board->isWall(xcoord, ycoord))
	{
		if (smer == 1)
		{
			xcoord += 2;
            smer = 2;
		}

		else if (smer == 2)
		{
			xcoord -= 2;
            smer = 1;
		}

		else if (smer == 3)
		{
			ycoord += 2;
            smer = 4;
		}

		else if (smer == 4)
		{
			ycoord -= 2;
            smer = 3;
		}
	}
}

void Mravec::moveAnt2(int x, int y)
{
    if (board->getColor(x, y) == ' ')
    {
        if (smer == 1)
            smer = 3;
        else if (smer == 2)
            smer = 4;
        else if (smer == 3)
            smer = 2;
        else if (smer == 4)
            smer = 1;
    }

    else
    {
        if (smer == 1)
            smer = 4;
        else if (smer == 2)
            smer = 3;
        else if (smer == 3)
            smer = 1;
        else if (smer == 4)
            smer = 2;
    }

    board->changeColor(x, y);

    if (smer == 1)
        xcoord = x - 1;
    if (smer == 2)
        xcoord = x + 1;
    if (smer == 3)
        ycoord = y - 1;
    if (smer == 4)
        ycoord = y + 1;

    if (board->isWall(xcoord, ycoord))
    {
        if (smer == 1)
        {
            xcoord += 2;
            smer = 2;
        }

        else if (smer == 2)
        {
            xcoord -= 2;
            smer = 1;
        }

        else if (smer == 3)
        {
            ycoord += 2;
            smer = 4;
        }

        else if (smer == 4)
        {
            ycoord -= 2;
            smer = 3;
        }
    }
}

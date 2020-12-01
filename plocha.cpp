#include"plocha.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;


Plocha::Plocha(char** b, int rs, int cs)
{
    plocha = b;
    velkostRiadka = rs;
    velkostStlpca = cs;
}


int Plocha::getVelkostStlpca()
{
	return velkostStlpca;
}


int Plocha::getVelkostRiadka()
{
	return velkostRiadka;
}


char Plocha::getColor(int x, int y)
{
	char el = plocha[x][y];

	if (el != ' ' && el != '#')
		return ' ';

	return el;
}

void Plocha::changeColor(int x, int y)
{
	char current = getColor(x, y);
	
	
	if (current == ' ')
        plocha[x][y] = '#';

	
	else
        plocha[x][y] = ' ';

}


bool Plocha::isWall(int x, int y)
{
	if (x < 0)
		return true;
	
	if (x > velkostRiadka - 1)
		return true;

	if (y < 0)
		return true;
	
	if (y > velkostStlpca - 1)
		return true;

	return false;
}

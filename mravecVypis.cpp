#include "mravecVypis.hpp"
#include <iostream>
using std::cout;
using std::endl;

void printToScreen(Plocha* b, Mravec a)
{
	
	int antRow = a.getRiadok();
	int antCol = a.getStlpec();
	int rowSize = b->getVelkostRiadka();
	int colSize = b->getVelkostStlpca();

	
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			
			if (i == antRow && j == antCol)
				cout << '@';

			
			else
				cout << b->getColor(i, j);
		}

		cout << endl;
	}
}

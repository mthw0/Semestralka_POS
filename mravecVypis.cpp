#include "mravecVypis.hpp"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;


void printToScreen1(Plocha* b, Mravec a)
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


void printToScreen(Plocha* b, std::vector<Mravec> ants) {
    int antRow;
    int antCol;
    int rowSize = b->getVelkostRiadka();
    int colSize = b->getVelkostStlpca();


    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            bool mravec = false;
            for (int x = 0; x < ants.size(); x++) {
                if (ants[x].getRiadok() == i && ants[x].getStlpec() == j)
                {
                    mravec = true;
                }

            }
            if (mravec) cout << '@';
            else cout << b->getColor(i, j);

        }
        cout << endl;
    }



}

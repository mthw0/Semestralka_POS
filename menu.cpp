#include"menu.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int menu()
{

	int vyber;

	cout << "1: Spustit Simulaciu Mravca" << endl;
	cout << "2. Ulozenie do suboru" << endl;
	cout << "3. Nacitanie zo suboru" << endl;
    cout << "4. Ulozenie na server" << endl;
    cout << "5. Nacitanie zo serveru" << endl;

    cout << "0: Quit" << endl;

	cout << "Vyberte si moznost zadanim cisla." << endl;

    scanf("%u",&vyber);

	while (vyber < 0 || vyber > 6)
	{
		cout << "Chyba, zvolena neplatna moznost." << endl;
        scanf("%u",&vyber);
	}

		switch (vyber)
		{
		case 1:
			return 1;

		case 2:
			return 2;

        case 3:
            return 3;

        case 4:
            return 4;

        case 5:
            return 5;
        }
}

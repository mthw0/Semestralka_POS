
#include "menu.hpp"
#include "TCP_Client.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
	int vyber = menu();
    int riadok, stlpec, pocetKrokov, velkostRiadku, velkostStlpca, aktualnyKrok = 0;
    char ** pole_kopia;

	while (vyber == 1)
	{

		cout << "Zadajte pocet stĺpcov 10 az 50:" << endl;
        scanf("%u",&velkostRiadku);
		
		while (velkostRiadku >= 50 && velkostRiadku <= 10)
		{
			cout << "Zadane cislo nepatri do rozsahu 10-50, skuste znova." << endl;
            scanf("%u",&velkostRiadku);
		}

        cout << "Zadajte pocet riadkov 10 az 50:" << endl;
        scanf("%u",&velkostStlpca);

		while (velkostStlpca >= 50 && velkostStlpca <= 10)
		{
            cout << "Zadane cislo nepatri do rozsahu 10-50, skuste znova." << endl;
            scanf("%u",&velkostStlpca);
		}

		cout << "Chcete nahodne generovanu mapu? 0/1" <<endl;

		int ano_nie;
		scanf("%u",&ano_nie);

		while (ano_nie>1)
        {
		    cout<< "Zadali ste neplatnu moznost. Zadajte 0 alebo 1." << endl;
            scanf("%u",&ano_nie);
        }

		cout << "Zadajte pociatocne umiestnenie mravca, suradnica x:"<< endl;
        scanf("%u",&riadok);
		
		while (riadok < 0 && riadok > velkostStlpca)
		{
			cout << "Zadane cislo nepatri do rozsahu, skuste znova";
            scanf("%u",&riadok);
		}

        cout << "Zadajte pociatocne umiestnenie mravca, suradnica y:"<< endl;
        scanf("%u",&stlpec);
		
		while (stlpec < 0 && stlpec > velkostRiadku)
		{
            cout << "Zadane cislo nepatri do rozsahu, skuste znova";
            scanf("%u",&stlpec);
		}

		cout << "Zadajte pocet krokov, ktore ma mravec spravit:" << endl;
        scanf("%u",&pocetKrokov);

        char **pole = new char*[velkostRiadku];
		for (int riadok = 0; riadok < velkostRiadku; riadok++)
            pole[riadok] = new char[velkostStlpca];

        if (ano_nie==1) {
            for (int i = 0;i<velkostStlpca ; i++)
                for (int j=0;j<velkostRiadku;j++)
                    if (rand()%2==0)
                    pole[i][j]=' ';
                    else pole[i][j]='#';

        }
        else {
            cout << "Zadajte pocet ciernych poli." << endl;
            int pocet_poli;
            scanf("%u",&pocet_poli);
            while (pocet_poli) {
                int cierne_pole_x, cierne_pole_y;

                cout << "Zadajte suradnicu cierneho pola, suradnica x:"<< endl;
                scanf("%u", cierne_pole_x);

                while (cierne_pole_x < 0 && cierne_pole_x>=velkostStlpca)
                {
                    cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                    scanf("%u",&cierne_pole_x);
                }

                cout << "Zadajte suradnicu cierneho pola, suradnica y:"<< endl;
                scanf("%u", cierne_pole_y);

                while (cierne_pole_y < 0 && cierne_pole_y>=velkostRiadku)
                {
                    cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                    scanf("%u",&cierne_pole_y);
                }
                pole[cierne_pole_x][cierne_pole_y]='#';
                pocet_poli--;
            }
        }


		Plocha *plocha = new Plocha(pole, velkostRiadku, velkostStlpca);
		Mravec mravec(plocha, riadok, stlpec);

		
		while (aktualnyKrok < pocetKrokov)
		{
            aktualnyKrok++;

			int mravecRiadok = mravec.getRiadok();
			int mravecStlpec = mravec.getStlpec();
			
			mravec.moveAnt(mravecRiadok, mravecStlpec);

			printToScreen(plocha, mravec);

			int novyRiadok = mravec.getRiadok();
			int novyStlpec = mravec.getStlpec();

			cout << "Krok c.: " << aktualnyKrok << "." << endl;
			cout << "Pozicia mravca: " << novyRiadok << ", "
                 << novyStlpec << endl;
			cout << "Enterom pokracujte na dalsi krok." << endl;

			
			cin.get();
		}

		pole_kopia=pole;
        vyber = menu();
	}
	while (vyber == 2) {
	    cout << "Ulozenie do suboru" << endl;
	    FILE *subor;
	    subor = fopen("save.txt","w");
        for (int i = 0;i<velkostStlpca ; i++) {
            for (int j=0;j<velkostRiadku;j++)
                fprintf(subor,"%c",pole_kopia[i][j]);
                fprintf(subor,"","\n");
        }
        fclose(subor);
        cout << "Ukladanie prebehlo uspesne" << endl;
        vyber = menu();
	}
    while (vyber == 3) {
        FILE *subor;
        subor = fopen("save.txt","r");
        for (int i = 0;i<velkostStlpca ; i++)
            for (int j=0;j<velkostRiadku;j++){
                fscanf(subor,"%c",&pole_kopia[i][j]);
                fscanf(subor,"%c", nullptr);
            }
        fclose(subor);

        char ** pole = pole_kopia;
        Plocha *plocha = new Plocha(pole, velkostRiadku, velkostStlpca);
        Mravec mravec(plocha, riadok, stlpec);

        while (aktualnyKrok < pocetKrokov)
        {
            aktualnyKrok++;

            int mravecRiadok = mravec.getRiadok();
            int mravecStlpec = mravec.getStlpec();

            mravec.moveAnt(mravecRiadok, mravecStlpec);

            printToScreen(plocha, mravec);

            int novyRiadok = mravec.getRiadok();
            int novyStlpec = mravec.getStlpec();

            cout << "Krok c.: " << aktualnyKrok << "." << endl;
            cout << "Pozicia mravca: " << novyRiadok << ", "
                 << novyStlpec << endl;
            cout << "Enterom pokracujte na dalsi krok." << endl;

            cin.get();
        }

        pole_kopia=pole;
        delete [] plocha;
        vyber = menu();

    }
    while (vyber == 4) {
        char* adresa = "localhost";
        TCP_Client tcpc(adresa,6000);
        int socket = tcpc.vytvorSpojenie();
        tcpc.posliSpravu(socket,"save");
        auto sprava = tcpc.prijmiSpravu(socket); // prijme spravu OK
        tcpc.posliSpravu(socket, nullptr); //TODO: vytovrenie spravy a odoslanie
        sprava = tcpc.prijmiSpravu(socket);
        if (sprava=="OK") cout<<"Uloženie na server úspešné." << endl;
        else cout << "Pri nahrávaní súboru na server doslo k chybe." << endl;
        tcpc.zatvorSpojenie();
    }
    while (vyber == 5) {
        char* adresa = "localhost";
        TCP_Client tcpc(adresa,6000);
        int socket = tcpc.vytvorSpojenie();
        tcpc.posliSpravu(socket,"load");
        auto sprava = tcpc.prijmiSpravu(socket); // prijme spravu OK
        tcpc.posliSpravu(socket, "OK");
        sprava = tcpc.prijmiSpravu(socket); // TODO: prijatie odpovede
        tcpc.zatvorSpojenie();
    }
	
	if (vyber == 0) {
        for (int row = 0; row < velkostRiadku; row++)
            delete[] pole_kopia[row];
        delete[] pole_kopia;
        return 0;
	}

}

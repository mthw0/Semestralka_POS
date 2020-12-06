  //#include "heap_monitor.h"
#include "menu.hpp"
#include <iostream>
#include <ctime>
#include <vector>
using std::cout;
using std::cin;
using std::endl;


int main()
{
	int vyber = menu();
    int riadok=0, stlpec=0, pocetKrokov=0, velkostRiadku=0, velkostStlpca=0, aktualnyKrok, pocetMravcov = 0;
    char ** pole_kopia;

    srand(time(0));

	while (vyber == 6)
	{
		cout << "Zadajte pocet stĺpcov 10 az 50:" << endl;
        scanf("%u",&velkostRiadku);
		
		while (velkostRiadku > 50 || velkostRiadku < 10)
		{
			cout << "Zadane cislo nepatri do rozsahu 10-50, skuste znova." << endl;
            scanf("%u",&velkostRiadku);
		}

        cout << "Zadajte pocet riadkov 10 az 50:" << endl;
        scanf("%u",&velkostStlpca);

		while (velkostStlpca > 50 || velkostStlpca < 10)
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
                scanf("%u", &cierne_pole_x);

                while (cierne_pole_x < 0 || cierne_pole_x>=velkostStlpca)
                {
                    cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                    scanf("%u",&cierne_pole_x);
                }

                cout << "Zadajte suradnicu cierneho pola, suradnica y:"<< endl;
                scanf("%u", &cierne_pole_y);

                while (cierne_pole_y < 0 || cierne_pole_y>=velkostRiadku)
                {
                    cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                    scanf("%u",&cierne_pole_y);
                }
                pole[cierne_pole_x][cierne_pole_y]='#';
                pocet_poli--;
            }
        }


		Plocha *plocha = new Plocha(pole, velkostRiadku, velkostStlpca);
		Mravec mravec(plocha, riadok, stlpec, 0);

		
		while (aktualnyKrok < pocetKrokov)
		{
            aktualnyKrok++;

			int mravecRiadok = mravec.getRiadok();
			int mravecStlpec = mravec.getStlpec();
			
			mravec.moveAnt(mravecRiadok, mravecStlpec);

			printToScreen1(plocha, mravec);

			int novyRiadok = mravec.getRiadok();
			int novyStlpec = mravec.getStlpec();

			cout << "Krok c.: " << aktualnyKrok << "." << endl;
			cout << "Pozicia mravca: " << novyRiadok << ", "
                 << novyStlpec << endl;
			cout << "Enterom pokracujte na dalsi krok." << endl;

			
			cin.get();
		}

		pole_kopia=pole;
        delete[] plocha;

        vyber = menu();
	}
	while (vyber == 2) {
	    cout << "Ulozenie do suboru" << endl;
	    FILE *subor;
	    subor = fopen("save.txt","w");
        fprintf(subor,"%u ",velkostStlpca);
        fprintf(subor,"%u",velkostRiadku);

	    for (int i = 0;i<velkostStlpca ; i++) {
            for (int j=0;j<velkostRiadku;j++)
                fprintf(subor,"%c",pole_kopia[i][j]);
                //fprintf(subor,"","\n");
        }

        fclose(subor);
        cout << "Ukladanie prebehlo uspesne" << endl;
        vyber = menu();
	}
    while (vyber == 3) {
        FILE *subor;
        subor = fopen("save.txt","r");
        velkostRiadku=0;
        velkostStlpca=0;

        fscanf(subor,"%u",&velkostStlpca);
        fscanf(subor,"%u",&velkostRiadku);
        char **pole = new char*[velkostRiadku];
        for (int riadok = 0; riadok < velkostRiadku; riadok++)
            pole[riadok] = new char[velkostStlpca];


        for (int i = 0;i<velkostStlpca ; i++)
            for (int j=0;j<velkostRiadku;j++){
                fscanf(subor,"%c",&pole[i][j]);
                //fscanf(subor,"%c", nullptr);
            }

        fclose(subor);

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
        //char ** pole = pole_kopia;
        Plocha *plocha = new Plocha(pole, velkostRiadku, velkostStlpca);
        Mravec mravec(plocha, riadok, stlpec, 0);

        while (aktualnyKrok < pocetKrokov) //jeden krok
        {
            aktualnyKrok++;

            int mravecRiadok = mravec.getRiadok();
            int mravecStlpec = mravec.getStlpec();

            mravec.moveAnt(mravecRiadok, mravecStlpec);

            printToScreen1(plocha, mravec);

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
        delete [] pole;
        vyber = menu();

    }
	
	if (vyber == 0) {
        for (int row = 0; row < velkostRiadku; row++)
            delete[] pole_kopia[row];
        delete[] pole_kopia;

        return 0;
	}

    while (vyber == 1) {
        cout << "Zadajte pocet stĺpcov 10 az 50:" << endl;
        scanf("%u",&velkostRiadku);

        while (velkostRiadku > 50 || velkostRiadku < 10)
        {
            cout << "Zadane cislo nepatri do rozsahu 10-50, skuste znova." << endl;
            scanf("%u",&velkostRiadku);
        }

        cout << "Zadajte pocet riadkov 10 az 50:" << endl;
        scanf("%u",&velkostStlpca);

        while (velkostStlpca > 50 || velkostStlpca < 10)
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


        cout << "Zadajte pocet mravcov"<< endl;
        scanf("%u",&pocetMravcov);

        while (pocetMravcov > 0 && pocetMravcov < 0)
        {
            cout << "Bolo zadane zle cislo";
            scanf("%u",&pocetMravcov);
        }

        cout << "Zadajte pocet krokov, ktore maju mravec spravit:" << endl;
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
                scanf("%u", &cierne_pole_x);

                while (cierne_pole_x < 0 || cierne_pole_x>=velkostStlpca)
                {
                    cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                    scanf("%u",&cierne_pole_x);
                }

                cout << "Zadajte suradnicu cierneho pola, suradnica y:"<< endl;
                scanf("%u", &cierne_pole_y);

                while (cierne_pole_y < 0 || cierne_pole_y>=velkostRiadku)
                {
                    cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                    scanf("%u",&cierne_pole_y);
                }
                pole[cierne_pole_x][cierne_pole_y]='#';
                pocet_poli--;
            }
        }


        Plocha *plocha = new Plocha(pole, velkostRiadku, velkostStlpca);
        std::vector<Mravec> mravce;

        for(int x=0; x < pocetMravcov; x++) {
            cout << "Zadajte pociatocne umiestnenie mravca cislo: "  << x << "! suradnica x:" << endl;
            scanf("%u", &riadok);

            while (riadok < 0 && riadok > velkostStlpca) {
                cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                scanf("%u", &riadok);
            }

            cout << "Zadajte pociatocne umiestnenie mravca cislo: "  << x << "! suradnica y:" << endl;
            scanf("%u", &stlpec);

            while (stlpec < 0 && stlpec > velkostRiadku) {
                cout << "Zadane cislo nepatri do rozsahu, skuste znova";
                scanf("%u", &stlpec);
            }



            cout << "Chcete aby mal mravec normalnu logiku alebo inverznu? 0/1" <<endl;

            int inverzna;
            scanf("%u",&inverzna);

            while (inverzna>1)
            {
                cout<< "Zadali ste neplatnu moznost. Zadajte 0 alebo 1." << endl;
                scanf("%u",&inverzna);
            }
            Mravec *m = new Mravec(plocha, riadok, stlpec, inverzna);
            mravce.push_back(*m);
        }

        aktualnyKrok = 0;
        while (aktualnyKrok < pocetKrokov)
        {
            aktualnyKrok++;
            for(int x = 0; x < mravce.size(); x++) {
                for(int y = x + 1; y < mravce.size(); y++) {
                    if(mravce[x].getRiadok() == mravce[y].getRiadok() && mravce[x].getStlpec() == mravce[y].getStlpec()) {
                        mravce.erase(mravce.begin() + x);
                    }
                }
            }


            for(auto &prvok : mravce) {
                int mravecRiadok = prvok.getRiadok();
                int mravecStlpec = prvok.getStlpec();

                if(prvok.getInverzna() == 0) {
                    prvok.moveAnt(mravecRiadok, mravecStlpec);
                } else {
                    prvok.moveAnt2(mravecRiadok, mravecStlpec);
                }

            }

            printToScreen(plocha, mravce);


            cout << "Krok c.: " << aktualnyKrok << "." << endl;
            cout << "Enterom pokracujte na dalsi krok." << endl;
            //cin.get();
            sleep(1);
            //TODO: pozastavenie a pokracovanie
        }

        pole_kopia=pole;
        delete[] plocha;

        for (auto mazany: mravce) {
            delete &mazany;
        }

        mravce.clear();
        vyber = menu();



    }
}

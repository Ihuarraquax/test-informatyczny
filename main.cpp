#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include "funkcje.hpp"

using namespace std;

int main()
{
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<string> tMenuGl;
    tMenuGl.push_back("Rozpocznij test");
    tMenuGl.push_back("Dodaj pytanie");
    tMenuGl.push_back("Ranking");
    tMenuGl.push_back("Baza pytan");
    tMenuGl.push_back("");
    tMenuGl.push_back("O autorze");
    tMenuGl.push_back("");
    tMenuGl.push_back("Wyjdz z programu");
start:
    int n=iloscpyt();


    string tresc[n],odpA[n],odpB[n],odpC[n],odpD[n];
    string poprawna[n];
    wczytajpyt(tresc,odpA,odpB,odpC,odpD,poprawna,n);
    int id = 0;
    do
    {
        n=iloscpyt();
        string tresc[n],odpA[n],odpB[n],odpC[n],odpD[n];
        string poprawna[n];
        wczytajpyt(tresc,odpA,odpB,odpC,odpD,poprawna,n);
        menu("TEST Z INFORMATYKI",tMenuGl, id);
        system("cls");
        switch(id)
        {
        case 7:
        {
            naglowek("Wyjscie z programu",249);
            cout<<"Wcisnij [T], jesli naprawde chcesz wyjsc z programu...";
            if(getch() == 't')
                id = -1;
            cout<<endl;
        }
        break;
        case 0:
        {
            system("cls");
            tasowaniepyt(tresc,odpA,odpB,odpC,odpD,poprawna,n);
            if(n<10)
            {
                naglowek("TEST",35);
                cout<<"Przykro mi, w bazie nie ma wystarczajacej liczby pytan aby przeprowadzic test."<<endl<<"Dodaj ich wiecej."<<endl;
                getch();
                goto kp;
            }
            naglowek("TEST",52);
            cout<<"Program wylosowal dla Ciebie 10 pytan z dziedziny informatyki."<<endl<<"Nacisnij dowolny klawisz, gdy bedziesz juz gotowy."<<endl<<"UWAGA: Test mierzy czas, wiec nie zwlekaj z odpowiedzia :)";
            getch();
            int punkty=0;
            char ODP;
            time_t start, koniec;
            double czas;
            time(&start);
            for(int i=0; i<10; i++)
            {
                system("cls");
                vector<string> pytanie;
                pytanie.push_back(odpA[i]);
                pytanie.push_back(odpB[i]);
                pytanie.push_back(odpC[i]);
                pytanie.push_back(odpD[i]);

                id = 0;

                menu(tresc[i],pytanie, id,79);
                system("cls");
                switch(id)
                {
                case 0:
                    ODP='A';
                    break;
                case 1:
                    ODP='B';
                    break;
                case 2:
                    ODP='C';
                    break;
                case 3:
                    ODP='D';
                    break;
                }

                if(ODP==poprawna[i][0]) punkty++;
            }
            system("cls");
            time(&koniec);
            czas = difftime(koniec,start);
            if(czas>29) czas=29;
            int wynik = punkty*(30-czas);
            naglowek("WYNIK:",52);
            cout<<"Poprawne odpowiedzi: "<<punkty<<"/10"<<endl<<endl;
            SetConsoleTextAttribute(uchwyt, 10);
            if(punkty>=5) cout<<"Brawo! Udalo ci sie zdac test na "<<punkty*10<<"%.";
            SetConsoleTextAttribute(uchwyt, 7);
            SetConsoleTextAttribute(uchwyt, 12);
            if(punkty<5) cout<<"Niestety, nie udalo ci sie zdac testu, Twoj wynik to "<<punkty*10<<"%."<<endl;
            SetConsoleTextAttribute(uchwyt, 7);

            cout<<"Czas: "<<czas<<'s'<<endl;
            cout<<"Punkty: "<<wynik<<"pkt"<<endl<<endl<<endl;
            cin.clear();
            cin.sync();
            getch();
            dodajuzytkownika(wynik);
            SetConsoleTextAttribute(uchwyt, 23);
            cout<<endl<<endl<<"[TIP] Nie zapomnij sprawdzic, ktore miejsce zajales w rankingu";
            SetConsoleTextAttribute(uchwyt, 7);
            getch();
        }
        break;
        case 1:
        {

            system("cls");
            dodajpyt();
            system("cls");
            goto start;
        }
        break;
        case 2:
        {
            system("cls");
            ranking();
            getch();
            cin.clear();
            cin.sync();
        }
        break;

        case 3:
        {
            system("cls");
            int n=iloscpyt();
            string haslo;
            naglowek("BAZA PYTAN",150);
            cout<<"Podaj tajne haslo dostepu: ";
            cin>>haslo;
            if(haslo=="calineczka")
            {
                system("cls");
                naglowek("TAJNA BAZA PYTAN");
                for(int i=0; i<n; i++)
                {
                    cout<<endl<<i+1<<". ";
                    cout<<"Tresc pytania: "<<tresc[i]<<endl<<endl;
                    cout<<"A: "<<odpA[i]<<endl;
                    cout<<"B: "<<odpB[i]<<endl;
                    cout<<"C: "<<odpC[i]<<endl;
                    cout<<"D: "<<odpD[i]<<endl<<endl;
                    cout<<"Poprawna: "<<poprawna[i]<<endl;
                }


            }
            else
            {
                cout<<endl<<"BLAD HASLA!";
            }
        }
        break;
        case 5:
        {
            system("cls");
            naglowek("O AUTORZE...");
            cout<<"Program wykonal: ";
            SetConsoleTextAttribute(uchwyt, 2);
            cout<<"Hubert Zablocki ";
            SetConsoleTextAttribute(uchwyt, 7);
            cout<<"jako projekt z programowania na pierwszy"<<endl<<"semestr studiow.";


        }
        break;
        }
kp:
        if(id > 0)
        {
            cout<<endl<<endl;
            SetConsoleTextAttribute(uchwyt, 6);
            cout<<"Wcisnij [ENTER], aby przejsc do menu...";
            SetConsoleTextAttribute(uchwyt, 7);
            gotoxy(1,1);
            getch();
        }
        system("cls");
    }
    while(id > -1);
    return 0;
}

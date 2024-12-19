#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "vector"
#include <sstream>
#include "funkcje.hpp"

using namespace std;
//wyswietla wszystkie rekordy zapamietane w bazie danych
//jesli w baza danych jest pusta wyswietla komunikat
void wyswietl(vector<dane> &baza)
{
    if (baza.size() == 0)//sprawdza czy baza danych jest pusta
    {
        cout<<"baza danych jest pusta"<<endl;
        return;
    }
    for (int i = 0; i < baza.size(); i++)
    {
        cout<<"Nazwa: "<<baza[i].nazwa<<endl;
        cout<<"Producent: "<<baza[i].producent<<endl;
        cout<<"Kategoria: "<<baza[i].kategoria<<endl;
        cout<<"Material korpusu: "<<baza[i].material_korpusu<<endl;
        cout<<"Ilosc strun: "<<baza[i].liczba_strun<<endl;
        cout<<"Kolor: "<<baza[i].kolor<<endl;
        cout<<"Liczba sztuk w magazynie: "<<baza[i].magazyn<<endl;
        cout<<"Cena: "<<baza[i].cena<<endl;
        cout<<"Data nastepnej dostawy: "<<baza[i].data_dostawy<<endl;
        cout<<"Ilosc sztuk w nastepnej dostawie: "<<baza[i].liczba_dostawa<<endl;
        cout<<endl;
    }
}

void dodanie_produktu(vector<dane> &baza)
{
    // dodanie nowego obiektu do tablicy vector na koncu tablicy
    baza.push_back(dane());
    int ostatni_index = baza.size() - 1;

    do
    {
        cout<<"Podaj nazwe produktu"<<endl;
        cin.ignore(255, '\n');//czysci cin
        getline(cin, baza[ostatni_index].nazwa);
    }while (baza[ostatni_index].nazwa.length() > 256);//sprawdzenie czy wprowadzona dlugosc tekstu nie przekracza 256 znakow
    do
    {
        cout<<"Podaj producenta"<<endl;
        getline(cin, baza[ostatni_index].producent);
    }while (baza[ostatni_index].producent.length() > 256);
    do
    {
        while(true)
        {
        cout<<"Podaj kategorie: akustyczna, elektryczna, klasyczna "<<endl;
        cin>>baza[ostatni_index].kategoria;
        if(baza[ostatni_index].kategoria != "akustyczna" && baza[ostatni_index].kategoria != "elektryczna" && baza[ostatni_index].kategoria != "klasyczna" )
        {
            //sprawdzenie czy uzytkownik wprowadzil poprawne dane
            //jesli nie to petla bedzie sie powtarzac dopoki uzytkownik nie wprowadzi prawidlowych
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
        }
        else
        {
        break;
        }
        }
    }while (baza[ostatni_index].kategoria.length() > 256);//sprawdzenie czy wprowadzona dlugosc tekstu nie przekracza 256 znakow
    do
    {
       while(true)
        {
        cout<<"Podaj material korpusu: mahon, lipa, klon, jesion, cedr "<<endl;
        cin>>baza[ostatni_index].material_korpusu;
        if(baza[ostatni_index].material_korpusu != "mahon" && baza[ostatni_index].material_korpusu != "lipa" && baza[ostatni_index].material_korpusu != "jesion" && baza[ostatni_index].material_korpusu != "cedr")
        {
            //sprawdzenie czy uzytkownik wprowadzil poprawne dane
            //jesli nie to petla bedzie sie powtarzac dopoki uzytkownik nie wprowadzi prawidlowych
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
        }
        else
        {
        break;
        }
        }
    }while (baza[ostatni_index].material_korpusu.length() > 256);//sprawdzenie czy wprowadzona dlugosc tekstu nie przekracza 256 znakow

    do
    {
        while(true)
        {
        cout<<"Podaj ilosc strun "<<endl;
        cin>>baza[ostatni_index].liczba_strun;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
        }
        else
        {
        break;
        }
        }
        //sprawdzenie czy uzytkownik wprowadzil poprawne dane
        //jesli nie to petla bedzie sie powtarzac dopoki uzytkownik nie wprowadzi prawidlowych
    }while (baza[ostatni_index].liczba_strun != 6 && baza[ostatni_index].liczba_strun != 7 &&
            baza[ostatni_index].liczba_strun != 8 && baza[ostatni_index].liczba_strun != 12);
    do
    {
        cout<<"Podaj kolor"<<endl;
        cin.clear();
        cin.ignore(255, '\n');//czysci cin
        getline(cin, baza[ostatni_index].kolor);
    }while (baza[ostatni_index].kolor.length() > 50);//sprawdza czy wprowadzona dlugosc tekstu jest mniejsza niz 50
    do
    {
    while(true)
    {
    cout<<"Podaj liczbe sztuk w magazynie "<<endl;
    cin>>baza[ostatni_index].magazyn;
    if(cin.fail())
    {
        //sprawdzenie czy uzytkownik wprowadzil poprawne dane
        //jesli nie to petla bedzie sie powtarzac dopoki uzytkownik nie wprowadzi prawidlowych
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
    }
    else
    {
        break;
    }
    }
    }while (baza[ostatni_index].magazyn <= 0);
    do
    {
    while(true)
    {
    cout<<"Podaj cene "<<endl;
    cin>>baza[ostatni_index].cena;
    if(cin.fail())
    {
        //sprawdzenie czy uzytkownik wprowadzil poprawne dane
        //jesli nie to petla bedzie sie powtarzac dopoki uzytkownik nie wprowadzi prawidlowych
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
    }
    else
    {
        break;
    }
    }
    }while (baza[ostatni_index].cena <= 0);
}

void usuniecie_produktu(vector<dane> &baza)
{
    //sprawdza czy w bazie danych sa zawaerte rekordy
    //jesli nie pokazuje komunikat i wraca do menu
    if (baza.size() == 0)//sprawdza czy baza danych jest pusta
    {
        cout<<"baza danych jest pusta"<<endl;
        return;
    }

    int index;
    do {
        cout<<"Podaj index elementu do usuniecia: ";
        cin>>index;
    } while (index < 0 || index >= baza.size());//sprawdza czy produkt o takim indexie istnieje
    baza.erase(baza.begin() + index);

}

void dostawa(vector<dane> &baza)//pozwala na dodanie dostawy do istniejacego produktu
{
    if (baza.size() == 0)//sprawdza czy baza danych jest pusta
    {
        cout<<"baza danych jest pusta"<<endl;
        return;
    }
    // sprawdzenie do ktorego rekordu mozna dodac dostawe
    vector<int> dostepne_indexy;
    cout<<"dostepne indexy rekordow do dodania dostawy: ";
    for (int i = 0; i < baza.size(); i++) {
        if (baza[i].data_dostawy == "") {
            dostepne_indexy.push_back(i);
            cout<<i;
        }
        cout<<endl;
    }

    int index;
    do
    {
        cout<<"Podaj index elementu do dodania dostawy: ";
        cin>>index;
        for (int i: dostepne_indexy)
        {
            // sprawdzenie czy podany przez uzytkownika index jest w tablicy 'dostepne indexy'
            // jezeli tak to uzytkownik wpisuje date i liczbe dostawy
            // jezeli nie to wyswietla blad i prosi o wprowadzenie poprawnego indexu
            if (index == i)
            {
                
                cout<<"Podaj date dostawy "<<endl;
                cin>>baza[index].data_dostawy;
                do
                {
                while(true)
                {
                cout<<"Podaj liczbe sztuk w dostawie "<<endl;
                cin>>baza[index].liczba_dostawa;
                if(cin.fail())
                {
                    //sprawdzenie czy uzytkownik wprowadzil poprawne dane
                    //jesli nie to petla bedzie sie powtarzac dopoki uzytkownik nie wprowadzi prawidlowych
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
                }
                else
                {
                break;
                }
                }
                }while (baza[index].liczba_dostawa <= 0);
                return;
            }
            else
            {
            cout<<"nie mozna dodac dostawy"<<endl;
            return;
            }
            return;
        }
    }while (true);   
}

void wczytywanie_danych(vector<dane> &baza)
{
    baza.clear(); // czysci cala tablice

    string nazwa_pliku, pojedyncza_wartosc;
    int i = 0;
    cout<<"Podaj nazwe pliku: ";
    cin>>nazwa_pliku;
    ifstream file(nazwa_pliku + ".txt");//wprowadzenie nazwy pliku bez rozszerzenia
    if (file.is_open())
    {
        string linia_tekstu;
        while (getline(file, linia_tekstu))
        {
            stringstream ss(linia_tekstu);
            string item;
            vector<string> elementy;
            while (getline(ss, item, ';'))//wczytuje dane odzielane znakiem ";"
            {
                elementy.push_back(item);//dodaje na koncu tablicy vecotr
            }
            baza.push_back(dane());
            int ostatni_index = baza.size() - 1;
            baza[ostatni_index].nazwa = elementy[0];
            baza[ostatni_index].producent = elementy[1];
            baza[ostatni_index].kategoria = elementy[2];
            baza[ostatni_index].material_korpusu = elementy[3];
            baza[ostatni_index].liczba_strun = stoi(elementy[4]);//zmienia typ danych na string 
            baza[ostatni_index].kolor = elementy[5];
            baza[ostatni_index].magazyn = stoi(elementy[6]);//zmienia typ danych na string 
            baza[ostatni_index].cena = stof(elementy[7]);//zmienia typ danych na string 
            baza[ostatni_index].data_dostawy = elementy[8];
            baza[ostatni_index].liczba_dostawa = stoi(elementy[9]);//zmienia typ danych na string 
        }
        file.close();
    }
}

void zapisanie_danych(vector<dane> &baza)
{
    if (baza.size() == 0)//sprawdza czy baza danych jst pusta
    {
        cout<<"baza danych jest pusta"<<endl;
        return;
    }

    string nazwa, linia = "";
    cout<<"Podaj nazwe bazy danych do zapisu: ";
    cin>>nazwa;

    ofstream file(nazwa + ".txt");//podanie nazwy pliku bez rozszerzenia
    if (file.is_open())
    {
        for (int i = 0; i < baza.size(); i++)
        {
            linia += baza[i].nazwa + ";";
            linia += baza[i].producent + ";";
            linia += baza[i].kategoria + ";";
            linia += baza[i].material_korpusu + ";";
            linia += to_string(baza[i].liczba_strun) + ";";
            linia += baza[i].kolor + ";";
            linia += to_string(baza[i].magazyn) + ";";
            linia += to_string(baza[i].cena) + ";";
            linia += baza[i].data_dostawy + ";";
            linia += to_string(baza[i].liczba_dostawa) + "\n";

            file<<linia;
            linia = "";
        }
    }
}

void wyszukaj(vector<dane> &baza)
{
    if (baza.size() == 0)//sprawdza czy baza danych jst pusta
    {
        cout<<"baza danych jest pusta"<<endl;
        return;
    }
    string wyszukanie;
    cout<<"Podaj nazwe produktu lub kategorie: ";
    cin>>wyszukanie;

    for (int i = 0; i < baza.size(); i++)
    {
        if (baza[i].nazwa == wyszukanie || baza[i].kategoria == wyszukanie)//pozwala na znalezienie produktu po nazwie lub kategori
        {
            cout<<"Nazwa: "<<baza[i].nazwa<<endl;
            cout<<"Producent: "<<baza[i].producent<<endl;
            cout<<"Kategoria: "<<baza[i].kategoria<<endl;
            cout<<"Material korpusu: "<<baza[i].material_korpusu<<endl;
            cout<<"Ilosc strun: "<<baza[i].liczba_strun<<endl;
            cout<<"Kolor: "<<baza[i].kolor<<endl;
            cout<<"Liczba sztuk w magazynie: "<<baza[i].magazyn<<endl;
            cout<<"Cena: "<<baza[i].cena<<endl;
            cout<<"Data nastepnej dostawy: "<<baza[i].data_dostawy<<endl;
            cout<<"Ilosc sztuk w nastepnej dostawie: "<<baza[i].liczba_dostawa<<endl;
            cout<<endl;
        }
    }
}


void zmiana_danych(vector<dane> &baza)
{
    if (baza.size() == 0)//sprawdza czy baza dabych jest pusta
    {
        cout<<"baza danych jest pusta"<<endl;
        return;
    }
    int index;
    cout<<"Podaj index elementu do zmiany: ";
    cin>>index;

    if (index < 0 || index > baza.size() - 1)//sprawdza czy produkt o takim inedexie istnieje
    {
        cout<<"taki rekord nie istnieje!";
        return;
    }

    do
    {
        cout<<"Podaj nowa nazwe produktu"<<endl;
        cin.ignore(255, '\n');
        getline(cin, baza[index].nazwa);
    }while (baza[index].nazwa.length() > 255);
    do
    {
        cout<<"Podaj nowego producenta"<<endl;
        getline(cin, baza[index].producent);
    }while (baza[index].producent.length() > 256);
    do
    {
        while(true)
        {
        cout<<"Podaj kategorie nowa: akustyczna, elektryczna, klasyczna "<<endl;
        cin>>baza[index].kategoria;
        if(baza[index].kategoria != "akustyczna" && baza[index].kategoria != "elektryczna" && baza[index].kategoria != "klasyczna" )
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
        }
        else
        {
        break;
        }
        }
    }while (baza[index].kategoria.length() > 256);
    do
    {
        while(true)
        {
        cout<<"Podaj nowy material korpusu: mahon, lipa, klon, jesion, cedr "<<endl;
        cin>>baza[index].material_korpusu;
        if(baza[index].material_korpusu != "mahon" && baza[index].material_korpusu != "lipa" && baza[index].material_korpusu != "jesion" && baza[index].material_korpusu != "cedr")
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
        }
        else
        {
        break;
        }
        }
    }while (baza[index].material_korpusu.length() > 256);

    do
    {
        while(true)
        {
        cout<<"Podaj nowa ilosc strun "<<endl;
        cin>>baza[index].liczba_strun;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
        }
        else
        {
        break;
        }
        }
    }while (baza[index].liczba_strun != 6 && baza[index].liczba_strun != 7 &&
             baza[index].liczba_strun != 8 && baza[index].liczba_strun != 12);
    do
    {
        cout<<"Podaj nowy kolor"<<endl;
        cin.clear();
        cin.ignore(255, '\n');
        getline(cin, baza[index].kolor);
    }while (baza[index].kolor.length() > 50);
    do
    {
    while(true)
    {
    cout << "Podaj nowa liczbe sztuk w magazynie "<<endl;
    cin >> baza[index].magazyn;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
    }
    else
    {
        break;
    }
    }
    }while (baza[index].magazyn <= 0);
    do
    {
    while(true)
    {
    cout<<"Podaj nowa cene "<<endl;
    cin>>baza[index].cena;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Podano niewlasciwe dane. Wprowadz je jeszcze raz"<<endl;
    }
    else
    {
        break;
    }
    }
    }while (baza[index].cena <= 0);


}


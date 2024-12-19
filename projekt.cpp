#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include "funkcje.hpp"

using namespace std;

int main()
{
    int n;
    vector<dane> baza;

    do
    {
    cout<<"[0] koniec"<<endl;
    cout<<"[1] dodaj produkt"<<endl;
    cout<<"[2] usun produkt"<<endl;
    cout<<"[3] zmien dane produktu"<<endl;
    cout<<"[4] dodaj dostawe"<<endl;
    cout<<"[5] wyszukaj produkt"<<endl;
    cout<<"[6] wyswietl wszystkie produkty"<<endl;
    cout<<"[7] zapisz dane do pliku"<<endl;
    cout<<"[8] wczytaj dane z pliku"<<endl;
    cin>>n;

    switch (n) {
        case 0:
            return 0;
        case 1:
            dodanie_produktu(baza);//funkcja dodajaca produkt
            break;
        case 2:
            usuniecie_produktu(baza);//funkcja usuwajaca produkt
            break;
        case 3:
            zmiana_danych(baza);//funkcja zmieniajaca dane wybranego produktu
            break;
        case 4:
            dostawa(baza);//funkcja dodajaca dostawe do istniejacego produktu
            break;
        case 5:
            wyszukaj(baza);//wyszukuje produkty w bazie danych zgodnie z wprowadzona nazwa lub kategoria
            break;
        case 6:
            wyswietl(baza);//funkcja wyswietla wszystkie dane zgromadzone w pamieci
            break;
        case 7:
            zapisanie_danych(baza);//funkcja zapisuje do pliku dane zgromadzone w pamieci
            break;
        case 8:
            wczytywanie_danych(baza);//funkcja wczytuje z pliku dane 
            break;
        default:
            break;
    }
    }while (n!=0);


}
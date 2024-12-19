#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct dane {
    string nazwa;//tablica znakow o max dluosci 256 znakow
    string producent;//tablica znakow o max dluosci 256 znakow
    string kategoria;//tablica znakow o max dluosci 256 znakow i jednym z wybranych podtypow
    string material_korpusu;//tablica znakow o max dluosci 256 znakow i jednym z wybranych podtypow
    int liczba_strun;//liczba calkowita, do wyboru 6 7 8 12
    string kolor;//tablica znakow o dlugosci 50 znakow
    int magazyn;//liczba calkowita
    float cena;//liczba zmiennoprzecinkowa
    string data_dostawy;//dd-mm-rrrr
    int liczba_dostawa;//liczba calkowita
};


void wyswietl(vector<dane> &baza);
//wyswietla wszystkie dane zgromadzone w bazie danych
//jesli baza danych jest pusta zwraca komunikat
void dodanie_produktu (vector<dane> &baza);//dodaje produkt
void usuniecie_produktu (vector<dane> &baza);
//usuwa wybrany produkt z bazy danych
//jesli baza danych jest pusta zwraca komunikat
void dostawa(vector<dane> &baza);
//daje mozliwosc dodania dostawy do istniejacego produktu
//jesli baza danych jest pusta zwraca komunikat
void wczytywanie_danych(vector<dane> &baza);
//wczytuje baze danych z istniejacego pliku
void zapisanie_danych(vector<dane> &baza);
//zapisuje baze danych do pliku
//jesli baza danych jest pusta zwraca komunikat
void wyszukaj(vector<dane> &baza);
//wyszukuje produkty w bazie danych zgodnie z wprowadzona nazwa lub kategoria
//jesli baza danych jest pusta zwraca komunikat
void zmiana_danych(vector<dane> &baza);//zmienia dane wybranego produktu
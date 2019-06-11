#ifndef DIJKSTRY__H
#define DIJKSTRY__H

#include <iostream>
#include <random>
using namespace std;

class Graf
{
private:
	//Wspolne
	int n;  //liczba wierzcholkow
	float g;	//gestosc grafu w %
	int m;		//liczba krawêdzi w grafie

	//Macierz
	int **M;

	//Lista
	list<int> **L;

	//Wierzcho³ek
	int *waga;	 //Wagi n wierzcholkow
	//Dijkstry
	int *d;   //Tablica kosztów dojscia
	int *p;	//Tablica poprzedników
	bool *QS;   //jesli false to jest w zbiorze Q jeœli true to w S
	int *S; //Stos

public:
	///Metody Wspolne
	void wyswietl_dane();

	///Meteody Macierzy
	//funkcje podstawowe
	void Stworz_Macierz();
	void Inicjalizuj_Macierz(int wierzcholki, int gestosc);

	//funkcje wyœwietlajace
	void wyswietl_krawedzie();
	void Wyswietl_Macierz();

	///Metody Listy
	//funkcje ogolne
	void Inicjalizuj_Liste(int wierzcholki, int gestosc);
	void Stworz_Liste();

	//funkcje wyswietlajace
	void wyswietl_liste();

	///Algorytm Dijkstry
	void Dijkstry(int v,char T);
	void wyswietl_Dijkstry();
};

#endif //DIJKSTRY__H
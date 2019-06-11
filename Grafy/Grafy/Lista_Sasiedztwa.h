#ifndef LISTA__SASIEDZTWA
#define LISTA__SASIEDZTWA

#include <iostream>
#include <random>
#include <list>
using namespace std;



class Lista_Sasiedztwa
{
private:
	int n;
	float d;
	int m;
	list<int> **A;
public:
	//funkcje ogolne
	void inicjalizuj(int wierzcholki, int gestosc);
	void Stworz_Liste();

	//funkcje wyswietlajace
    void wyswietl_liste();
	void wyswietl_dane();
};
#endif //LISTA__SASIEDZTWA
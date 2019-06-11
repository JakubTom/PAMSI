#ifndef MACIERZ__SASIEDZTWA
#define MACIERZ__SASIEDZTWA

#include <iostream>
#include <random>
using namespace std;

class Macierz_Sasiedztwa
{
private:
	int n;
	float d;
	int m;
	int **A;
public:
	//funkcje podstawowe
	void Stworz_Macierz();
	void inicjalizuj(int wierzcholki, int gestosc);

	//funkcje wyœwietlajace
	void wyswietl_dane();
	void wyswietl_krawedzie();
	void Wyswietl_Macierz();
	
};
#endif //SORTOWANIE_H
#include "pch.h"
#include "Macierz_Sasiedztwa.h"


void Macierz_Sasiedztwa::Stworz_Macierz()
{
	int i;
	int x, y;
	
	A = new int*[n];
	for (int k = 0; k < n; k++)
	{
		A[k] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
		}
	}

	//generowanie losowych liczb
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, n - 1);
	//int x = dis(gen);

	//przypisanie losowych definicji krawêdzi poszczególnym wierzcho³kom (graf nieskierowany)
	for (i = 0; i < m; i++)
	{
		do
		{
			x = dis(gen);
			y = dis(gen);
		} 
		//zabezpieczenie aby nie tworzy³y siê te same krawêdzie 
		while ((A[x][y] == 1) || (A[y][x] == 1) || x == y);
		A[x][y] = 1;
		A[y][x] = 1;
		//cout << (int)A[x][y];
	}
}

void Macierz_Sasiedztwa::inicjalizuj(int wierzcholki, int gestosc)
{
	n = wierzcholki;
	d = gestosc/100;
	m = d * (n*(n - 1)) / 2;
	Stworz_Macierz();
}

void Macierz_Sasiedztwa::Wyswietl_Macierz()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << (int)A[i][j] << " ";
		cout << endl;
	}
}

void Macierz_Sasiedztwa::wyswietl_dane()
{
	cout << " liczba  wierzcholkow " << n << endl;
	cout << " liczba krawedzi " << m << endl;
	cout << " gestosc grafu " << d*100 <<"%" << endl;
}

void Macierz_Sasiedztwa::wyswietl_krawedzie()
{
	cout << "n = " << n << endl;
	cout << "Krawedzie w grafie:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if ((int)A[i][j] == 1)
				cout << i << " " << j << endl;
		}
}
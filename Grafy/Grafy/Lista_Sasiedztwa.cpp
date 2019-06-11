#include "pch.h"
#include "Lista_Sasiedztwa.h"
#include <iomanip>



void Lista_Sasiedztwa::inicjalizuj(int wierzcholki, int gestosc)
{
	n = wierzcholki;
	d = gestosc / 100;
	m = d * (n*(n - 1)) / 2;

	//Tworzenie Tablicy sasiedztwa - kazdy element tablicy to lista
	A = new list<int> *[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = new list<int>;
	}

	//wypelnienie tablicy pustymi listami
	//for (int i = 0; i < n; i++)
	//{
	//	A[i] = NULL;
	//}
	Stworz_Liste();
}

void Lista_Sasiedztwa::Stworz_Liste()
{
	int **S;
	int x, y;
	S = new int*[n];
	for (int k = 0; k < n; k++)
	{
		S[k] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			S[i][j] = 0;
		}
	}

	//generowanie losowych liczb
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, n - 1);
	//int x = dis(gen);

	//przypisanie losowych definicji krawêdzi poszczególnym wierzcho³kom (graf nieskierowany)
	for (int i = 0; i < m; i++)
	{
		do
		{
			//x to numer wierzcholka 
			x = dis(gen);
			//y to jego nowy si¹siad
			y = dis(gen);
		}
		//zabezpieczenie aby nie tworzy³y siê te same krawêdzie 
		while ((S[x][y] == 1) || (S[y][x] == 1) || x == y);
		S[x][y] = 1;
		S[y][x] = 1;

		A[x]->push_back(y);
		A[y]->push_back(x);
	
	}

}

void Lista_Sasiedztwa::wyswietl_liste()
{
	for (int k = 0; k < n; k++)
	{
		cout << "A[" << k << "] =";
		for (list<int>::iterator i = A[k]->begin(); i!= A[k]->end(); ++i)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
}

void Lista_Sasiedztwa::wyswietl_dane()
{
	cout << " liczba  wierzcholkow " << n << endl;
	cout << " liczba krawedzi " << m << endl;
	cout << " gestosc grafu " << d * 100 << "%" << endl;
}
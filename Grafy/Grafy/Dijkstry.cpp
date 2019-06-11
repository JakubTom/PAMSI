#include "pch.h"
#include "Dijkstry.h"
const int MAXINT = 2147483647;

//Metody Wspolne
void Graf::wyswietl_dane()
{
	cout << " liczba  wierzcholkow " << n << endl;
	cout << " liczba krawedzi " << m << endl;
	cout << " gestosc grafu " << g * 100 << "%" << endl;
}

//Metody Macierzy
void Graf::Stworz_Macierz()
{
	int i;
	int x, y;

	M = new int*[n];
	for (int k = 0; k < n; k++)
	{
		M[k] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M[i][j] = 0;
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
		while ((M[x][y] == 1) || (M[y][x] == 1) || x == y);
		M[x][y] = 1;
		M[y][x] = 1;
		//cout << (int)A[x][y];
	}
}

void Graf::Inicjalizuj_Macierz(int wierzcholki, int gestosc)
{
	n = wierzcholki;
	g = (1.0*gestosc) / 100;
	m = g * (n*(n - 1)) / 2;
	waga = new int[n];
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, n - 1);
	for (int i = 0; i < n; i++)
	{
		waga[i] = dis(gen);
	}
	Stworz_Macierz();
}

void Graf::Wyswietl_Macierz()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << (int)M[i][j] << " ";
		cout << endl;
	}
}

void Graf::wyswietl_krawedzie()
{
	cout << "n = " << n << endl;
	cout << "Krawedzie w grafie:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if ((int)M[i][j] == 1)
				cout << i << " " << j << endl;
		}
}

//Metody Listy
void Graf::Inicjalizuj_Liste(int wierzcholki, int gestosc)
{
	n = wierzcholki;
	g = (1.0*gestosc) / 100;
	m = g * (n*(n - 1)) / 2;

	waga = new int[n];
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, n - 1);
	for (int i = 0; i < n; i++)
	{
		waga[i] = dis(gen);
	}

	//Tworzenie Tablicy sasiedztwa - kazdy element tablicy to lista
	L = new list<int> *[n];

	for (int i = 0; i < n; i++)
	{
		L[i] = new list<int>;
	}

	Stworz_Liste();
}

void Graf::Stworz_Liste()
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

		L[x]->push_back(y);
		L[y]->push_back(x);

	}
	delete[]S;
}

void Graf::wyswietl_liste()
{
	for (int k = 0; k < n; k++)
	{
		cout << "A[" << k << "] =";
		for (list<int>::iterator i = L[k]->begin(); i != L[k]->end(); ++i)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
}


//Algorytm Dijkstry
void Graf::Dijkstry(int v, char T)
{
	int k, j, u, x;
	
	int s=1;
	int l=0;
	int y=1;

	d = new int [n];
	p = new int [n];
	QS = new bool [n];
	

	//iniciowanie tablic dynamicznych
	for (k = 0; k < n; k++)
	{
		d[k] = MAXINT;
		p[k] = -1;
		QS[k] = false;
	}

	//cout << endl;
	d[v] = 0;  //Koszt dojscia do v (startowy) jest zerowy
	//Wyznaczanie sciezek
	x = 0;
	//for (k = 0; k < n; k++) //po n przejsciach ca³a tablica QS bedzie true
	
		//cout << "algorytm Diskrty" << endl;
		while (!(s == l && y == 0) && x<n)
		{

			s = 0;
			l = 0;
			//szkamy wierzcholka w Q o najmniejszym koszcie d
			//pocz¹tkowo wszystkie po za v maja MAXINT
			for (j = 0; QS[j]; j++);
			for (u = j++; j < n; j++)
				if (!QS[j] && (d[j] < d[u]))
				{
					u = j;
				}

			//znaleziony wierzcholek przenosimy do S

			QS[u] = true;
			y--;	//kazdy nowy odkryty sasiad musi zostac zbadany
			//cout << endl << "u przed =" << u;
			//Modyfikacja wszystkich s¹siadów u którzy s¹ w Q
			if (T == 'l')
			{
				for (list<int>::iterator i = L[u]->begin(); i != L[u]->end(); ++i)
				{
					if (!QS[*i])	//liczy ile nowych sasiadow zostalo odkrytych
					y++;
					l++; //licznik sasiadow danego wierzcholka
					if (QS[*i] ) //Sprawdzenie czy dany sasiad jest w zbiorze S (do których jest znaleziona sciezka)
						s++;
					if (!QS[*i] && (d[*i] > d[u] + waga[*i]))
					{
						//cout << u << " ";
						d[*i] = d[u] + waga[*i]; //przypisanie nowej wagi
						p[*i] = u;	//przypisanie poprzednika
					}
				}

			}

			if (T == 'm')
			{
				//cout<< "A["<< u << "]: ";
				for (k = 0; k < n; k++)	//Przegladanie wiersza danego wierzcholka w celu szukania sasiadow
				{
					//cout << "i = " << k << " ";
					if (M[u][k] == 1)	//dla i ktore sa sasiadami u
					{
						//cout << k << " ";
						if (!QS[k])
						y++;
						l++;	//licznik sasiadow danego wierzcholka
						if (QS[k])
							s++;
						if (!QS[k] && (d[k] > d[u] + waga[k]))
						{
							d[k] = d[u] + waga[k]; //przypisanie nowej wagi
							p[k] = u;	//przypisanie poprzednika
						}
					}
				}
			}
			x++;
		}
	
		//wyswietl_Dijkstry();


		delete[]d;
		delete[]p;
		delete[]QS;
		//delete[]L;
		delete[]waga;
}

void Graf::wyswietl_Dijkstry()
{
	int i, j;
	int sptr=0;
	S = new int[n];
	//Gotowe, wyœwietlamy wyniki
	cout << endl << endl;
	for(i = 0; i < n; i++)
	{
			cout << i << ": ";
			//œciezke przechodzimy od konca ku poczatkowi
			//Zapisujac na stosie kolejne wierzcholki
			//jakbys sie zastanawial o co chodzi to rozrysuj
			//j=p[j] przechodzi od elementu i w dó³ a¿ do elementu pocz¹tkowego
			//gdzie osiagdnie warotsc -1 i przerwie petle
		if (d[i]!=MAXINT)
		{
			for (j = i; j > -1; j = p[j])
			{
				S[sptr++] = j;
			}
			while (sptr)
			{
				cout << S[--sptr] << " ";
			}
			cout << "koszt: " << d[i] << endl;
		}
		else
		{
			cout << i << ": BRAK SCIEZKI"<<endl;
		}
		
	}
	delete[]S;

	delete[]d;
	delete[]p;
	delete[]QS;
	delete[]L;
	delete[]waga;

	cout << endl;
}
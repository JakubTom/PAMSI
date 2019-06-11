
#ifndef SORTOWANIE_H
#define SORTOWANIE_H
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

// TODO: w tym miejscu dodaj nag³ówki, które maj¹ byæ wstêpnie kompilowane

template<typename T>
class Sortowanie
{
private:

public:
//TODO::Funkcje ogolne
	//template<typename T>
	static T* stworz_tablice(int rozmiar,double posortowanie,char typ);
	//template<typename T>
	static bool czy_posortowane(T tablica[],int l,int r);
	//template<typename T>
	static void odwroc(T tablica[], int l, int r);

// TODO: quicksort_beta
	//template<typename T>
	static void quicksort_beta(T tablica[], int p, int r);
	//template<typename T>
	static int podziel_beta(T tablica[], int p, int r);

// TODO: quicksort
	//template<typename T>
	static void quicksort(T tablica[], int p, int r);
	//template<typename T>
	static int podziel(T tablica[], int p, int r);
	//template<typename T>
	static void zmien(T tablica[], int p1, int p2);
	//template<typename T>
	static void MedianOfThree(T tablica[], int p, int r);


// TODO: mergesort
	//template<typename T>
	static void mergesort(T tablica[], T pomocnicza[], int p, int k);
	//template<typename T>
	static void merge(T tablica[],T pomocnicza[], int p, int s, int k);

// TODO: HeapSort
	//template<typename T>
	static void heapSort(T tablica[], int l, int r);
	//template<typename T>
	static void heapify(T tablica[], int l,int r, int i);

// TODO: Introsort
	//template<typename T>
	static void sort(T tablica[], int l, int r);
	//template<typename T>
	static void introsort(T tablica[], int l, int r, int maxdepth);
};

// TODO: quicksort_beta
	template<typename T>
	void Sortowanie<T>::quicksort_beta(T tablica[], int p, int r)
{
	int k;
	if (p < r)
	{
		//podzia³ tablicy na 2 czêsci, k oznacza punkt podzialu
		k = podziel(tablica, p, r);
		//wywolanie quicksort dla pierwszej czesci dablicy
		quicksort(tablica, p, k);
		//wywolanie quicksort dla drugiej czesci tablicy
		quicksort(tablica, k + 1, r);
	}
}

	template<typename T>
	int Sortowanie<T>::podziel_beta(T tablica[], int p, int r)
{
	T x = tablica[p];
	int i = p;
	int j = r;
	T w;
	//petla wykonujaca sie do momentu zwrocenia j
	while (true)
	{
		//dopoki nie znajdzie elementu mniejszego od x
		while (tablica[j] > x)
			j--;
		//dopoki nie znajdzie elementu wiekszego od x
		while (tablica[i] < x)
			i++;
		//jeœli znalaz³o oba elementu i indeksy jeszcze sie nie spotka³y 
		if (i < j)
		{
			//zamiana lementów miejscami
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		//jeœli indeksy tablic sie spotkaja zwraca j jako indeks podzia³ dablicy
		else
			return j;
	}
}

// TODO: quicksort
	template<typename T>
	void Sortowanie<T>::quicksort(T tablica[], int p, int r)
	{
		//w sortowaniu tym element i (czyli indeks podzialu)
		//po wykonanym dzieleniu znajduje sie juz na odpowiedniej pozycji
		//wiec nie trzeba go brac pod uwage w dalszym losowaniu
		int i;
		//wykonuj dopóki fragment bedzie d³u¿szy ni¿ 1 element
		//jesli p=r to bedzie juz 0 elementów
		while(p<r)
		{
			i = podziel(tablica, p, r);
			//sprawdza czy lewa czesc jest krotsza
			if((i-p)<=(r-i))
			{
				//sortowanie lewej, krotszej czesci
				quicksort(tablica, p, i - 1);
				//kontunuacja dzielenia dluzszej czesci bez wywoa³ania rekurencji
				p = i + 1;
			}
			else
			{
				//sortowanie prawej, krotszej czesci
				quicksort(tablica,i+1, r);
				//kontunuacja dzielenia dluzszej czesci bez wywoa³ania rekurencji
				r = i - 1;
			}
		}
	}

	template<typename T>
	int Sortowanie<T>::podziel(T tablica[], int p, int r)
	{
		//jesli we fragmencie sa conajmniej 3 elementy to wykonaj funkcje MedianOfThree
		if((r-p+1)>=3)
		MedianOfThree(tablica, p, r);
		//wybranie elementu,ktory posluzy jako podzial
		int x = p + (r - p) / 2;
		//zapamietanie wartosci podzialu
		T wartosc = tablica[x];
		//przeniesienie elementu podzialu na koniec talicy,aby nie bral udzialu w podziale
		zmien(tablica, x, r);
		
		int aktualna_pozycja = p;
		//iterowanie przez wszystkie elementy,
		//jesli element jest mniejszy niz wartosc elementu podzialu, dodaj go do lewej strony
		for(int i=p;i<=r-1;i++)
		{
			if(tablica[i]<wartosc)
			{
				zmien(tablica, i, aktualna_pozycja);
				aktualna_pozycja++;
			}
		}
		//ustawienie elementu podzialu we wlasciwym miejscu
		zmien(tablica, aktualna_pozycja, r);
		return aktualna_pozycja;
	}

	template<typename T>
	void Sortowanie<T>::zmien(T tablica[], int p1, int p2)
	{
		T w;
		w = tablica[p1];
		tablica[p1] = tablica[p2];
		tablica[p2] = w;
	}

	template<typename T>
	void Sortowanie<T>::MedianOfThree(T tablica[], int p, int r)
	{
		int mid = p + (r - p) / 2;
		if (tablica[r] < tablica[p])
			zmien(tablica, p, r);
		if (tablica[mid] < tablica[p])
			zmien(tablica,mid, p);
		if (tablica[r] < tablica[mid])
			zmien(tablica, r, mid);
		//po wykonaniu operacji mid jest median¹ z trzech wybranych
	}

// TODO: mergesort
	template <typename T>
	void Sortowanie<T>::mergesort(T tablica[], T pomocnicza[], int p, int k)
	{
		int s;
		if(p < k)

		{
			//wyznaczenie srodka tablicy
			s = p + (k -p) / 2;
			//dielenie lewej czesci
			mergesort(tablica,pomocnicza, p, s);
			//dzielenie prawej czesci
			mergesort(tablica,pomocnicza, s + 1, k);
			//laczenie lewej i prawej czesci
			merge(tablica,pomocnicza, p, s, k);
		}
		
	}

	template<typename T>
	void Sortowanie<T>::merge(T tablica[], T pomocnicza[], int p, int s, int k)
{
	int i;
	int j;
	int w;
	
	//skopiowanie elementow do tablicy pomocniczej
	//musi byæ tworzona tutaj aby laczyc juz czesciowo posortowane elementy w kolejnych wywoalaniach rekurencji
	for(i=p;i<=k;i++)
	{
		pomocnicza[i] = tablica[i];
	}
	//ustawienie wskaznikow talic
	i = p;
	j = s+1;
	w = p;
	while(i<=s && j<=k)
	{
		//gdy element ze zbioru pierwszego jet mniejszy 
		if (pomocnicza[i] < pomocnicza[j])
			tablica[w++] = pomocnicza[i++];
		//gdy element ze zbioru pierwszego NIE jet mniejszy
		//(wtedy kolejny jest element z drugiego zbioru)
		else
			tablica[w++] = pomocnicza[j++];
	}
	//przeniesie dane ze zbioru pierwszego w przypadku gdy drugi sie skonczy
	while(i<=s)
	{
		tablica[w++] = pomocnicza[i++];
	}
	
}

// TODO: HeapSort
	template<typename T>
	void Sortowanie<T>::heapSort(T tablica[], int l, int r)
	{
		//stworzenie odpowiedniego stosu w którym ga³eŸ matka,
		//ma mieæ co najwy¿ej 2 odga³êzienia o wartoœci < galeŸ matka
		for(int i=(r+1+l)/2-1;i>=l;i--)
		{
			//na miejscu i(ga³êzi matka) ma byæ najwieksza wartoœæ, na samej górze bêdzie najwiêksza wartoœæ
			heapify(tablica, l,r+1, i);
			//r jest ograniczeniem aby nie odwo³aæ siê do nieistniej¹cego elementu talicy
			
		}

		//przenoszenie pokolei elementu l (na samej górze) na koniec tablicy
		//element ten nie bêdze ju¿ podlega³ dalszemu sortowaniu
		for(int i=r;i>=l;i--)
		{
			//przesuñ najwiêkszy element z miejsca l na koniec
			zmien(tablica, l, i);

			//na miejscu ga³êzi l ma byæ najwiêksza wartoœæ
			heapify(tablica,l, i, l);
			//i jest ograniczeniem aby nie odwo³aæ siê do nieistniej¹cego elementu talbicy
			//ani do elementów które s¹ ju¿ posortowane i od³o¿one na koniec tablicy

		}
	}

	template<typename T>
	void Sortowanie<T>::heapify(T tablica[],int l, int r, int i)
	{
		int largest = i; //na miejscu i ma byæ najwiêkszy element
		int l_child = 2 * (i-l) + 1 + l; //left = 2*i +1
		int r_child = 2 * (i-l) + 2 + l; //right = 2*i +2

		//w poni¿szych if jest sprawdzane czy indeks nie wykracza po za górn¹ granice tablicy r
		//nie jest konieczne sprawdzanie dolnej l poniewa¿
		//nigdy nie zostanie utowrzony taki indeks l_child lub r_child
		//jeœli lewe dziecko jest wieksze zamieñ
		if(l_child < r && tablica[l_child] > tablica[largest])
		{
			largest = l_child;
		}

		//jeœli prawe dziecko jest wieksze zamieñ
		if (r_child < r && tablica[r_child] > tablica[largest])
		{
			largest = r_child;
		}

		//jeœli indeks najwiêkszego elementu by³ zmieniony czyli != pocz¹tkowemu i
		if(largest!= i)
		{
			//wtedy zamien je miejscami
			zmien(tablica, i, largest);

			//oraz spawdz czy na miejscu w którym by³ najwiêkszy element(largest)
			//stoi element który nadal jest wiêkszy od swoich dzieci, i tak dalej
			//potrzebne aby nie drzewo by³o o³o¿one w odpowiedni sposób
			heapify(tablica,l, r, largest);
		}

	}

// TODO: Introsort
	template<typename T>
	void Sortowanie<T>::sort(T tablica[], int l, int r)
	{
		int maxdepth = 2 * log(r + 1 - l);
		introsort(tablica, l, r, maxdepth);
	}

	template<typename T>
	void Sortowanie<T>::introsort(T tablica[], int l, int r, int maxdepth)
	{
		int n = r + 1 - l;
		int p = podziel(tablica, l, r);

		if(n<=1)
		{
			return;
		}
		else if(maxdepth==0)
		{
			heapSort(tablica, l, r);
		}
		else
		{
			introsort(tablica,l,p-1,maxdepth-1);
			introsort(tablica,p+1,r,maxdepth-1);
		}
	}

//TODO::Funkcje ogolne
	template<typename T>
	T* Sortowanie<T>::stworz_tablice(int rozmiar, double posortowanie,char typ)
	{
		int r = posortowanie * rozmiar;
		T* tablica = new T[rozmiar];
		//cout << "sortuj do" << r << endl;
		//generowanie losowych liczb
		random_device rd;  //Will be used to obtain a seed for the random number engine
		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		uniform_int_distribution<> dis(0, 10000);
		
		for (int i = 0; i < rozmiar; i++)
		{
			tablica[i] = dis(gen);
			//cout << "tablica[" << i << "]=" << tablica[i] << endl;
		}
	
		if (typ == 'o')
		{
			//posortowanie tablicy
			sort(tablica, 0, rozmiar-1);
			//odwrocenie tablicy
			odwroc(tablica, 0, rozmiar - 1);	
		}
		
		if(posortowanie!=0)
		sort(tablica, 0, r - 1);
		return tablica;;
	}

	template<typename T>
	bool Sortowanie<T>::czy_posortowane(T tablica[], int l, int r)
	{
		//sprawdza czy tablica jest posortowana rosnaco
		for(int i=0;i<=r-1;i++)
		{
			if (tablica[i] > tablica[i + 1])
			{
				cout << "element " << i << "oraz " << i+1 << " sa zle posortowane" << endl;
				return 0;
			}
				
		}
		return 1;
	}

	template<typename T>
	void Sortowanie<T>::odwroc(T tablica[], int l, int r)
	{
		int i = l + (r + 1 - l) / 2;
		for(i;i>0;i--)
		{
			zmien(tablica,l,r);
			l++;
			r--;
		}
	}

#endif //SORTOWANIE_H

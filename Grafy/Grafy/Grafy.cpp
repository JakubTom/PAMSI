// Grafy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	char T;
	//int v;
	int Ilosc_Grafow=100;
	int wierzcholki;
	int gestosc;

	Graf G;
	//G.Inicjalizuj_Macierz(5, 30);
	//G.wyswietl_dane();
	//G.Wyswietl_Macierz();
	//G.wyswietl_krawedzie();

	//G.Inicjalizuj_Liste(5, 30);
	//G.wyswietl_dane();
	//G.wyswietl_liste();

	//G.Dijkstry(0,'l');
	//G.wyswietl_Dijkstry();


	//cout << "Ile grafow stworzyc?: " << endl;
	//cin >> Ilosc_Grafow;
	cout << "Ilosc wierzcholkow w kazdym grafie: " << endl;
	cin >> wierzcholki;
	cout << "Gestosc stworzonych Grafow: " << endl;
	cin >> gestosc;
	//cout << "Podaj wierzcholek poczatkowy: " << endl;
	//cin >> v;

	cout << "Podaj Typ reprezentacji grafu: " << endl;
	cout << "l - Lista sasiedztwa" << endl;
	cout << "m -Macierz sasiedztwa" << endl;
	cin >> T;

	//funkcje mierzące czas
	auto start = chrono::high_resolution_clock::now();
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	//cout << "Czas sortowania przed : " << duration.count() << "mikrosekund" << endl;
	for (int j = 0; j<Ilosc_Grafow; j++)
	{
		//cout << "Petla nr" << j << endl;
		switch (T)
		{
		case 'l':
			G.Inicjalizuj_Liste(wierzcholki, gestosc);
			start = chrono::high_resolution_clock::now();
			G.Dijkstry(0, T);
			stop = chrono::high_resolution_clock::now();
			break;

		case 'm':
			G.Inicjalizuj_Macierz(wierzcholki, gestosc);
			start = chrono::high_resolution_clock::now();
			G.Dijkstry(0, T);
			stop = chrono::high_resolution_clock::now();
			break;

		default:
			cout << "Niepoprawnie wybrana opcja" << endl;
			break;

		}
		duration += chrono::duration_cast<chrono::microseconds>(stop - start);
		
	}
	
	cout << "Czas: " << duration.count() << "milisekund" << endl;

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include "pch.h"
#include <iostream>
#include <chrono>
//#include <cstdlib>
//#include <ctime>
using namespace std;

//funckja dzielaca tablice na dwie czesci, w pierwszj wszystkie liczby sa mniejssze badz rowne x,
//w drugiej wieksze badz rowne x.


int main()
{
	//srand(time(NULL));
	int rozmiar;
	double posortowanie;
	int Ilosc_Tablic;
	int i;
	char typ;
	char rodzaj_sortowania;
	cout << "Podaj ilosc liccb do posortowania: ";
	cin >> rozmiar;
	cout << "Podaj ilosc tablic ktore maja zostac poddane sortowaniu ";
	cin >> Ilosc_Tablic;
	cout << "Podaj w ilu procentach maja byc posortowane generowane tablice: ";
	cin >> posortowanie;
	cout << "Podaj typ wygenerowanej tablicy: " << endl;
	cout << "l - losowa" << endl;
	cout << "o - w odwrotnej kolejnosci" << endl;
	cin >> typ;
	posortowanie = posortowanie / 100;
	int l = posortowanie * rozmiar;
	cout << "Wybierz rodziaj sortowanie z ponizszych: " << endl;
	cout << "q - quicksort" << endl;
	cout << "m - mergesort" << endl;
	cout << "i - introsort" << endl;
	cin >> rodzaj_sortowania;

	int *pomocnicza = new int[rozmiar];

	auto start = chrono::high_resolution_clock::now();
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	//cout << "Czas sortowania przed : " << duration.count() << "mikrosekund" << endl;
	for (int j = Ilosc_Tablic; j > 0; j--)
	{
		int *tablica = Sortowanie<int>::stworz_tablice(rozmiar, posortowanie,typ);
		
		switch (rodzaj_sortowania)
		{
		case 'q':
			start = chrono::high_resolution_clock::now();
			Sortowanie<int>::quicksort(tablica, 0, rozmiar - 1);
			stop = chrono::high_resolution_clock::now();
			break;

		case 'm':
			//for (i = 0; i < +rozmiar; i++)
			//{
			//	pomocnicza[i] = tablica[i];
			//}
			start = chrono::high_resolution_clock::now();
			Sortowanie<int>::mergesort(tablica, pomocnicza, 0, rozmiar - 1);
			stop = chrono::high_resolution_clock::now();
			break;
			
		case 'i':
			start = chrono::high_resolution_clock::now();
			Sortowanie<int>::sort(tablica, 0, rozmiar - 1);
			//Sortowanie<int>::heapSort(tablica,0, rozmiar - 1);
			stop = chrono::high_resolution_clock::now();
			break;
		default:
			cout << "Niepoprawnie wybrany rodzaj sortowania" << endl;
			break;

		}
		duration += chrono::duration_cast<chrono::milliseconds>(stop - start);
		//cout << "Czas sortowania nr " <<Ilosc_Tablic-j<<"wynosi:"<< duration.count() << "mikrosekund" << endl;
		if (!Sortowanie<int>::czy_posortowane(tablica, 0, rozmiar - 1))
			cout << "tablica zostala zle posortowana";

		delete[] tablica;
	}
	delete[] pomocnicza;
	cout << "Czas sortowania: " << duration.count() << "milisekund" << endl;

	//auto start = chrono::high_resolution_clock::now();
	//auto stop = chrono::high_resolution_clock::now();
	//auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	//cout << "Czas sortowania: " << duration.count() << "mikrosekund" << endl;

	//Sortowanie<int>::quicksort_beta(tablica,0 , rozmiar - 1);
	//Sortowanie<int>::heapSort(tablica, 0, rozmiar - 1);
	
	
	//for(i=0;i< rozmiar;i++)
	//{
	//	cout << "tablica[" << i << "]=" << tablica[i] << endl;
	//}
	
	
	return 0;

    //cout << "Hello World!\n"; 
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

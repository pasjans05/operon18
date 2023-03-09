// operon18.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
using namespace std;

ifstream plik("trzyliczby.txt");

unsigned long long int XtoDEC(int n, string a)
{
	char b;
	int bb = 0;
	unsigned long long int dec = 0;
	int j = 0;
	for (int i = a.length()-1; i >= 0; i--)
	{
		b = a[i];
		bb = 0;
		switch (b)
		{
			case '1':
				bb = 1;
				break;
			case '2': 
				bb = 2;
				break;
			case '3': 
				bb = 3;
				break;
			case '4': 
				bb = 4;
				break;
			case '5': 
				bb = 5;
				break;
			case '6': 
				bb = 6;
				break;
			case '7': 
				bb = 7;
				break;
			case '8': 
				bb = 8;
				break;
			case '9': 
				bb = 9;
				break;
			case 'A': 
				bb = 10;
				break;
			case 'B': 
				bb = 11;
				break;
			case 'C': 
				bb = 12;
				break;
			case 'D': 
				bb = 13;
				break;
			case 'E': 
				bb = 14;
				break;
			case 'F': 
				bb = 15;
				break;
		}
		dec += bb*pow(n, j);
		j++;
	}
	return dec;
}

bool sysSpr(string a, string b, string c, int n)
{
	unsigned long long int DECa = XtoDEC(n, a);
	unsigned long long int DECb = XtoDEC(n, b);
	unsigned long long int DECc = XtoDEC(n, c);
	if (DECa + DECb == DECc) return true;
	else return false;
}

void Jeden()
{
	int SYS[15]{};
	for (int i = 0; i < 15; i++) SYS[i] = 0;
	string a;
	string b;
	string c;
	for (int i = 0; i < 100; i++)
	{
		plik >> a >> b >> c;
		for (int i = 2; i <= 16; i++)
		{
			if (sysSpr(a, b, c, i)) SYS[i - 2]++;
			//cout << a << "\t" << b << "\t" << c << "\t" << XtoDEC(i, a) << " + " << XtoDEC(i, b) << " = " << XtoDEC(i, c) << "\t" << sysSpr(a, b, c, i) << "\t" << i << endl;
		}
	}
	for (int i = 0; i < 15; i++) cout << "System " << i + 2 << ": \t" << SYS[i] << endl;
}

int main()
{
	Jeden();
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

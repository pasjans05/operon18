// operon18.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
using namespace std;

ifstream plik("trzyliczby.txt");

long int XtoDEC(int n, string a)
{
	char b;
	long long int dec = 0;
	int j = 1;
	for (int i = a.length(); i > 0; i--)
	{
		b = a[i];
		if (b == 'A') b = 10;
		if (b == 'B') b = 11;
		if (b == 'C') b = 12;
		if (b == 'D') b = 13;
		if (b == 'E') b = 14;
		if (b == 'F') b = 15;
		dec += b*pow(n, j);
		j++;
	}
	return dec;
}

bool sysSpr(string a, string b, string c, int n)
{
	long long int DECa = XtoDEC(n, a);
	long long int DECb = XtoDEC(n, b);
	long long int DECc = XtoDEC(n, c);
	if (DECa + DECb == DECc) return true;
	else return false;
}

void Jeden()
{
	int SYS[15];
	for (int i = 0; i <= 14; i++) SYS[i] = 0;
	string a;
	string b;
	string c;
	for (int i = 0; i < 100; i++)
	{
		plik >> a >> b >> c;
		for (int i = 2; i <= 16; i++)
		{
			if (sysSpr(a, b, c, i)) SYS[i - 2] += 1;
		}
	}
	for (int i = 0; i <= 14; i++)
	{
		cout << "System " << i + 2 << ": \t" << SYS[i] << endl;
	}
}

int main()
{
	/*string a;
	string b;
	string c;
	for (int i = 0; i < 100; i++)
	{
		plik >> a >> b >> c;
		cout << a << "\t" << b << "\t" << c << endl;
	}*/
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

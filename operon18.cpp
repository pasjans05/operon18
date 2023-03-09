// operon18.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream plik("trzyliczby.txt");

float ZNAK[15];

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
		if (n <= bb)
		{
			return 1;
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
	int max;
	int min;
	for (int i = 0; i < 100; i++)
	{
		plik >> a >> b >> c;
		for (int j = 2; j <= 16; j++)
		{
			if (sysSpr(a, b, c, j))
			{
				SYS[j - 2]++;
				if (i == 0)
				{
					max = XtoDEC(j, a);
					min = max;
				}
				if (XtoDEC(j, a) > max) max = XtoDEC(j, a);
				if (XtoDEC(j, b) > max) max = XtoDEC(j, b);
				if (XtoDEC(j, c) > max) max = XtoDEC(j, c);
				if (XtoDEC(j, a) < min) min = XtoDEC(j, a);
				if (XtoDEC(j, b) < min) min = XtoDEC(j, b);
				if (XtoDEC(j, c) < min) min = XtoDEC(j, c);
				break;
			}
		}
	}
	plik.close();
	plik.open("trzyliczby.txt");
	for (int i = 0; i < 15; i++) cout << "System " << i + 2 << ": \t" << SYS[i] << endl;
	cout << endl << "Największa wartość: " << max << endl << "Najmniejsza wartość: " << min << endl;
}

void Znaki(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		int b = a[i];
		switch (b)
		{
		case '0':
			ZNAK[0]++;
			break;
		case '1':
			ZNAK[1]++;
			break;
		case '2':
			ZNAK[2]++;
			break;
		case '3':
			ZNAK[3]++;
			break;
		case '4':
			ZNAK[4]++;
			break;
		case '5':
			ZNAK[5]++;
			break;
		case '6':
			ZNAK[6]++;
			break;
		case '7':
			ZNAK[7]++;
			break;
		case '8':
			ZNAK[8]++;
			break;
		case '9':
			ZNAK[9]++;
			break;
		case 'A':
			ZNAK[10]++;
			break;
		case 'B':
			ZNAK[11]++;
			break;
		case 'C':
			ZNAK[12]++;
			break;
		case 'D':
			ZNAK[13]++;
			break;
		case 'E':
			ZNAK[14]++;
			break;
		case 'F':
			ZNAK[15]++;
			break;
		}
	}
}

void Trzy()
{
	for (int i = 0; i < 16; i++) ZNAK[i] = 0;
	int sum = 0;
	string a;
	string b;
	string c;
	for (int i = 0; i < 100; i++)
	{
		plik >> a >> b >> c;
		sum += a.length() + b.length() + c.length();
		Znaki(a);
		Znaki(b);
		Znaki(c);
	}
	plik.close();
	for (int i = 0; i < 16; i++)
	{
		ZNAK[i] *= 100;
		ZNAK[i] /= sum;
		if (ZNAK[i] >= 10) cout << setprecision(4);
		else if (ZNAK[i] >= 1) cout << setprecision(3);
		else if (ZNAK[i] < 1) cout << setprecision(2);
		if (i < 10) cout << i << ":\t" << ZNAK[i] << "%\n";
		switch (i)
		{
		case 10:
			cout << "A:\t" << ZNAK[i] << "%\n";
			break;
		case 11:
			cout << "B:\t" << ZNAK[i] << "%\n";
			break;
		case 12:
			cout << "C:\t" << ZNAK[i] << "%\n";
			break;
		case 13:
			cout << "D:\t" << ZNAK[i] << "%\n";
			break;
		case 14:
			cout << "E\t" << ZNAK[i] << "%\n";
			break;
		case 15:
			cout << "F\t" << ZNAK[i] << "%\n";
		}
	}
}

int main()
{
	Jeden();
	Trzy();
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

// SDiZO3.cpp : Defines the entry point for the console application.
//
//Nothing yet

#include "stdafx.h"




void knapsackMenu()
{
	cout << "Menu problemu plecakowego, wybor rozwiazania:" << endl
		<< "1 - Algorytm aproksymacyjny, wersja zachlanna." << endl
		<< "2 - Przeglad zupelny" << endl
		<< "c - Czysc ekran. " << endl
		<< "ESC - Wyjdz." << endl;

	char decision;
	do
	{
		decision = _getch();

		switch (decision)
		{
		case '1':
			break;
		case '2':
			break;
		case 'c':
			system("CLS");
			cout << "Menu problemu plecakowego, wybor rozwiazania:" << endl
				<< "1 - Algorytm aproksymacyjny, wersja zachlanna." << endl
				<< "2 - Przeglad zupelny" << endl
				<< "c - Czysc ekran. " << endl
				<< "ESC - Wyjdz." << endl;
			break;
		case 27:
			cout << "Opuszczono menu problemu plecakowego. \n Menu Glowne:" << endl;
			break;

		}
	} while (decision != 27);

}

void salesmanMenu()
{
	cout << "Menu problemu komiwojazera, wybor rozwiazania:" << endl
		<< "1 - " << endl
		<< "2 - Przeglad zupelny" << endl
		<< "c - Czysc ekran. " << endl
		<< "ESC - Wyjdz." << endl;

	char decision;
	do
	{
		decision = _getch();

		switch (decision)
		{
		case '1':
			break;
		case '2':
			break;
		case 'c':
			system("CLS");
			cout << "Menu problemu komiwojazera, wybor rozwiazania:" << endl
				<< "1 - " << endl
				<< "2 - Przeglad zupelny" << endl
				<< "c - Czysc ekran. " << endl
				<< "ESC - Wyjdz." << endl;
			break;
		case 27:
			cout << "Opuszczono menu komiwojazera. \n Menu Glowne:" << endl;
			break;

		}
	} while (decision != 27);

}

void mainMenu()
{
	cout << "Menu glowne, wybor problemu:" << endl
		<< "1 - Problem plecakowy." << endl
		<< "2 - Problem komiwojazera." << endl
		<< "c - Czysc ekran. " << endl
		<< "ESC - Wyjdz." << endl;

	char decision;
	do
	{
		decision = _getch();

		switch (decision)
		{
		case '1':
			//Dodaæ wczytywanie danych z pliku
			knapsackMenu();
			break;
		case '2':
			//Dodaæ wczytywanie danych z pliku
			salesmanMenu();
			break;
		case 'c':
			system("CLS");
			cout << "Menu glowne, wybor problemu:" << endl
				<< "1 - Problem plecakowy." << endl
				<< "2 - Problem komiwojazera." << endl
				<< "c - Czysc ekran. " << endl
				<< "ESC - Wyjdz." << endl;
			break;
		case 27:
			break;

		}
	} while (decision != 27);

}

int main()
{

	mainMenu();
	system("PAUSE");
    return 0;
}


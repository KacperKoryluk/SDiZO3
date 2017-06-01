// SDiZO3.cpp : Defines the entry point for the console application.
//
//Nothing yet

#include "stdafx.h"

Algorithm *_currentAlgorithm;
string fileName;

void knapsackMenu()
{
	cout << "Menu problemu plecakowego, wybor rozwiazania:" << endl
		<< "1 - Algorytm aproksymacyjny, wersja zachlanna." << endl
		<< "2 - Przeglad zupelny" << endl
		<< "3 - Wyswietl dane pobrane z pliku" << endl
		<< "c - Czysc ekran. " << endl
		<< "ESC - Wyjdz." << endl;

	char decision;
	do
	{
		decision = _getch();

		switch (decision)
		{
		case '1':
			_currentAlgorithm->greedyAlgorithm();
			break;
		case '2':
			_currentAlgorithm->bruteforce();
			break;
		case '3':
			_currentAlgorithm->print();
			break;
		case 'c':
			system("CLS");
			cout << "Menu problemu plecakowego, wybor rozwiazania:" << endl
				<< "1 - Algorytm aproksymacyjny, wersja zachlanna." << endl
				<< "2 - Przeglad zupelny" << endl
				<< "3 - Wyswietl dane pobrane z pliku" << endl
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
		<< "1 - Najbli¿szy s¹siad" << endl
		<< "2 - Przeglad zupelny" << endl
		<< "3 - Wyswietl dane pobrane z pliku" << endl
		<< "c - Czysc ekran. " << endl
		<< "ESC - Wyjdz." << endl;

	char decision;
	do
	{
		decision = _getch();

		switch (decision)
		{
		case '1':
			_currentAlgorithm->greedyAlgorithm();
			break;
		case '2':
			_currentAlgorithm->bruteforce();
			break;
		case '3':
			_currentAlgorithm->print();
			break;
		case 'c':
			system("CLS");
			cout << "Menu problemu komiwojazera, wybor rozwiazania:" << endl
				<< "1 - " << endl
				<< "2 - Przeglad zupelny" << endl
				<< "3 - Wyswietl dane pobrane z pliku" << endl
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
			_currentAlgorithm = new KnapsackProblem();
			cout << "Nazwa pliku z danymi: " << endl;
			cin >> fileName;
			if (_currentAlgorithm->loadFromFile(fileName))
			{
				knapsackMenu();

				delete _currentAlgorithm;
			}
			else cout << "Operacja nie powiodla sie! Nie znaleziono pliku." << endl;
			break;
		case '2':
			_currentAlgorithm = new SalesmanProblem();
			cout << "Nazwa pliku z danymi: " << endl;
			cin >> fileName;
			if (_currentAlgorithm->loadFromFile(fileName))
			{
				salesmanMenu();

				delete _currentAlgorithm;
			}
			else cout << "Operacja nie powiodla sie! Nie znaleziono pliku." << endl;
			
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


#include "stdafx.h"
#include "SalesmanProblem.h"


SalesmanProblem::SalesmanProblem()
{
}


SalesmanProblem::~SalesmanProblem()	//Uwa¿aæ tutaj
{
	for (int i = 0; i < amountOfCities; i++)
	{
		delete[] distanceMatrix[i];
	}
	delete[] distanceMatrix;
}

bool SalesmanProblem::loadFromFile(std::string fileName)
{
	fstream file;
	file.open(fileName, ios::in);

	if (file.is_open())
	{
		if (file.fail())
		{
			return false;
		}
		file >> amountOfCities;
		distanceMatrix = new int*[amountOfCities];
		for (int i = 0; i < amountOfCities; i++)
		{
			distanceMatrix[i] = new int[amountOfCities];
		}

		for (int i = 0; i < amountOfCities; i++)
		{
			for (int j = 0; j < amountOfCities; j++)
			{
				file >> distanceMatrix[i][j];
			}
		}

	}
	else
	{
		return false;
	}

	file.close();
	return true;
}

void SalesmanProblem::greedyAlgorithm()
{
	int *visited = new int[amountOfCities]; //visited, 1 oznacza odwiedzono, 0 - miasto nie by³o odwiedzone
	vector<int> bestRoute;
	int totalCost = 0;
	for (int i = 0; i < amountOfCities; i++)
	{
		visited[i] = 0;
	}

	int start = 0; //Przyjmujê pierwsze miasto jako punkt startowy i koñcowy podró¿y
	pair <int, int> tempClosestCity; // Tymczasowe najbli¿sze miasto, <odleg³oœæ, indeks>
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > tempRouteQueue; //Kolejka dróg, wybiera najkrótsz¹ <Koszt, Miasto docelowe>
	int currentCity = start; //Aktualnie odwiedzane miasto
	bestRoute.push_back(start); //Umieszczam punkt startowy w œcie¿ce
	visited[start] = 1; 
	
	for (int i = 0; i < amountOfCities-1; i++)
	{
		for (int j = 0; j < amountOfCities; j++)
		{
			if (visited[j]==0)
			tempRouteQueue.push(make_pair(distanceMatrix[i][j], j));
			
		}
		tempClosestCity = tempRouteQueue.top(); //Wyci¹gam z kolejki miasto o najmniejszym koszcie dotarcia
		totalCost += tempClosestCity.first; 
		bestRoute.push_back(tempClosestCity.second);
		visited[tempClosestCity.second] = 1;
		currentCity = tempClosestCity.second; //"Idê" do miasta o najmniejszym koszcie

		while (tempRouteQueue.size() >= 1)
		{
			tempRouteQueue.pop();
		}
		
	}
			
	totalCost += distanceMatrix[amountOfCities - 1][0]; // Dodajê koszt dojœcia do pierwszego miasta
	bestRoute.push_back(start); // Dodajê numer pierwszego wierzcho³ka

	//Wyœwietlanie

	cout << "Koszt podrozy: " << totalCost << endl;
	cout << "Droga: " << endl;
	for (int z = 0; z < amountOfCities; z++)
	{
		cout << bestRoute[z] << " --> ";
	}
	cout << bestRoute[amountOfCities];
	cout << endl;

	delete[] visited;
}

void SalesmanProblem::bruteforce() //Permutacje wszystkich œcie¿ek
{
	int *cities = new int[amountOfCities]; //Tablica miast
	int tempCost = 0;
	int bestCost = 0;
	int *bestRoute = new int[amountOfCities];
	for (int i = 0; i < amountOfCities; i++)
	{
		cities[i] = i;
	}

	sort(cities, cities+amountOfCities);

	do
	{
		tempCost = 0;
		for (int i = 0; i < amountOfCities-1; i++)
		{
			tempCost += distanceMatrix[i][i + 1];
		}
		tempCost += distanceMatrix[amountOfCities - 1][0];

		if (tempCost < bestCost || bestCost == 0)
		{
			bestCost = tempCost;
			for (int i = 0; i < amountOfCities; i++)
			{
				bestRoute[i] = cities[i];
			}
		}

	} while (next_permutation(cities, cities + amountOfCities));
	

	//Wyœwietlanie


	cout << "Koszt: " << bestCost << endl << "Najlepsza droga: " << endl;
	for (int i = 0; i < amountOfCities; i++)
	{
		cout << bestRoute[i] << " --> ";
	}
	cout << "0" << endl;

	delete[] cities;
	delete[] bestRoute;
}

void SalesmanProblem::print()
{
	cout << "Ilosc miast: " << amountOfCities << endl;

	cout << setw(4) << "  ";
	for (int i = 0; i < amountOfCities; i++)
	{
		cout << setw(3) << " | " << setw(3) << i;
	}
	cout << setw(3) << " | " << endl;
	for (int i = 0; i < amountOfCities; i++)
	{
		cout << i << setw(3) << "|";
		for (int j = 0; j < amountOfCities; j++)
		{
			
				cout << setw(3) << " : " << setw(3) << distanceMatrix[i][j];
			
			
		}
		cout << setw(3) << " : " << endl;
	}
}

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
}

void SalesmanProblem::bruteforce()
{
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

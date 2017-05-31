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

}

void SalesmanProblem::greedyAlgorithm()
{
}

void SalesmanProblem::bruteforce()
{
}

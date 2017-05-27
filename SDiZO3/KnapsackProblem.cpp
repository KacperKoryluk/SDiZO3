#include "stdafx.h"
#include "KnapsackProblem.h"


KnapsackProblem::KnapsackProblem()
{
}


KnapsackProblem::~KnapsackProblem()
{
}

bool KnapsackProblem::loadFromFile(std::string fileName)	//Zweryfikowaæ poprawnoœæ
{
	fstream file;
	file.open(fileName, ios::in);

	if (file.is_open())
	{
		if (file.fail())
		{
			return false;
		}
		file >> knapsackCapacity;
		file >> amountOfItems;

		int itemTempdata[2];
		for (int i = 0; i < amountOfItems; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				file >> itemTempdata[j];
			}
			
			items.push_back(make_pair(itemTempdata[1], itemTempdata[0]));

		}

	}
	else
	{
		return false;
	}

	file.close();
}

void KnapsackProblem::greedyAlgorithm()
{
}

void KnapsackProblem::bruteforce()
{
}

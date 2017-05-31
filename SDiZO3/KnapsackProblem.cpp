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

void KnapsackProblem::greedyAlgorithm() //Sprawdziæ poprawnoœæ na zbiorze tesotwym
{
	priority_queue <pair<pair <double, int>, pair<int,int>>> *itemQueue = new priority_queue<pair<pair <double, int>, pair<int, int>>>(); //Para par. Struktura <<Stosunek cena/waga, oryginalny indeks> <waga, cena>>
	int currentWeight = 0;
	int currentValue = 0;
	int *itemSet = new int[amountOfItems];

	for (int i = 0; i < amountOfItems; i++)
	{
	
		itemQueue->push(make_pair(make_pair((items[i].second / items[i].first), i), items[i]));
		itemSet[i] = 0;
	}

	pair<pair <double, int>, pair<int, int>> tempItem;
	while (!itemQueue->empty())
	{
		tempItem = itemQueue->top();
		if (tempItem.second.first + currentWeight <= knapsackCapacity)
		{
			itemSet[tempItem.first.second] = 1;
			currentWeight = tempItem.second.first;
			currentValue = tempItem.second.second;
		}

		itemQueue->pop();
	}

	//Wyœwietliæ current weight, current value i itemSet

}

void KnapsackProblem::bruteforce()	//Sprawdziæ poprawnoœæ na zbiorze testowym
{
	int *weights = new int[amountOfItems];
	int *values = new int[amountOfItems];
	int *tempItemSet = new int[amountOfItems];
	
	int bestWeight = 0;
	int bestValue = 0;
	int *bestItemSet;

	for (int i = 0; i < amountOfItems; i++)
	{
		weights[i] = items[i].first;
		values[i] = items[i].second;
		tempItemSet[i] = 0;
	}

	int tempWeight;
	int tempValue;
	int j;

	for (int i = 0; i < 2 ^ amountOfItems; i++)
	{
		j = amountOfItems;
		tempWeight = 0;
		tempValue = 0;

		while (tempItemSet[j] != 0 && j >= 0)
		{
			tempItemSet[j] = 0;
			j--;
		}
		tempItemSet[j]++;

		for (int k = 0; k < amountOfItems; k++)
		{
			if (tempItemSet[k] == 1)
			{
				tempWeight = tempWeight + weights[k];
				tempValue = tempValue + values[k];
			}

			if (tempValue > bestValue && tempWeight <= knapsackCapacity)
			{
				bestValue = tempValue;
				bestWeight = tempWeight;
				bestItemSet = tempItemSet;
			}
		}
	}
	//Dodaæ wyœwietlanie wyników. Bestweight, bestvalue, bestitemset

	delete[] weights;
	delete[] values;
	delete[] tempItemSet;
}

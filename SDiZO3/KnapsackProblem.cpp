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
			
			items.push_back(make_pair(itemTempdata[0], itemTempdata[1]));

		}

	}
	else
	{
		return false;
	}

	file.close();

	

	return true;
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
			currentWeight += tempItem.second.first;
			currentValue += tempItem.second.second;
		}

		itemQueue->pop();
	}

	//Wyœwietliæ current weight, current value i itemSet

	cout << "Wartosc: " << currentValue << endl << "Waga/Pojemnosc: " << currentWeight << "/" << knapsackCapacity << endl;

	cout << "Zestaw: " << endl;

	for (int i = 0; i < amountOfItems; i++)
	{
		if (itemSet[i] == 1)
		{
			cout << "Wybrano: " << i << endl;
		}
		if (itemSet[i] == 0)
		{
			cout << "Odrzucono: " << i << endl;
		}
	}


	delete[] itemSet;
}




void KnapsackProblem::bruteforce()	//Sprawdziæ poprawnoœæ na zbiorze testowym
{
	int overflow = 0; //Sprawdza, czy osi¹gniêto wszystkie kombinacje
	 
	int *weights = new int[amountOfItems];
	int *values = new int[amountOfItems];
	int *tempItemSet = new int[amountOfItems];
	int *sum = new int[amountOfItems]; //Suma pozycyjna

	
	int bestWeight = 0;
	int bestValue = 0;
	int *bestItemSet = new int[amountOfItems];

	for (int i = 0; i < amountOfItems; i++)
	{
		weights[i] = items[i].first;
		values[i] = items[i].second;
		tempItemSet[i] = 0;
		bestItemSet[i] = 0;
	}

	int tempWeight=0;
	int tempValue=0;
	int j = 0;
	int c = 0; //Wartoœæ przeniesienia na kolejn¹ pozycjê
	
	while (overflow == 0)
	{

		c = 1; //Ustawiam wartoœæ przeniesienia na jeden
		for (int i = 0; i < amountOfItems; i++) //Ka¿dy przebieg pêtli to dodawanie 1 do liczby binarnej - interpretacji tablicy wybranych przedmiotów
		{
			

			if (tempItemSet[i] + c < 2)
			{
				sum[i] = tempItemSet[i] + c;
				c = 0;
			}
			if (tempItemSet[i] + c >= 2)
			{
				sum[i] = tempItemSet[i] + c - 2;
				c = 1;
				if (i == amountOfItems - 1)
				{
					overflow = 1;
				}
			}
		}

		if (overflow == 0)
		{
			for (int i = 0; i < amountOfItems; i++)
			{
				tempItemSet[i] = sum[i];
			}

			for (int i = 0; i < amountOfItems; i++)
			{
				if (tempItemSet[i] == 1)
				{
					tempValue += values[i];
					tempWeight += weights[i];
				}
			}

			if (tempValue > bestValue && tempWeight <= knapsackCapacity)
			{
				bestValue = tempValue;
				bestWeight = tempWeight;

				for (int i = 0; i < amountOfItems; i++)
				{
					bestItemSet[i] = tempItemSet[i];
				}
			}
			tempWeight = 0;
			tempValue = 0;

			
		}

		
	}

	



	//Wyœwietlanie

	cout << "Wartosc: " << bestValue << endl << "Waga/WagaCalkowita: " << bestWeight << "/" << knapsackCapacity << endl << "Zestaw: " << endl;
	for (int i = 0; i < amountOfItems; i++)
	{
		if (bestItemSet[i] == 1)
		{
			cout << "Wybrano:" << i << endl;
		}
		if (bestItemSet[i] == 0)
		{
			cout << "Odrzucono:" << i << endl;
		}

	}

	delete[] weights;
	delete[] values;
	delete[] sum;
	delete[] bestItemSet;
	delete[] tempItemSet;
}

void KnapsackProblem::print()
{
	cout << "Pojemnosc: " << knapsackCapacity << " Ilosc przedmiotow: " << amountOfItems << endl;

	cout << "Waga -- Wartosc" << endl;
	for (int i = 0; i < amountOfItems; i++)
	{
		cout << items[i].first << " -- " << items[i].second << endl;
	}
}

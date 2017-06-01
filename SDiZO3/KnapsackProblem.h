#pragma once
#include "stdafx.h"
class KnapsackProblem :
	public Algorithm
{
private:
	int amountOfItems;
	int knapsackCapacity;
	std::vector <std::pair<int, int>> items; //Wektor par items[numer przedmiotu] = para[waga, wartoœæ]
	
public:
	KnapsackProblem();
	~KnapsackProblem();
	bool loadFromFile(std::string fileName);
	void greedyAlgorithm();	//Wersja zach³anna algorytmu aproksymacyjnego
	void bruteforce();
	void print();
};


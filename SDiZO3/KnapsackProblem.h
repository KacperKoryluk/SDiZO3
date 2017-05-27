#pragma once
#include "Algorithm.h"
class KnapsackProblem :
	public Algorithm
{
private:
	int numberOfItems;
	int knapsackCapacity;
	vector <std::pair<int, int>> items; //Wektor par items[numer przedmiotu] = para[waga, wartoœæ]
	
public:
	KnapsackProblem();
	~KnapsackProblem();
	void loadFromFile(std::string fileName);
	void greedyAlgorithm();
	void bruteforce();
};


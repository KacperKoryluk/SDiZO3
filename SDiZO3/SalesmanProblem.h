#pragma once
#include "Algorithm.h"
class SalesmanProblem :
	public Algorithm
{
private:
	int amountOfCities;
	int **distanceMatrix; //WskaŸnik na tablicê wskaŸników tab[miasto i][miasto j] = odleg³oœæ miasta i od miasta j
public:
	SalesmanProblem();
	~SalesmanProblem();
	bool loadFromFile(std::string fileName);
	void greedyAlgorithm();
	void bruteforce();
};


#pragma once
#include "Algorithm.h"
class SalesmanProblem :
	public Algorithm
{
private:
	int amountOfCities;
	int **distanceMatrix; //Wska�nik na tablic� wska�nik�w tab[miasto i][miasto j] = odleg�o�� miasta i od miasta j
public:
	SalesmanProblem();
	~SalesmanProblem();
	bool loadFromFile(std::string fileName);
	void greedyAlgorithm();
	void bruteforce();
};


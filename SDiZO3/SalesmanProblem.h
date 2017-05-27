#pragma once
#include "Algorithm.h"
class SalesmanProblem :
	public Algorithm
{
private:
	
public:
	SalesmanProblem();
	~SalesmanProblem();
	void loadFromFile(std::string fileName);
	void greedyAlgorithm();
	void bruteforce();
};


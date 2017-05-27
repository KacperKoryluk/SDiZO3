#pragma once
#include "stdafx.h"

class Algorithm
{
private:
	
public:
	Algorithm();
	~Algorithm();
	virtual void greedyAlgorithm() {};
	virtual void bruteforce() {};
	virtual void loadFromFile(std::string fileName) {};
};


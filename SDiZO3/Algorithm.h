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
	virtual bool loadFromFile(std::string fileName) {};
};


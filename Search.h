#pragma once
#include "Parameters.h"
#include "Container.h"
#include "SearchOperators.h"
#include <vector>
class  Search
{
public:
	 Search();
	 Search(Parameters, vector<vector<Container>>);
	~ Search();

	
private:
	Parameters param;
	SearchOperators operators;
	vector<vector<Container>> mainStructure;
	vector<vector<vector<Container>>> neighbors;
	double fitness(vector<vector<Container>>);
};


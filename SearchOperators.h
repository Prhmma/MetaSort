#pragma once
#include "Container.h"
#include <vector>
class SearchOperators
{
public:
	SearchOperators();
	~SearchOperators();
	vector<vector<Container>> swap(vector<vector<Container>>, int, int, int, int);
	vector<vector<Container>> mutate(vector<vector<Container>>);
	vector<vector<Container>> rowShift(vector<vector<Container>>, int);
	vector<vector<Container>> rowSwap(vector<vector<Container>>, int, int);
	vector<vector<Container>> columnSwap(vector<vector<Container>>, int, int);
};

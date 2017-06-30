#include "Search.h"
Search::Search()
{
}

Search::Search(Parameters p, vector<vector<Container>> m)
{
	param = p;
	mainStructure = m;
}

Search::~Search()
{
}

double Search::fitness(vector<vector<Container>>)
{
	return 0.0;
}


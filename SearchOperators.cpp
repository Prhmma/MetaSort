#include "SearchOperators.h"
#include <iomanip>

SearchOperators::SearchOperators()
{
}

SearchOperators::~SearchOperators()
{
}
vector<vector<Container>> SearchOperators::swap(vector<vector<Container>> structure, int firsti, int firstj, int secondi, int secondj)
{
	std::swap(structure.at(firsti).at(firstj), structure.at(secondi).at(secondj));
	return structure;
}

vector<vector<Container>> SearchOperators::mutate(vector<vector<Container>> structure)
{
	int doorNumber = structure.at(1).size();
	int size = structure.size();
	srand(time(NULL));
	int r1, c1;
	int r2, c2;
	r1 = rand() % (size / doorNumber);
	c1 = rand() % doorNumber;
	r2 = rand() % (size / doorNumber);
	c2 = rand() % doorNumber;
	return swap(structure,r1,c1,r2,c2);
}

vector<vector<Container>> SearchOperators::rowShift(vector<vector<Container>> structure, int direction)
{
	if (direction == 1)//rotate right
	{
		rotate(structure.begin(), structure.end() - 1, structure.end());
	}
	else if (direction == 0)//rotate left
	{
		rotate(structure.begin(), structure.begin() + 1, structure.end());
	}
	return structure;
}

vector<vector<Container>> SearchOperators::rowSwap(vector<vector<Container>> structure, int first, int second)
{
	structure.at(first).swap(structure.at(second));
	return structure;
}

vector<vector<Container>> SearchOperators::columnSwap(vector<vector<Container>> structure, int first, int second)
{
	int i = 0;
	while (i < structure.size()) {
		std::swap(structure.at(i).at(first), structure.at(i).at(second));		
	}
	return structure;
}

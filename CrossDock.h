#pragma once
#include <vector>
#include "Forklift.h"

using namespace std;
class Door
{
public:
	int x;
	int y;
	vector<int> stock;
};

class CrossDock
{
public:
	vector<Door> doors;
	vector<Forklift> forklifts;
	vector<vector<double>> distanceTable;
	CrossDock(int);
	~CrossDock();
};

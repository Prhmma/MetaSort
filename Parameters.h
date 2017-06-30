#pragma once
class Parameters {
public:
	Parameters();
	Parameters(int,int);
	~Parameters();
	int swap;
	int mutate;
	int rowShift;
	int rowSwap;
	int columnSwap;
	int threshold;
	int population;
};
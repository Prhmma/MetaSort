#pragma once
#include <vector>
using namespace std;
class Container
{
public:
	Container();
	~Container();
	int ID;
	int satisfaction=0;
	int leave = 0;
	vector<int> lst_GiveTo;
	vector<int> lst_GiveAmount;
	vector<int> lst_RecieveFrom;
	vector<int> lst_RecieveAmount;

	void setUp();
	int getGivers();
	///<summary>
	///daasdasd a
	///sdasdkas d
	///as dasl dk;sa dk
	///as dk
	///sa; dk;dl ka;sd
	///</summary>
	int getGPR();
	double getiRS();
	bool getRD();
	int getDN();
	int getRN();
	int getGC();
	int getRC();
	void setDN(int);
	void setRN(int);

	void print();
private:
	
	//int GiversCount;
	int numberOfItemsToGive;
	int numberOfItemsToRecieve;
	int RoundNumber;
	int Doornumber;
	bool ReverseDependency;
	double GivingPerRecieving;
	double inRoundSatisfaction;
};
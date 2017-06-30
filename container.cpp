#include "Container.h"
#include <iostream>
#include <vector>

Container::Container()
{
	ID=0;
	numberOfItemsToGive=0;
	numberOfItemsToRecieve=0;
	RoundNumber=0;
	Doornumber=0;
	ReverseDependency=false;
	GivingPerRecieving=0;
	inRoundSatisfaction=0;
}

	
Container::~Container()
{
}

void Container::setUp()
{
	numberOfItemsToGive = lst_GiveTo.size();
	numberOfItemsToRecieve = lst_RecieveFrom.size();
	//cout << ID << " : " << GiversCount << " , " << RecieversCount << endl;
	if (numberOfItemsToRecieve != 0)
		GivingPerRecieving = numberOfItemsToGive / numberOfItemsToRecieve;
	else
		GivingPerRecieving = 100;
}

///<summary>
///
///
///
///
///
///</summary>
int Container::getGPR()
{
	return GivingPerRecieving;
}

double Container::getiRS()
{
	return inRoundSatisfaction;
}

bool Container::getRD()
{
	return ReverseDependency;
}

int Container::getDN()
{
	return Doornumber;
}

int Container::getRN()
{
	return RoundNumber;
}

int Container::getGC()
{
	return numberOfItemsToGive;
}

int Container::getRC()
{
	return numberOfItemsToRecieve;
}

void Container::setDN(int a)
{
	Doornumber=a;
}

void Container::setRN(int a)
{
	RoundNumber=a;
}
void Container::print() {
	cout<<"ID ="<<ID<<endl;
	cout << "number Of Items To Give = " << numberOfItemsToGive << endl;
	cout << "number Of Items To Recieve = " << numberOfItemsToRecieve << endl;
	cout << "Round Number = " << RoundNumber << endl;
	cout << "Door number = " << Doornumber << endl;
	cout << "Giving Per Recieving = " << GivingPerRecieving << endl;
	cout << "------------------------------------" << endl;
}

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "Container.h"

using namespace std;
vector<Container> readFile(string, int);
vector<Container> sort(vector<Container>);
bool DeadLockTest(vector<vector<Container>>, int, int);
vector<vector<Container>> intelliSort(vector<vector<Container>>,int,int,int);
vector<int> mostNeeded(vector<int>, int);
vector<vector<Container>> swapOperation(vector<vector<Container>>, int, int,int, int);
void printStructure(vector<vector<Container>>, int, int);
void test();


void main()
{
	int size = 64;
	int doorNumbers = 16;
	string fileName = "C:\\Users\\qp\\Desktop\\qiau\\Thesis\\cross-dock\\untouch\\Project\\InputData\\small\\small8\\uncorrelated\\low\\randomtest1.csv";
	vector<Container> containers = readFile(fileName, size);
	for (int i = 0;i < containers.size(); i++)
		containers.at(i).setUp();
	containers = sort(containers);
	vector<vector<Container>> MainStructur;
	int p = size-1;
	for (int i = 0;i < size/doorNumbers;i++)
	{
		vector<Container> temp;
		for (int j = 0;j < doorNumbers;j++)
		{
			containers.at(p).setDN(j);
			containers.at(p).setRN(i);
			temp.push_back(containers.at(p));
			p--;
		}
		MainStructur.push_back(temp);
	}
	cout << "initial structure" << endl;
	printStructure(MainStructur, size, doorNumbers);
	for (int attempt = doorNumbers / 3;attempt < doorNumbers/2;attempt++) {
		if (DeadLockTest(MainStructur, size, doorNumbers) == false) {
			cout << "no dead lock";
			break;
		}
		else {
			cout << "dead lock";
			MainStructur=intelliSort(MainStructur, size, doorNumbers,attempt);
		}
		cout << endl<<"trial: "<<attempt<<endl;
		printStructure(MainStructur, size, doorNumbers);

	}
	getche();
}
void test() {

	string fileName = "C:\\Users\\qp\\Desktop\\qiau\\Thesis\\cross-dock\\untouch\\Project\\InputData\\small\\small8\\uncorrelated\\low\\randomtest1.csv";
	ifstream ifile;
	string text;
    ifile.open(fileName);
	vector<vector<int>> testVec;
	vector<int> tempTest;
	string token;
	while (!ifile.eof()) {
		ifile >> text;
		istringstream ss(text);
		while (getline(ss, token, ',')) {
			tempTest.push_back(stoi(token));
		}
		testVec.push_back(tempTest);
		tempTest.clear();
	}
	
}
void printStructure(vector<vector<Container>> MainStructur,int size, int doorNumbers) {
	cout << "(ID - GIVING - RECIEVING)" << endl;
	for (int i = 0;i < size / doorNumbers;i++)
	{
		for (int j = 0;j < doorNumbers;j++)
		{
			string s = "(" + to_string(MainStructur.at(i).at(j).ID) + "-" + to_string(MainStructur.at(i).at(j).getGC()) + "-" + to_string(MainStructur.at(i).at(j).getRC()) + ")";
			cout << setw(8) << s;
		}
		cout << endl;
	}
	cout << endl << "press any key to continue...";
	getche();
}
vector<Container> readFile(string fileName, int size)
{
	ifstream file;
	file.open(fileName,ios::in);
	string value;
	int index=0;
	string intString;

	file >> value;
	vector<Container> container(size);
	while (index<size)
	{
		file >> value;
		istringstream ss(value);
		int counter = 0;
		while (getline(ss, intString, ',')) 
		{
			if (counter == 0)
			{
				container.at(index).ID = stoi(intString);
			}
			else if(stoi(intString)!=0)
			{
				container.at(index).lst_RecieveFrom.push_back(counter-1);
				container.at(index).lst_RecieveAmount.push_back(stoi(intString));
				container.at(counter-1).lst_GiveTo.push_back(index);
				container.at(counter-1).lst_GiveAmount.push_back(stoi(intString));		
			}
			counter++;
		}
		index++;
	}
	return container;
}
vector<Container> sort(vector<Container> c)
{
	int maxGiving = 0;
	int lastPos = c.size()-1;
	int maxPos = 0;
	Container cTemp;
	while (lastPos>=0)
	{
		for (int i = 0;i <= lastPos;i++)
		{
			if (c.at(i).getGPR()>maxGiving)
			{
				maxGiving = c.at(i).getGPR();
				maxPos = i;
			}
		}
		cTemp = c.at(lastPos);
		c.at(lastPos) = c.at(maxPos);
		c.at(maxPos) = cTemp;
		lastPos--;
		maxPos = 0;
		maxGiving = 0;
	}
	return c;
}
bool DeadLockTest(vector<vector<Container>> c,int size, int doorNumber)
{
	//biaim bade khali shodane har round, dobare sort konim, 
	//va kalahayi k allan too cross-dock hasto az liste girandegi hazf konim
	//intori shayad yeki k ghablan ziad mikhaste, allan hamash too cross-dock bashe, biad safe aval
	vector <int> CrossDock;
	int row = 0;
	bool refresh = 0;
	vector<Container> Door;
	Door=c.at(0);
	for (int i = 0;i < doorNumber;i++)
	{
		CrossDock.push_back(Door.at(i).ID);
		
		//unloading goods at each door
		//door distance not considered yet!
	}
	int counter = 0;
	while (true)
	{
		for each (Container truck in Door)
		{
			counter++;
			//cout << endl<<truck.getDN()<<": "<<truck.ID << ", "<<truck.getGC()<<", "<<truck.getRC()<<endl;
			for each(int id in truck.lst_RecieveFrom)
			{
				//cout << id << "= ";
				if (find(CrossDock.begin(), CrossDock.end(), id) != CrossDock.end())
				{
					//cout << "O  ";
					truck.satisfaction++;
					id = -1;
				}
			//	else
					//cout << "X  ";
			}
			//cout << truck.ID << " : " << truck.satisfaction << endl;
			if (truck.satisfaction == truck.lst_RecieveFrom.size())
			{
				truck.leave = 1;

				//cout << endl<<truck.ID << " **LEFT**" << endl;
				if (truck.getRN() + 1 < size / doorNumber)
				{
					//avali k miad biroon yeki dg bejash miad, bejaye inke sare jaye oon beshine
					//mire yeki jelo tar.
					//too mesal doorNumber bayad 0 beshe, vali 48 roo 1 miad.
					Door[truck.getDN()] = c[truck.getRN() + 1][truck.getDN()];
					CrossDock.push_back(Door[truck.getDN()].ID);
					refresh = 1;
					//cout << Door[truck.getDN()].ID << " ** joined **" << endl;
				}
			}
		}
		//cout << "**************************** " << counter << endl;
  		int flag = 0;
		for each (Container contin in Door)
		{
			if (contin.leave == 0)
				flag = 1;
		}
		if ((flag == 0 && refresh == 0) || counter==size)
			break;
		if (flag == 1 && refresh == 0)
			return true;
		refresh = 0;
	}
	return false;
}

vector<vector<Container>> intelliSort(vector<vector<Container>> c,int size, int doorNumber,int attempt)
{
	for (int i = 0;i < size / doorNumber;i++)
	{
		vector<int> list(size,0);
		for (int j = 0;j < i + attempt;j++)
		{
			if (j == doorNumber)
				break;
			for each(int id in c[i][j].lst_RecieveFrom)
			{
				list[id]++;
			}
		}
		//Xtract ids that satisfy most givers at each round
		vector<int> inRoundNeed = mostNeeded(list, doorNumber);
		//reverse(list.begin(), list.end());
		for (int j = doorNumber - 1; j >= i + attempt; j--)
		{
			if (doorNumber - j - 1 >= inRoundNeed.size())
				break;
			c = swapOperation(c, c.at(i).at(j).ID, inRoundNeed.at(doorNumber - j - 1), size, doorNumber);
		}
	}
	return c;
}
vector<int> mostNeeded(vector<int> IDs,int doorNumber)
{
	int max = 0;
	int find = 1;
	int id = 0;
	vector<int> vec;
	while (find==1)
	{
		find = 0;
		for (int i = 0;i < IDs.size();i++)
		{
			if (IDs[i] > max)
			{
				max = IDs[i];
				id = i;
				find = 1;
			}
		}
		if (find == 1)
		{
			IDs[id] = 0;
			max = 0;
			vec.push_back(id);
		}
	}
	return vec;
}
vector<vector<Container>> swapOperation(vector<vector<Container>> c, int id1, int id2, int size, int doorNumber)
{
	Container tempTruck;
	int tempLocation1[2] = { 0,0 };
	int tempLocation2[2] = { 0,0 };
	bool flag1 = false;
	bool flag2 = false;
	for (int i = 0;i < size / doorNumber;i++)
	{
		for (int j = 0;j < doorNumber;j++)
		{
			if (c.at(i).at(j).ID == id1)
			{
				tempLocation1[0] = i;
				tempLocation1[1] = j;
				flag2 = true;
			}
			else if(c.at(i).at(j).ID == id2)
			{
				tempLocation2[0] = i;
				tempLocation2[1] = j;
				flag2 = true;
			}
			
		}
		if (flag1 && flag2)
			break;
	}
	tempTruck = c.at(tempLocation1[0]).at(tempLocation1[1]);
	//cout << tempTruck.ID << " with " << c.at(tempLocation2[0]).at(tempLocation2[1]).ID<<endl;
	c.at(tempLocation1[0]).at(tempLocation1[1])= c.at(tempLocation2[0]).at(tempLocation2[1]);
	c.at(tempLocation2[0]).at(tempLocation2[1]) = tempTruck;
	
	return c;	
}
//trial on neighboring operations
vector<vector<Container>> rowSwap(vector<vector<Container>> c, int firstRow, int secondRow, int size, int doorNumber) {
	//vector<Container> temp;
	//temp = c.at(firstRow);
	//c.at(firstRow)=c.at(secondRow);
	//c.at(secondRow) = temp;
	c.at(firstRow).swap(c.at(secondRow));
	return c;
}
//vector<vector<Container>> rowRotate(vector<vector<Container>> c, int row, int rotateDegree) {
//	rotate(c.at(row).begin, c.at(row).begin + rotateDegree, c.at(row).end);
//	return c;
//}
vector<vector<Container>> mutate(vector<vector<Container>> c, int size, int doorNumber) {
	srand(time(NULL));
	int r1, c1;
	int r2, c2;
	r1 = rand() % (size / doorNumber);
	c1 = rand() % doorNumber;
	r2 = rand() % (size / doorNumber);
	c2 = rand() % doorNumber;
	swap(c.at(r1).at(c1), c.at(r2).at(c2));
	return c;
}
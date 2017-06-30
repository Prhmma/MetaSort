#pragma once
#include <vector>
class Forklift{
public:
	Forklift(int,double);
	int ID;//specific door number which its belong to.
	double speed;
	int destination;//where its going.
	//std::vector<int> goods; //list of what it carries, in case of multitype carriage is allowed.
	//std::vector<int> amount;//list of how many it carries, in case of multitype carriage is allowed.
	int goods;//what it carries.
	int amount;//how many it carries
	enum stats { Busy, Standby };
	stats status;

};
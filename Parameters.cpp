#include "Parameters.h"

Parameters::Parameters() {
	swap=2;
	mutate=2;
	rowShift=10;
	rowSwap=20;
	columnSwap=20;
	threshold=40;
	population=40;
}
Parameters::Parameters(int doorNumber, int truckNumber) {
	swap = 2;
	mutate = 2;
	rowShift = doorNumber;
	rowSwap = 2*doorNumber;
	columnSwap = truckNumber/doorNumber;
	if (rowSwap > columnSwap) {
		threshold = rowSwap;
	}
	else {
		threshold = columnSwap;
	}
	population = threshold;
}
Parameters::~Parameters() {

}
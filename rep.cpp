#include "rep.h"

/*
*  Implementation of randNeighbor
*  because my roommate in CS51 told
*  me the other day to never copy and
*  paste code.
*/
vector<int> Rep::randNeighbor() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,neighbors.size()-1);
	return neighbors[dis(gen)];
}
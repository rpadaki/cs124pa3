#include "rep.h"

/*
*	Implementation of the
*	standard representation
*	of this problem.
*/

// Solutions are lists of +-1 values.
// We think of them as 0/1 for efficiency.
vector<int> Rep::randSolution() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,1);

	vector<int> out(n);
	for (int i = 0; i < n; ++i) {
		out[i]=dis(gen);
	}
	return out;
}

// Neighbors differ in exactly 1 or 2 slots.
void  Rep::calcNeighbors(vector<int> solution) {
	// We can use combinatorics to calculate the number
	// of neighbors.
	neighbors.clear();
	neighbors.resize(n*(n+1)/2);
	fill(neighbors.begin(), neighbors.end(), solution);
	int k = 0;
	
	// Neighbors that differ in 1 slot.
	for (int i = 0; i < n; ++i) {
		neighbors[k][i] = 1-neighbors[k][i];
		++k;
	}

	// Neighbors that differ in 2 slots.
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
		{
			neighbors[k][i] = 1-neighbors[k][i];
			neighbors[k][j] = 1-neighbors[k][j];
			++k;
		}
	}
}

// The residue is just the positive difference
// between the two sums.
uint64_t Rep::residue(vector<int> solution) {
	uint64_t total1 = 0;
	uint64_t total2 = 0;
	for (int i = 0; i < n; i++) {
		if (solution[i]) total1 += a[i];
		else total2 += a[i];
	}
	if (total1>total2) return total1-total2;
	else return total2-total1;
}
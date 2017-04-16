#include "kkimp.h"
#include "rep.h"

/*
*	Implementation of the
*	prepartitioning representation
*	of this problem.
*/

// Solutions are lists of values 0 through n-1.
vector<int> Rep::randSolution() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,n-1);

	vector<int> out(n);
	for (int i = 0; i < n; ++i) {
		out[i]=dis(gen);
	}
	return out;
}

// Neighbors differ in exactly 1 slot.
void Rep::calcNeighbors() {
	// There are n slots and each one can be changed to
	// (n-1) different values.
	neighbors = vector<vector<int>>(n*(n-1),vector<int>(n));
	int k = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			neighbors[k][i] = j;
			++k;
		}
	}
}

// Given a slot in neighbors, calculate
// the actual solution.
vector<int> Rep::findNeighbor(vector<int> solution, int m) {
	for (int i = 0; i < n; ++i) {
		solution[i] = (solution[i] + neighbors[m][i]) % n;
	}
	return solution;
}

// To get the residue, we first enforce the
// prepartitioning, then use KK.
uint64_t Rep::residue(vector<int> solution) {
	vector<uint64_t> b(a.size());
	for (int j = 0; j < n; j++) {
		b[solution[j]] += a[j];
	}
	return kk(b);
}
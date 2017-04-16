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
void Rep::calcNeighbors(vector<int> solution) {
	// There are n slots and each one can be changed to
	// (n-1) different values.
	neighbors.clear();
	neighbors.resize(n*(n-1));
	fill(neighbors.begin(), neighbors.end(), solution);
	int k = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			neighbors[k][i] = (neighbors[k][i] + j) % n;
			++k;
		}
	}
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
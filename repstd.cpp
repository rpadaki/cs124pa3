#include <vector>
#include <random>
#include <iostream>
#include "rep.h"

using namespace std;

/*
*	Implementation of the
*	standard representation
*	of this problem.
*/

// For testing purposes
int main() {
	Rep stRep;
	vector<uint64_t> a = {10, 8, 7, 6, 5};
	stRep.n = 5;
	stRep.a = a;
	vector<int> solution = stRep.randSolution();
	for (int i : solution) {
		cout << i << ", ";
	}
	cout << endl;
	cout << endl;
	vector<vector<int>> neighbors =stRep.neighbors(solution);
	for (vector<int> c : neighbors) {
		for (int i= 0; i < 5; i++) {
			cout << (c[i] - solution[i])*(c[i]-solution[i]) << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << stRep.residue(solution) << endl;
	return 0;
}

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
vector<vector<int>>  Rep::neighbors(vector<int> solution) {
	vector<vector<int>> neighbors(n*(n+1)/2, solution);
	int k = 0;
	cout << "pizza" << endl;
	for (int i = 0; i < n; ++i) {
		neighbors[k][i] = 1-neighbors[k][i];
		k++;
	}
		cout << "pizza" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
		{
			neighbors[k][i] = 1-neighbors[k][i];
			neighbors[k][j] = 1-neighbors[k][j];
			k++;
		}
	}
		cout << "pizza" << endl;

	return neighbors;
}

// The residue is just the absolute value of the sum
uint64_t Rep::residue(vector<int> solution) {
	uint64_t total1 = 0;
	uint64_t total2 = 0;
	for (int i = 0; i < n; i++) {
		if (solution[i]) total1 += a[i];
		else total2 += a[i];
	}
	cout << total1 << endl << total2 << endl;
	if (total1>total2) return total1-total2;
	else return total2-total1;
}
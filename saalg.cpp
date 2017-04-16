#include <cmath>
#include "rep.h"
#include "alg.h"

/*
*  Simulated annealing
*/

long double temp(uint64_t, uint64_t, int, long double);

uint64_t minResidue(vector<uint64_t> a, int maxIter) {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<long double> dis(0,1);

	Rep r;
	r.a = a;
	r.n = a.size();
	vector<int> s = r.randSolution();
	vector<int> t;
	uint64_t ress = r.residue(s);
	uint64_t resu = ress;
	uint64_t rest;
	long double num = pow(10,10);
	r.calcNeighbors(s);
	for (int i=0; i<maxIter; ++i) {
		t = r.randNeighbor();
		rest = r.residue(t);
		if (rest < ress) {
			s=t;
			ress=rest;
			r.calcNeighbors(s);
		}
		else if (dis(gen) < temp(ress,rest,i, num)) {
			s=t;
			ress=rest;
			r.calcNeighbors(s);
		}
		if (ress < resu) {
			resu=ress;
		}
	}
	return resu;
}

long double temp(uint64_t a, uint64_t b, int i, long double num) {
	return exp(-(long double)(b-a)/(num*pow((long double) 0.8,(i+1)/300)));
}
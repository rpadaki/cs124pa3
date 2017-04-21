#include "rep.h"
#include "alg.h"

/*
*  Repeated random.
*/
uint64_t minResidue(vector<uint64_t> a, int maxIter) {
	Rep r;
	r.a = a;
	r.n = a.size();
	vector<int> s = r.randSolution();
	uint64_t ress = r.residue(s);
	vector<int> t;
	uint64_t rest;
	for (int i=0; i<maxIter; ++i) {
		t = r.randSolution();
		rest = r.residue(t);
		if (rest < ress) {
			ress = rest;
		}
	}
	return ress;
}
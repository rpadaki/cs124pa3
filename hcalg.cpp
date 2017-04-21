#include "rep.h"
#include "alg.h"

/*
*  Hill climbing.
*/
uint64_t minResidue(vector<uint64_t> a, int maxIter) {
	Rep r;
	r.a = a;
	r.n = a.size();
	vector<int> s = r.randSolution();
	uint64_t ress = r.residue(s);
	vector<int> t;
	uint64_t rest;;
	r.calcNeighbors();
	for (int i=0; i<maxIter; ++i) {
		t = r.randNeighbor(s);
		rest = r.residue(t);
		if (rest < ress) {
			s = t;
			ress = rest;
		}
	}
	return ress;
}
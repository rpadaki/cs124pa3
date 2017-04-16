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
	vector<int> t;
	for (int i=0; i<maxIter; ++i) {
		t = r.randSolution();
		if (r.residue(t) < r.residue(s)) s=t;
	}
	return r.residue(t);
}
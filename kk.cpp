#include <iostream>
#include <fstream>
#include "alg.h"

using namespace std;

/*
*  Get list from file and do stuff with it.
*  Print out the minimum residue based on
*  the algorithm and representation we are
*  compiling with.
*/

vector<uint64_t> getList(string);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "usage: " << argv[0] << "<filename>\n";
	}
	else {
		vector<uint64_t> a = getList(argv[1]);
		cout << minResidue(a,100000);
	}
	return 0;
}

// Get a list from file.
vector<uint64_t> getList(string filename) {
	ifstream in(filename);

	vector<uint64_t> out(0);
	uint64_t sto;
	while (in >> sto) out.push_back(sto);

	in.close();
	return out;
}
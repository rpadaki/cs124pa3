#include <vector>
#include <random>
#include <cstdint>

using namespace std;

/*
*  Methods for either representation
*  of the Number Partition problem.
*  Don't tell us this isn't slick.
*  This is slick.
*  This lets the makefile handle
*  the dirty work.
*/

struct Rep {
	// The size of our list
	int n;

	// our list
	vector<uint64_t> a;

	// ways to create neighbors
	vector<vector<int>> neighbors;

	// Generate a random solution.
	vector<int> randSolution();

	// initialize neighbors
	void calcNeighbors();

	// how to actually create a neighbor
	// given a 'neighbor constructor'
	vector<int> findNeighbor(vector<int>, int);

	// Get a random neighbor of the given
	// solution.
	vector<int> randNeighbor(vector<int>);

	// Get the residue of a given solution.
	uint64_t residue(vector<int>);
};
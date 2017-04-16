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

	// keep track of neighbors efficiently
	vector<vector<int>> neighbors;

	// Generate a random solution.
	vector<int> randSolution();

	// Calculate the neighbors of given
	// solution and store in neighbors.
	void calcNeighbors(vector<int>);

	// Get a random element of neighbors.
	vector<int> randNeighbor();

	// Get the residue of a given solution.
	uint64_t residue(vector<int>);
};
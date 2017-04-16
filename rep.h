// Methods for either representation
// of the Number Partition problem.

struct Rep {
	// The size of our list
	int n;

	// our list
	vector<uint64_t> a;

	// Generate a random solution.
	vector<int> randSolution();

	// Get the neighbors of given soltion.
	vector<vector<int>> neighbors(vector<int>);

	// Get the residue of a given solution.
	uint64_t residue(vector<int>);
};
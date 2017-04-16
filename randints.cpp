#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <random>
#include <string>

using namespace std;

void randlist(string);

int main(int argc, char *argv[]) {
	// Check for proper input.
	if (argc != 2) {
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else {
		// Store 100 randomly 64-bit
		// ints in the specified file.
		randlist(argv[1]);
	}
}

// Store 100 random 64-bit ints
// in specified file.
void randlist(string filename) {
	// Open output file
	ofstream out(filename);

	// RNG setup
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<uint64_t> dis(1,pow(10,12));
	
	// Do the thing
	for (int i = 0; i < 99; ++i)
	{
		out << dis(gen) << endl;
	}
	out << dis(gen);

	// Close output file
	out.close();
}
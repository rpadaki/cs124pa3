#include <fstream>
#include <cstdint>
#include <cmath>
#include <random>
#include <string>
#include <iostream>

using namespace std;

/*
*	Generate random ints and
*	store them in files.
*/

void randList(string);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else {
		randList(argv[1]);
	}
	return 0;
}

// Store 100 random 64-bit ints
// in specified file.
void randList(string filename) {
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

	out.close();
}
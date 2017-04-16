#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <random>

using namespace std;

int main() {
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<uint64_t> dis(1,pow(10,12));
	for (int i = 0; i < 7; ++i)
	{
		cout << dis(gen) << endl;
	}
	cout << "Hello tomoka!";
	return 0;
}
#include <iostream>

using namespace std;

int hammingDistance(int x, int y) {
	unsigned int s = x ^ y;

	int ones = 0;
	while (s != 0) {
		if ((s & 1)) ++ones;

		s = s >> 1;
	}

	return ones;
}

int main() {
	int x = 11, y = 4;

	cout << hammingDistance(x, y) << endl;

	return 0;
}
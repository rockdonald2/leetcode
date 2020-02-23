#include <iostream>

using namespace std;

bool isPowerOfFour(int n) {
	if (n < 1) return false;

	while (n % 4 == 0 && n > 0) {
		// n /= 4;
		n >>= 2;
	}

	return n == 1;
}


int main() {
	int n{ 256 };

	cout << isPowerOfFour(n) << endl;

	return 0;
}
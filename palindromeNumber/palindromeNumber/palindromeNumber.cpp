#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	/*int rN = 0;
	int cN = n;

	while (cN != 0) {
		int rem = cN % 10;
		rN = rN * 10 + rem;
		cN /= 10;
	}

	if (n == rN) {
		return true;
	}
	else {
		return false;
	}*/

	if (x == 0) return true;
	else if (x < 0 || (x % 10 == 0 && x != 0)) return false;

	int rN = 0;

	while (x > rN) {
		int rem = x % 10;
		rN = rN * 10 + rem;

		x /= 10;
	}

	return x == rN || x == rN / 10;
}

int main() {
	int n = 10;

	cout << isPalindrome(n) << endl;

	return 0;
}
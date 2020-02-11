#include <iostream>

using namespace std;

bool isPalindrome(int n) {
	int rN = 0;
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
	}
}

int main() {
	int n = 20200202;

	cout << isPalindrome(n) << endl;

	return 0;
}
#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
	while (n % 3 == 0 && n > 0) {
		n /= 3;
	}

	if (n == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n = 243;

	cout << isPowerOfThree(n) << endl;

	return 0;
}
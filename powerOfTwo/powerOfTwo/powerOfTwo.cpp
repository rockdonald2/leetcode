#include <iostream>
#include <bitset>

using namespace std;

bool isPowerOfTwo(int n) {
	/*bitset<64> b(n);

	return b.count() == 1;*/

	if (n < 1) return false;
	else return (n & (n - 1)) == 0;
}

int main() {
	int n{ 219 };

	cout << isPowerOfTwo(n) << endl;

	return 0;
}
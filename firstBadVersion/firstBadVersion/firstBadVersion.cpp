#include <iostream>

using namespace std;

bool isBadVersion(int version) {
	if (version <= 4) return false;
	else return true;
}

int firstBadVersion(int n) {
	int left = 1, right = n, mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		if (isBadVersion(mid) && !isBadVersion(mid - 1)) return mid;
		else if (isBadVersion(mid - 1)) right = mid;
		else left = mid + 1;
	}

	if (isBadVersion(left)) return left;
	else return -1;
}

int main() {
	cout << firstBadVersion(5) << endl;

	return 0;
}
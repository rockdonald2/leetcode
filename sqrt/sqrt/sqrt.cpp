#include <iostream>

using namespace std;

int mySqrt(int x) {
	if (x == 0) return 0;
	int left = 1, right = x - 1, mid;

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (mid <= x / mid && (mid + 1) > x / (mid + 1)) return mid;
		else if (mid < x / mid) left = mid + 1;
		else right = mid - 1;
	}

	return 1;
}

int main() {
	cout << mySqrt(10) << endl;

	return 0;
}
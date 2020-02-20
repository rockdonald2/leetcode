#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandomNumber(int min, int max) {
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int guess(int num) {
	static int r{ getRandomNumber(1, 10) };

	if (num == r) return 0;
	else if (num > r) return -1;
	else return 1;
}

int guessNumber(int n) {
	int left = 1, right = n, mid;

	while (left <= right) {
		mid = left + (right - left) / 2;

		int v = guess(mid);

		if (v == 0) return mid;
		else if (v == 1) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << guessNumber(10) << endl;

	return 0;
}
#include <iostream>
#include <map>

using namespace std;

int countPrimes(int n) {
	map<int, bool> m;

	for (int i = 2; i < sqrt(n); ++i) {
		int p = i * i;
		int incrementer = 0;

		if (!m[i]) {
			m[i] = false;
		}

		while (sqrt(p) < sqrt(n)) {
			m[p] = true;

			incrementer += i;
			p = i * i + incrementer;
		}
	}

	int primes = 0;
	for (int i = 2; i < n; ++i) {
		if (m[i] == false) {
			primes += 1;
		}
	}

	return primes;
}

int main() {
	int n = 499979;

	cout << countPrimes(n) << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int);

int main() {
	cout << tribonacci(25) << '\n';

	return 0;
}

int tribonacci(int n) {
    vector<int> tmp{0, 1, 1};

	for (int i = 3; i <= n; ++i) {
		auto next{tmp[i - 3] + tmp[i - 2] + tmp[i - 1]};
		tmp.push_back(next);
	}

	return tmp[n];
}
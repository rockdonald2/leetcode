#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int len = digits.size();
	int i = len - 1;
	if (digits[i] == 9) {
		while (digits[i] == 9) {
			if (i != 0) {
				digits[i] = 0;
			}
			else {
				digits[i] = 0;
				digits.insert(digits.begin(), 1);
				break;
			}

			--i;
		}

		if (digits.size() == len) {
			digits[i] += 1;
		}
	}
	else {
		digits[i] += 1;
	}

	return digits;
}

int main() {
	vector<int> digits{ 5, 7, 9, 9 };

	vector<int> sol = plusOne(digits);

	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
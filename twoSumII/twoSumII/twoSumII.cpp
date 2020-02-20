#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int search(vector<int>& numbers, int target) {
	int left = 0, right = numbers.size() - 1, mid;

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (numbers[mid] == target) return mid;
		else if (numbers[mid] < target) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> sol{ -1, -1 };

	if (numbers.empty()) return sol;

	int i{ 0 }, cr{ numbers[i] }, t;

	while (i < numbers.size()) {
		t = search(numbers, target - cr);

		if (t != -1 && t != i) {
			sol[0] = i + 1; sol[1] = t + 1;
			break;
		}

		if (i < numbers.size() - 1) cr = numbers[++i];
		else break;
	}

	sort(sol.begin(), sol.end());
	return sol;
}*/

vector<int> twoSum(vector<int>& numbers, int target) {
	int left = 0, right = numbers.size() - 1, t;

	while (left < right) {
		t = numbers[left] + numbers[right];

		if (t > target) --right;
		else if (t < target) ++left;
		else if (t == target) break;
	}

	if (left == right) return { -1, -1 };
	else return { left + 1, right + 1 };
}

int main() {
	vector<int> nums{ -1, 0 };
	int target = 3;

	vector<int> sol = twoSum(nums, target);

	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) cout << *it << " ";

	return 0;
}
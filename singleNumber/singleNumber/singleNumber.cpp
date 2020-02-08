#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
	/*sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 1; i += 2) {
		if (nums[i] != nums[i + 1]) {
			return nums[i];
		}
	}

	return nums[nums.size() - 1];*/

	// XOR művelettel a leghatékonyabb megoldani, ahol a^a = 0 és a^0 = a

	int a = 0;
	for (int i = 0; i < nums.size(); ++i) {
		a ^= nums[i];
	}

	return a;
}

int main() {
	vector<int> nums{ 4, 1, 2, 1, 2 };

	cout << singleNumber(nums) << endl;

	return 0;
}
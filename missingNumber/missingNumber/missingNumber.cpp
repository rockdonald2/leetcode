#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNumber(vector<int>& nums) {
	// sortolva az eredeti vectort
	/*sort(nums.begin(), nums.end());

	for (int i = 0; i <= nums.size(); ++i) {
		if (nums[i] != i) {
			return i;
		}
	}

	return -1;*/

	// hasznalva a XOR tulajdonsagot, miszerint a^a = 0 es a^0 = a
	int a = nums.size();
	for (int i = 0; i < nums.size(); ++i) {
		a ^= (i ^ nums[i]);
	}
	// 3^0^3^1^0^1^2 => (3^3)^(0^0)^(1^1)^2 => 0^0^0^2 => 2

	return a;
}

int main() {
	vector<int> nums{ 3, 0, 1 };

	cout << missingNumber(nums) << endl;

	return 0;
}
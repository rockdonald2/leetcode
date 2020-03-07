#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> output_arr;

	for (auto i = 0; i < nums.size(); ++i) {
		auto index = abs(nums[i]) - 1;

		if (nums[index] < 0) output_arr.push_back(index + 1);
		nums[index] = -nums[index];
	}

	return output_arr;
}

int main() {
	vector<int> nums{ 4, 3, 2, 7, 8, 2, 3, 1 };

	vector<int> returned_arr{ findDuplicates(nums) };

	for (auto it = returned_arr.begin(); it != returned_arr.end(); ++it) cout << *it << " ";

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	for (int i = 0, j = 1; j < nums.size() && i < nums.size(); ++j) {
		if (nums[i] != 0) {
			++i;
		}
		
		if (nums[j] != 0 && nums[i] == 0) {
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;

			++i;
		}
	}
}

int main() {
	vector<int> nums{ 0, 1, 0, 3, 12 };

	moveZeroes(nums);

	for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
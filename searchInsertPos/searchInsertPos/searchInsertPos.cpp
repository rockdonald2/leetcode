#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	if (nums.empty()) return 0;
	else if (nums.size() == 1) {
		if (nums[0] >= target) return 0;
		else return 1;
	}

	int left = 0, right = nums.size(), mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) right = mid;
		else left = mid + 1;
	}

	if (mid != nums.size() && nums[mid] >= target) return mid;
	else if (mid != nums.size() && nums[mid] < target) return mid + 1;
	else return 0;
}

int main() {
	vector<int> nums{ 1 };
	int target{ 1 };

	cout << searchInsert(nums, target) << endl;

	return 0;
}
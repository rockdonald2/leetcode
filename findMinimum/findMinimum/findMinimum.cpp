#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	if (nums.empty()) return -1;

	int left = 0, right = nums.size() - 1, mid;

	if (nums[left] < nums[right]) return nums[left];

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) return nums[mid + 1];
		else if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];
		else if (nums[mid] > nums[left]) left = mid + 1;
		else if (nums[mid] < nums[left]) right = mid - 1;
	}

	return -1;
}

int main() {
	vector<int> nums{ 3, 4, 0, 1, 2 };

	cout << findMin(nums) << endl;

	return 0;
}
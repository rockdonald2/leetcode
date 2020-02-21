#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
	/*if (nums.empty()) return -1;
	if (nums.size() == 1) return nums[0];

	int left = 0, right = nums.size() - 1, mid;

	if (nums[left] < nums[right]) return nums[left];

	while (left < right) {
		mid = left + (right - left) / 2;

		if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) return nums[mid + 1];
		else if (mid > 0 && nums[mid] < nums[mid - 1]) return nums[mid];
		else if (nums[left] > nums[mid]) right = mid;
		else left = mid + 1;
	}

	return -1;*/


	if (nums.empty()) return -1;

	int left = 0, right = nums.size() - 1, mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		if (nums[mid] > nums[right]) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return nums[left];
}

int main() {
	vector<int> nums{ 5, 1, 2, 3, 4 };

	cout << findMin(nums) << endl;

	return 0;
}
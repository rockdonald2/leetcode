#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, mid;

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (nums[mid] == target) return mid;

		if (nums[mid] > nums[left]) {
			if (nums[left] <= target && target < nums[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else if (nums[mid] < nums[left]) {
			if (target > nums[mid] && nums[right] >= target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

int main() {
	vector<int> nums{ 4,5,6,7,0,1,2 };

	cout << search(nums, 2) << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int findFirst(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		if (nums[mid] >= target) right = mid;
		else left = mid + 1;
	}

	return nums[left] == target ? left : -1;
}

int findLast(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, mid;

	while (left < right) {
		mid = left + (right - left) / 2 + 1;

		if (nums[mid] < target) left = mid + 1;
		else if (nums[mid] > target) right = mid - 1;
		else left = mid;
	}

	return nums[left] == target ? left : -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.empty()) return { -1, -1 };

	vector<int> result(2);

	result[0] = findFirst(nums, target);

	if (result[0] == -1) return { -1, -1 };

	result[1] = findLast(nums, target);

	return result;
}

int main(void) {
	vector<int> nums{ 1, 1, 1 };
	int target{ 1 };

	vector<int> sol{ searchRange(nums, target) };
	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) cout << *it << " ";

	return 0;
}
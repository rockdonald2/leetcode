#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	int left = 0, right = nums.size(), mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) left = mid + 1;
		else right = mid;
	}

	if (left != nums.size()) return left;
	else return -1;
}

int main() {
	vector<int> nums{ 5, 6, 4, 3, 4, 8, 9 };

	cout << findPeakElement(nums) << endl;

	return 0;
}
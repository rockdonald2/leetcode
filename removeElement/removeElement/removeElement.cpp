#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	if (nums.empty()) return 0;

	if (nums.size() == 1 && nums[0] == val) return 0;
	else if (nums.size() == 1) return 1;

	int ptr1 = 0, ptr2 = 1;

	while (ptr1 < nums.size() && ptr2 < nums.size()) {
		while (ptr1 < nums.size() && ptr2 < nums.size() && nums[ptr1] != val) {
			++ptr1;
			++ptr2;
		}

		while (ptr2 < nums.size() && nums[ptr2] == val) {
			++ptr2;
		}

		if (ptr1 >= nums.size() || ptr2 >= nums.size()) break;

		if (nums[ptr1] == val && nums[ptr2] != val) {
			swap(nums[ptr1], nums[ptr2]);
			++ptr1;
			++ptr2;
		}
	}

	return (nums[ptr1] == val ? ptr1 : ptr1 + 1);
}

int main() {
	vector<int> nums{  };
	int val{ 5 };
	
	int n{ removeElement(nums, val) };
	for (int i = 0; i < n; ++i) {
		cout << nums[i] << " ";
	}

	return 0;
}
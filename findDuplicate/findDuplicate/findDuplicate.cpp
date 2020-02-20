#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findDuplicate(vector<int>& nums) {
	/*for (int i = 0; i < nums.size() - 1; ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[i] == nums[j]) return nums[i];
		}
	}

	return -1;*/

	/*unordered_set<int> s;

	for (int i = 0; i < nums.size(); ++i) {
		if (s.find(nums[i]) != s.end()) return nums[i];
		else s.insert(nums[i]);
	}

	return -1;*/

	int slow = nums[0];
	int fast = nums[0];

	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while (slow != fast);

	slow = nums[0];

	while (slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}

int main() {
	vector<int> nums{ 3, 1, 3, 4, 2 };

	cout << findDuplicate(nums) << endl;

	return 0;
}
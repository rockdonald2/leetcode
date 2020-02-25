#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
	// A tobbsegi elem, egy olyan elem, amely egy adott vector-ban tobbszor jelenik megint, mint hossz / 2

	// I. megoldas
	/*int n = (nums.size() - 1) / 2;
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); ++i) {
		if (m.find(nums[i]) == m.end()) {
			m[nums[i]] = 1;
		}
		else {
			m[nums[i]] += 1;
		}
	}

	for (const auto& k : m) {
		if (k.second >= n) return k.first;
	}*/

	// II. megoldas
	int c = 0;
	int jelolt = 0;

	for (auto& num : nums) {
		if (c == 0) jelolt = num;

		c += (num == jelolt) ? 1 : -1;
	}

	return jelolt;
}

int main() {
	vector<int> nums{ 3, 1, 3 };

	cout << majorityElement(nums) << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> s;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int first = 0, second = 0;

	while (first < nums1.size() && second < nums2.size()) {
		if (nums1[first] > nums2[second]) ++second;
		else if (nums1[first] < nums2[second]) ++first;
		else {
			s.insert(nums1[first]);
			++first;
			++second;
		}
	}

	return vector<int>(s.begin(), s.end());
}

int main() {
	vector<int> nums1{ 4,9,5 };
	vector<int> nums2{ 9,4,9,8,4 };

	vector<int> sol(intersection(nums1, nums2));

	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
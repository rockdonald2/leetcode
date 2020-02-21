#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	/*if (nums1.size() == 0 || nums2.size() == 0) return {};

	vector<int> merged;
	int i = 0, j = 0;

	while(i < nums1.size() && j < nums2.size()) {
		if (nums1[i] <= nums2[j]) {
			merged.push_back(nums1[i++]);
		}
		else if (nums1[i] > nums2[j]) {
			merged.push_back(nums2[j++]);
		}
	}

	while (i < nums1.size()) {
		merged.push_back(nums1[i++]);
	}

	while (j < nums2.size()) {
		merged.push_back(nums2[j++]);
	}

	return merged;*/

	// ha bármelyik üres lenne, térítjük az első arrayt, vagy ha mindkettő üres, akkor egy üreset
	if (nums1.empty() && !nums2.empty()) {
		nums1 = nums2;
		return nums1;
	}
	else if (nums1.empty() && nums2.empty()) return {};
	else if (nums2.empty()) return nums1;

	/*
	
	alapvető ötlet az algoritmus mögött, az, hogy összemérjük a két utolsó inicializált elemet, ami nem 0, és az alapján helyezzük be a végére,
	ha bármelyik mutató, amely az inicializált elemekre mutat 0 lesz, akkor vagy felhelyezzük a maradék elemet a sorba, vagy abbahagyjuk
	
	*/
	for (int i = nums1.size() - 1; i >= 0; --i) {
		if (n == 0) break;
		if (m == 0) {
			nums1[i] = nums2[n - 1];
			--n;
			continue;
		}

		if (nums1[m - 1] > nums2[n - 1]) {
			nums1[i] = nums1[m - 1];
			--m;
		}
		else if (nums1[m - 1] <= nums2[n - 1]) {
			nums1[i] = nums2[n - 1];
			--n;
		}
	}

	return nums1;
}

int main() {
	vector<int> nums1{ 0 };
	vector<int> nums2{ 1 };

	vector<int> sol{ mergeArrays(nums1, 0, nums2, nums2.size()) };

	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) cout << *it << " ";

	return 0;
}
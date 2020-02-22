#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		if (nums[mid] < target) left = mid + 1;
		else right = mid;
	}

	if (left < nums.size() && left >= 0) return left;
	else return -1;
}

vector<int> findClosestElements(vector<int>& nums, int k, int x) {
	vector<int> result;

	// I. eset, amikor a viszonyított elem kisebb, mint az első
	if (x <= nums[0]) {
		int i = 0;
		while (i < k) {
			result.push_back(nums[i++]);
		}
	}
	// II. eset, amikor a viszonyított elem nagyobb, mint az utolsó
	else if (nums[nums.size() - 1] <= x) {
		int i = nums.size() - k;
		while (i < nums.size()) {
			result.push_back(nums[i++]);
		}
	}
	// alap eset, amikor valahol középen található a viszonyított elem
	else {
		// megkeressük hol található az elem, ha nem található, akkor azt az indexet adja vissza, ahol lennie kellene
		int index = search(nums, x);
		if (index == -1) index = 0;

		// egy intervallumot hozzunk létre, amely [index - k, index + k], max. [0, length] lehet
		int low = (index - k) >= 0 ? index - k : 0;
		int high = (index + k) < nums.size() ? index + k : nums.size() - 1;

		// mindaddig csökkentsük az intervallumot, amíg nem marad pontosan k elem
		while (high - low > k - 1) {
			// abban az esetben, ha a low eléri a legelső indexet, vagy az alsó elem közelebb van az x-hez, akkor a felsőt csökkentsük
			if (low < 0 || (x - nums[low] <= nums[high] - x)) --high;
			// abban az esetben, ha a high eléri a legutolsó indexet, vagy a felső elem közelebb van az x-hez, az alsót növeljük
			else if (high > nums.size() - 1 || (x - nums[low] > nums[high] - x)) ++low;
		}

		while (low <= high) {
			result.push_back(nums[low++]);
		}
	}

	return result;
}

int main() {
	vector<int> nums{1, 2, 3, 4, 5};
	int k{ 4 };
	int x{ 3 };

	vector<int> sol{ findClosestElements(nums, k, x) };
	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) cout << *it << " ";

	return 0;
}
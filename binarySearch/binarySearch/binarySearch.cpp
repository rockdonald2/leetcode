#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1 , mid;

	while (left <= right) {
		// kiválasztjuk a középső elemet
		mid = ((left + right + 1) % 2 != 0) ? (left + right + 1) / 2 : (left + right + 1) / 2 - 1;

		// abban az esetben, ha ez lenne a keresett elem térítjük az indexét
		if (nums[mid] == target) return mid;
		// ha a keresett elem ennél kisebb akkor a bal oldalát kell megvizsgáljuk
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		// ha nagyobb akkor a jobb oldalát
		else {
			left = mid + 1;
		}
	}

	// ha nem találnánk az adott elemet
	return -1;
}

int main() {
	vector<int> nums{ -1, 0, 3, 5, 9, 12 };

	cout << search(nums, 5) << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
	if (nums.empty()) return -1;

	int left = 0, right = nums.size() - 1, mid;

	while (left < right) {
		mid = left + (right - left) / 2;

		// összemérve a középső és jobb oldali szélső értéket találjuk meg a minimumot
		// abban az esetben, ha a középső érték nagyobb, mint a jobb oldali, tudjuk, hogy minden bal oldali elem nagyobb, mint a minimum, ezért balról szűkülünk
		if (nums[mid] > nums[right]) left = mid + 1;
		// abban az esetben, ha a középső elem és a jobb oldali megegyezik, eggyel szűküljön, mert meglehet, hogy pont a duplikátum elemnél van forgatva
		else if (nums[mid] == nums[right]) --right;
		// abba az esetben, ha kisebb a középső elem, mint a jobb oldali, jobbról szűkülünk
		else right = mid;
	}

	if (left != nums.size()) return nums[left];
	else return -1;
}

int main() {
	vector<int> nums{ 3, 3, 1, 3 };

	cout << findMin(nums) << endl;

	return 0;
}
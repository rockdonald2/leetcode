#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int low, int high) {
	// a pivot jelenleg a legutolsó elem lesz, mindig
	int pivot = nums[high];

	// az első elemtől kezdve
	int i = low - 1;

	for (int j = low; j <= high - 1; ++j) {
		// abban az esetben, ha az adott elem kisebb, mint a pivot, megcseréljük az i elemmel
		if (nums[j] < pivot) {
			swap(nums[++i], nums[j]);
		}
	}

	// végül behelyezzük a megfelelő helyre a pivottot
	swap(nums[i + 1], nums[high]);

	return (i + 1);
}

void quickSort(vector<int>& nums, int low, int high) {
	if (low < high) {
		// alapvető alapja a partició függvény, amely a pivot elemet teszi a megfelelő helyére
		int pi = partition(nums, low, high);

		// rekurzív módon lehívjuk a pivot elem alatti intervallumra, és a fölötti intervallumra is
		quickSort(nums, low, pi - 1);
		quickSort(nums, pi + 1, high);
	}
}

int main() {
	vector<int> nums{ 10, 80, 30, 90, 40, 50, 70 };

	quickSort(nums, 0, nums.size() - 1);

	return 0;
}
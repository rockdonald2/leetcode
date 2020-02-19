#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); ++i) {
		// kezdve a második elemtől, lementjük a jelenleg vizsgált elem értékét, és inditunk egy j mutatót, ami a [0, i - 1] intervallumra fog mutatni
		int key = nums[i];
		int j = i - 1;

		// abban az esetben, ha egy adott j elem értéke nagyobb, mint a vizsgált elemé, minden alkalommal minden elemet eggyel jobbra tolunk
		while (j >= 0 && key < nums[j]) {
			nums[j + 1] = nums[j];
			j -= 1;
		}

		// majd behelyezzük az utolsó j elem helyére a vizsgált értéket
		nums[j + 1] = key;
	}
}

int main() {
	vector<int> nums{ 12, 11, 13, 5, 6 };

	insertionSort(nums);

	return 0;
}
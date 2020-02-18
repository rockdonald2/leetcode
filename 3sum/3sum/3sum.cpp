#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	// létrehozunk egy vektort, ami tartalmazza a végső tripleteket
	vector<vector<int>> result;

	// abban az esetben ha a parametér vektor kevesebb taggal rendelkezik, mint 3, akkor üres vektort térítünk
	if (nums.size() < 3) return vector<vector<int>>();

	// a kulcs, hogy rendezzük az vektort növekvő sorrendben
	sort(nums.begin(), nums.end());

	/*
	alapvetően az ötlet az, hogy kiválasztjuk az i. elemet, majd inicializáljuk a j-t és a k-t, amely a i utánadik, és az utolsó elemre mutat
	a j. és k. összege, pont a 0 - i. elem kell legyen, abban az esetben, ha a kettő összege kisebb, akkor az j. elemről lépünk tovább,
	ha nagyobb akkor a k-t csökkentsük
	*/
	for (int i = 0; i < nums.size() - 2; ++i) {
		if (i > 0 && nums[i] == nums[i - 1]) continue; // ha az előző i. elem, megegyezik a mostani ugorjuk át, mert már számításba vettük

		int wantedSum = 0 - nums[i];
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k) {
			int sum = nums[j] + nums[k];

			if (sum == wantedSum) {
				vector<int> triplet{ nums[i], nums[j], nums[k] };
				result.push_back(triplet);

				while (j < k && nums[j] == nums[j + 1]) ++j; // ha a következő elem megegyezik, ugorjuk át, már számításba vettük
				while (j < k && nums[k] == nums[k - 1]) --k;

				++j;
				--k;
			}
			else if (sum < wantedSum) {
				++j;
			}
			else {
				--k;
			}
		}
	}

	return result;
}

int main() {
	vector<int> nums{ -1, 0, 1, 2, -1, 4 };

	vector<vector<int>> results = threeSum(nums);

	for (int i = 0; i < results.size(); ++i) {
		for (int j = 0; j < results[i].size(); ++j) {
			cout << results[i][j] << " ";
		}
	}

	return 0;
}

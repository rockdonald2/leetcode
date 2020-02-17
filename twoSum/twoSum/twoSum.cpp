#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	/*unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); ++i) {
		m[i] = nums[i];
	}

	vector<int> sol{ -1, -1 };

	for (int i = 0, j = i + 1; i < m.size() - 1; ++j) {
		if (m.find(j) == m.end()) {
			if (j > m.size()) {
				break;
			}

			continue;
		}

		if (target - m[i] == m[j]) {
			sol[0] = i;
			sol[1] = j;

			break;
		}

		if (j == m.size() - 1) {
			++i;
			j = i;
		}
	}

	return sol;*/

	unordered_map<int, int> m;

	// átrendezzük az eredeti vector-t egy hashMap-be.
	for (int i = 0; i < nums.size(); ++i) {
		m[nums[i]] = i;
	}

	// inicializáljuk a terítendő vektort a két indexel
	vector<int> sol{ -1, -1 };

	// megkeressük a párját, azonban kétszer ugyanaz az index nem szerepelhet
	for (int j = 0; j < nums.size(); ++j) {
		if (m.find(target - nums[j]) == m.end() || m[target - nums[j]] == j) {
			continue;
		}

		sol[0] = j;
		sol[1] = m[target - nums[j]];
		break;
	}

	return sol;
}

int main() {
	vector<int> nums{ 3, 4, -3, 2 };
	int target{ 0 };

	vector<int> sol = twoSum(nums, target);

	for (int i = 0; i < sol.size(); ++i) {
		cout << sol[i] << " ";
	}

	cout << "\n";

	return 0;
}
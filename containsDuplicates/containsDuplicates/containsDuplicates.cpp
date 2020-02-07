#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool containsDuplicates(vector<int>& nums) {
    /*unordered_set<int> bucket;

    for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
        if (bucket.find(*it) == bucket.end()) {
            bucket.insert(*it);
        }
        else {
            return true;
        }
    }

    return false;*/

    sort(nums.begin(), nums.end());

    for (int i = 0, j = 1; j < nums.size(); ++j, ++i) {
        if (nums[i] == nums[j]) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> nums{ 1, 2, 3, 1 };

    cout << containsDuplicates(nums) << endl;

    return 0;
}
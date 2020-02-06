#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            temp[(i + k) % nums.size()] = nums[i];
        }

        for (int j = 0; j < nums.size(); ++j) {
            nums[j] = temp[j];
        }
    }
};

int main() {
    Solution sol;

    vector<int> sub{ 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;

    sol.rotate(sub, k);

    for (vector<int>::const_iterator it = sub.begin(); it != sub.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
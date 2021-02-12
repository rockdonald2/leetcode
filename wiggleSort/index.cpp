#include <iostream>
#include <vector>

using namespace std;

void wiggleSort(vector<int>& nums);

int main() {
    vector<int> arr{1};

    wiggleSort(arr);

    for (const auto &e : arr) {
        cout << e << ' ';
    }

    return 0;
}

void wiggleSort(vector<int>& nums) {
    auto maxElem{*max_element(nums.begin(), nums.end())};

    vector<int> freqArr(maxElem + 1, 0);

    for (const auto &e : nums) {
        freqArr[e]++;
    }

    int even{0};
    int odd{1};

    for (int i = maxElem; i >= 0; --i) {
        if (even >= nums.size() && odd >= nums.size()) {
            break;
        }

        while (freqArr[i] && (even < nums.size() || odd < nums.size())) {
            freqArr[i]--;

            if (odd < nums.size()) {
                nums[odd] = i;
                odd += 2;
            } else {
                nums[even] = i;
                even += 2;
            }
        }
    }
}
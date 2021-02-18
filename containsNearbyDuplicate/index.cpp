#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k);

int main() {
    vector<int> tmp{1, 0, 1, 1};
    const int k{1};

    cout << containsNearbyDuplicate(tmp, k) << '\n';

    return 0;
}

int binarySearch(const vector<int> &arr, const int &l, const int &r, const int &curr, const int &k) {
    if (l > r) {
        return -1;
    } else {
        int mid{l + (r - l) / 2};

        if (abs(arr[mid] - curr) <= k) {
            return mid;
        } else {
            return binarySearch(arr, l, mid - 1, curr, k);
        }
    }
}

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, vector<int>> cache{};

    for (size_t i = 0; i < nums.size(); ++i) {
        cache[nums[i]].push_back(i);
    }

    for (auto it{cache.begin()}; it != cache.end(); ++it) {
        if (it->second.size() <= 1) continue;
        else {
            for (int j{0}; j < it->second.size() - 1; ++j) {
                int m{binarySearch(it->second, j + 1, static_cast<int>(it->second.size()) - 1, it->second[j], k)};

                if (m != -1) {
                    return true;
                }
            }
        }
    }

    return false;
}
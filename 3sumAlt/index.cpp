vector<vector<int>> threeSum(vector<int> &nums) {
    if (!nums.size()) {
        return {};
    }
    
    sort(nums.begin(), nums.end());

    vector<vector<int>> r{};

    int i = 0;
    while (i < nums.size() - 1) {
        int j = i + 1;

        while (j < nums.size()) {
            int k{binarySearch(nums, j + 1, nums.size() - 1, -(nums[i] + nums[j]))};

            if (k != -1) {
                vector<int> tmp{nums[i], nums[j], nums[k]};

                bool found{false};
                int z{0};

                while (!found && z < r.size()) {
                    if (r[z] == tmp) {
                        found = true;
                    } else {
                        ++z;
                    }
                }

                if (!found) {
                    r.push_back(tmp);
                }
            }

            ++j;
        }

        ++i;
    }

    return r;
}

int binarySearch(vector<int> &nums, const int &l, const int &r, const int &k) {
    if (l > r) {
        return -1;
    } else {
        int m = l + (r - l) / 2;

        if (nums[m] == k) {
            return m;
        } else {
            if (nums[m] > k) {
                return binarySearch(nums, l, m - 1, k);
            } else {
                return binarySearch(nums, m + 1, r, k);
            }
        }
    }
}
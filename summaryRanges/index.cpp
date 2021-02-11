#include <iostream>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int> &nums);

int main() {
    vector<int> tmp{0, 1, 2, 4, 5, 7};

    auto r{summaryRanges(tmp)};

    for (const auto &e : r) {
        cout << e << '\n';
    }

    return 0;
}

vector<string> summaryRanges(vector<int> &nums) {
    vector<string> _st{};

    int i{0};
    while (i < nums.size()) {
        string _tmp{to_string(nums[i])};

        int j{i};
        while (j < (nums.size() - 1) && nums[j] + 1 == nums[j + 1]) {
            ++j;
        }

        if (j != i) {
            _tmp += "->" + to_string(nums[j]);
        }

        i = j + 1;

        _st.push_back(_tmp);
    }

    return _st;
}
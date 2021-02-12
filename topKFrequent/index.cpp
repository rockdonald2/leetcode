#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);
void makeHeap(vector<int> &keys, vector<int> &vals, const int &i);
void buildHeap(vector<int> &keys, vector<int> &vals);
int removeFromHeap(vector<int> &keys, vector<int> &vals);

int main() {
    vector<int> _tmp{1, 1, 1, 2, 2, 3};
    const int k{2};

    auto r{topKFrequent(_tmp, k)};

    for (const auto &e : r) {
        cout << e << ' ';
    }

    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq{};

    for (const auto &e : nums) {
        freq[e]++;
    }

    vector<int> keys{};
    keys.reserve(freq.size());
    vector<int> vals{};
    vals.reserve(freq.size());

    for (const auto &e : freq) {
        keys.push_back(e.first);
        vals.push_back(e.second);
    }

    buildHeap(keys, vals);

    vector<int> rArr{};
    rArr.reserve(k);

    for (int c = 1; c <= k; ++c) {
        rArr.push_back(removeFromHeap(keys, vals));
    }

    return rArr;
}

void makeHeap(vector<int> &keys, vector<int> &vals, const int &i) {
    int b{2 * i + 1};
    int j{2 * i + 2};

    int max{};
    if (b < keys.size() && vals[b] > vals[i]) {
        max = b;
    } else {
        max = i;
    }

    if (j < keys.size() && vals[j] > vals[max]) {
        max = j;
    }

    if (max != i) {
        swap(vals[i], vals[max]);
        swap(keys[i], keys[max]);
        makeHeap(keys, vals, max);
    }
}

void buildHeap(vector<int> &keys, vector<int> &vals) {
    for (int i = static_cast<int>(keys.size()) / 2 - 1; i >= 0; --i) {
        makeHeap(keys, vals, i);
    }
}

int removeFromHeap(vector<int> &keys, vector<int> &vals) {
    int tmp{keys[0]};

    keys[0] = keys[keys.size() - 1];
    vals[0] = vals[vals.size() - 1];
    keys.pop_back();
    vals.pop_back();

    makeHeap(keys, vals, 0);

    return tmp;
}
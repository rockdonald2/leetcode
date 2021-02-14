#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int longestPalindrome(string s);

int main() {
    cout << longestPalindrome("abccccdd") << '\n';

    return 0;
}

int longestPalindrome(string s) {
    unordered_map<char, int> freq{};

    for (const auto &c : s) {
        freq[c]++;
    }

    int r{0};
    for (const auto &c : freq) {
        r += (c.second / 2 * 2);

        if (r % 2 == 0 && c.second % 2 == 1) {
            r++;
        }
    }

    return r;
}
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using ull = unsigned long long;

string toHex(int num);

int main() {
    cout << toHex(-1) << '\n';

    return 0;
}

string toHex(int num) {
    if (num == 0) {
        return "0";
    }

    static unordered_map<int, char> hexCharacters {
            {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
            {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
            {10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}
    };

    ull tmp{};
    tmp = (num < 0 ? 4294967296 + num: num);
    string r{};

    while (tmp != 0) {
        r += hexCharacters[tmp % 16];
        tmp >>= 4;
    }

    reverse(r.begin(), r.end());
    return r;
}
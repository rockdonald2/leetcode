#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s);

int main() {
    cout << repeatedSubstringPattern("abab") << '\n';

    return 0;
}

bool repeatedSubstringPattern(string s) {
    string _tmp{s + s};
    string _match{_tmp.substr(1, _tmp.length() - 2)};

    if (_match.find(s) != -1) {
        return true;
    }

    return false;
}
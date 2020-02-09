#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }
}

int main() {
    vector<char> s{ 'a', 'p', 'p', 'l', 'e' };

    reverseString(s);

    for (vector<char>::const_iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it;
    }

    return 0;
}
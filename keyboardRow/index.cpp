#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> findWords(vector<string>& words);

int main() {
    vector<string> tmp{"Hello","Alaska","Dad","Peace"};

    auto r{findWords(tmp)};

    for (const auto &w : r) {
        cout << w << ' ';
    }

    return 0;
}

vector<string> findWords(vector<string>& words) {
    vector<string> keyboardRows{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    vector<string> r{};

    for (const auto &w : words) {
        int rowNumber{};
        bool foundRow{false};

        int i{0};
        while (i < keyboardRows.size() && !foundRow) {
            if (keyboardRows[i].find(tolower(w[0])) != string::npos) {
                rowNumber = i;
                foundRow = true;
            } else {
                ++i;
            }
        }

        string row{keyboardRows[rowNumber]};
        int j{1};
        bool ok{true};
        while (j < w.size() && ok) {
            if (row.find(tolower(w[j])) == string::npos) {
                ok = false;
            } else {
                ++j;
            }
        }

        if (ok) {
            r.push_back(w);
        }
    }

    return r;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
	if (s.length() != t.length()) return false;

	constexpr int MAX_CHAR{ 256 };
	vector<int> index(MAX_CHAR);
	vector<int> countS(MAX_CHAR);
	vector<int> countT(MAX_CHAR);

	for (int i = 0; i < MAX_CHAR; ++i) {
		index[i] = -1;
		countS[i] = 0;
		countT[i] = 0;
	}

	for (int j = 0; j < s.size(); ++j) {
		index[s[j]] = j;
		countS[s[j]] += 1;
		countT[t[j]] += 1;
	}

	for (int w = 0; w < t.size(); ++w) {
		if (index[t[w]] == -1) {
			return false;
		}
		else if (countS[t[w]] != countT[t[w]]) {
			return false;
		}
	}

	return true;
}

int main() {
	string s = "aaaabb";
	string t = "aabbbb";

	cout << isAnagram(s, t) << endl;

	return 0;
}
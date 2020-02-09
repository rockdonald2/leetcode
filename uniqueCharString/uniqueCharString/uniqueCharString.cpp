#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
	/*bool duplicate = false;

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s.size(); ++j) {
			if (s[i] == s[j] && i != j) {
				duplicate = true;
			}
		}

		if (!duplicate) {
			return i;
		}

		duplicate = false;
	}

	return -1;*/

	/*
	
	Alapvető ötletem most, hogy létrehozok 2 arrayt, egy count-ot és egy index-t, amely az adott char előfordulási számát (1 vagy 2(több)), a másik pedig az indexét tárolja (1 vagy n(nem érdekel minket))

	*/

	const int MAX_CHAR{ 256 };

	vector<int> count(MAX_CHAR);
	vector<int> index(MAX_CHAR);
	unsigned int n{s.length()};

	for (int i = 0; i < MAX_CHAR; ++i) {
		count[i] = 0;
		index[i] = n;
	}

	for (int j = 0; j < s.size(); ++j) {
		char x = s[j];
		++count[x];

		if (count[x] == 1 && x != ' ') {
			index[x] = j;
		}
		else if (count[x] == 2) {
			index[x] = n;
		}
	}

	sort(index.begin(), index.end());
	for (int w = 0; w < MAX_CHAR && index[w] != n; ++w) {
		return index[w];
	}

	return -1;
}

int main() {
	string s = "aaa";

	cout << firstUniqChar(s) << endl;

	return 0;
}
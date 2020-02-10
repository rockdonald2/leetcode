#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	/*if (s.length() == 0) return true;

	vector<char> v;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 65 && s[i] <= 90) {
			v.push_back(char(s[i] + 32));
		}
		else if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
			v.push_back(s[i]);
		}
	}

	if (v.size() == 0) {
		return true;
	}

	for (int k = 0, w = v.size() - 1; k < w; ++k, --w) {
		if (v[k] != v[w]) {
			return false;
		}
	}

	return true;*/

	// az isalnum algoritmus ellenőrzi, hogy ha a karakter betű/szám, és téríti bool-ként.
	// minden esetben figyelni kell arra, hogy az alsó index kisebb legyen mint a felső.

	if (s.length() == 0) return true;

	for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
		while (!isalnum(s[i]) && i < j) ++i;
		while (!isalnum(s[j]) && i < j) --j;

		if (toupper(s[i]) != toupper(s[j])) {
			return false;
		}
	}

	return true;
}

int main() {
	string s = "`l;`` 1o1 ??;l`";

	cout << isPalindrome(s) << endl;

	return 0;
}
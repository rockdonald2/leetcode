#include <iostream>
#include <string>
#include <algorithm>

char findDifference(std::string s, std::string t) {
	if (s.empty() && !t.empty()) return t[0];
	else if (s.empty() && t.empty()) return ' ';

	/*std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	int i = 0, j = 0;
	while (i == j && i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			++j;
			++i;
		}
		else {
			return t[j];
		}
	}

	if (j < t.length()) return t[j];
	else return ' ';*/

	int sumS = 0;
	for (int i = 0; i < s.size(); ++i) {
		sumS += s[i];
	}

	int sumT = 0;
	for (int j = 0; j < t.size(); ++j) {
		sumT += t[j];
	}

	return sumT > sumS ? sumT - sumS : sumS - sumT;
}

int main() {
	std::string s{ "a" };
	std::string t{ "aa" };

	std::cout << findDifference(s, t) << std::endl;

	return 0;
}
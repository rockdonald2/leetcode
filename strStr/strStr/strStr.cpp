#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
	if (needle.length() == 0) {
		return 0;
	}

	for (int i = 0, j = 0, k = 0; j < haystack.length(); ++j) {
		if (haystack[j] == needle[k]) {
			i = j;

			if ((i + needle.length() - 1) < haystack.length()) {
				while (haystack[i] == needle[k]) {
					++k;
					++i;

					if (k == needle.length()) {
						return j;
					}
				}

				k = 0;
			}
		}
	}

	return -1;
}

int main() {
	string haystack{ "mississippi" };
	string needle{ "issip" };

	cout << strStr(haystack, needle) << endl;

	return 0;
}
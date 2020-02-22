#include <iostream>
#include <string>
#include <vector>

using namespace std;

// téríti az első betüt, amely hiányzik a stringből
char missing(string& str) {
	/*vector<char> ascii(256);

	for (int i = 0; i < str.length(); ++i) {
		ascii[str[i]] = 1;
	}

	for (int j = str[0]; j < ascii.size(); ++j) {
		if (ascii[j] == 0) return j;
	}

	return NULL;*/

	for (int i = 0; i < str.length(); ++i) {
		if (i < str.length() - 1 && str[i] + 1 != str[i + 1]) return str[i] + 1;
	}

	return NULL;
}

int main() {
	string str{ "stvwx" };

	cout << missing(str) << endl;

	return 0;
}
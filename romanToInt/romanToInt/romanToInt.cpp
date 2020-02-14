#include <iostream>
#include <string>
#include <map>

using namespace std;

int romanToInt(string roman) {
	int sol = 0;

	map<char, int> romanValues; romanValues['M'] = 1000; romanValues['D'] = 500; romanValues['C'] = 100; romanValues['L'] = 50; romanValues['X'] = 10; romanValues['V'] = 5; romanValues['I'] = 1;

	for (int i = 0; i < roman.length(); ++i) {
		if (i < roman.length() - 1) {
			if (romanValues[roman[i]] < romanValues[roman[i + 1]]) {
				sol -= romanValues[roman[i]];
			}
			else {
				sol += romanValues[roman[i]];
			}
		}
		else {
			sol += romanValues[roman[i]];
		}
	}

	return sol;
}

int main() {
	string roman{ "XL" };

	cout << romanToInt(roman) << endl;

	return 0;
}
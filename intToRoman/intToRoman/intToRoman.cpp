#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

string intToRoman(int num) {
    vector<string> romanStr{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    vector<int> romanVals{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    string return_val{ "" };
    size_t iterator = 0;

    while (num > 0) {
        if ((num / romanVals[iterator]) > 0) {
            return_val.append(romanStr[iterator]);
            num -= romanVals[iterator];
        }
        else ++iterator;
    }

    return return_val;
}

int main() {
	int num{ 1994 };
	string return_str{ intToRoman(num) };

	cout << return_str << endl;

	return 0;
}
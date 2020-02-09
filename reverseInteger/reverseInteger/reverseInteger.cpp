#include <iostream>
#include <string>

using namespace std;

int reverse(int x) {
    int reversed = 0, remainder = 0;

    while (x != 0) {
        remainder = x % 10;
        x /= 10;

        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && remainder > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && remainder < -8)) return 0;

        reversed = reversed * 10 + remainder;
    }

    return reversed;
}

int main() {
	int x = 120;

	cout << reverse(x) << endl;

	return 0;
}
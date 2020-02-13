#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> sol(n);

	for (int i = 0; i < n; ++i) {
		string output = "";

		if ((i + 1) % 3 == 0) output += "Fizz";
		if ((i + 1) % 5 == 0) output += "Buzz";

		if (output == "") output = to_string(i + 1);

		sol[i] = output;
	}

	return sol;
}

int main() {
	vector<string> sol{ fizzBuzz(15) };

	for (vector<string>::const_iterator it = sol.begin(); it != sol.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}
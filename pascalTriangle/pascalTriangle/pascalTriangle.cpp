#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> pascal(numRows);

	for (int i = 0; i < numRows; ++i) {
		int j = 0;

		while (j < i + 1) {
			if (j > 0 && j < i) {
				int num = (pascal[i - 1][j - 1] + pascal[i - 1][j]);
				pascal[i].push_back(num);
			}
			else {
				pascal[i].push_back(1);
			}

			++j;
		}
	}

	return pascal;
}

int main() {
	int numRows = 20;

	vector<vector<int>> triangle = generate(numRows);

	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			cout << triangle[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	/*int rowLength = matrix.size();
	int colLength = matrix[0].size();

	for (int i = 0; i < rowLength; ++i) {
		for (int j = i + 1; j < colLength; ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	
	int mid = colLength / 2;
	bool flag = colLength % 2 == 0;
	for (int i = 0; i < rowLength; ++i) {
		for (int j = 0; j < mid; ++j) {
			int temp = matrix[i][j];
			int diff = mid - j;
			matrix[i][j] = matrix[i][mid + diff - flag];
			matrix[i][mid + diff - flag] = temp;
		}
	}*/

	// először megfordítjuk az mátrixot keresztbe, magyarán felcseréljük a sort az oszloppal
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i + 1; j < matrix[i].size(); ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	// következő lépésben, pedig felcseréljük az oszlopok sorrendjét
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size() / 2; ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][matrix[i].size() - 1 - j];
			matrix[i][matrix[i].size() - 1 - j] = temp;
		}
	}
}

int main() {
	vector<vector<int>> matrix(4);
	matrix[0] = { 1, 2, 3, 4 };
	matrix[1] = { 5, 6, 7, 8 };
	matrix[2] = { 9, 10, 11, 12 };
	matrix[3] = { 13, 14, 15, 16 };

	rotate(matrix);

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			cout << matrix[i][j] << " ";
		}

		cout << '\n';
	}

	return 0;
}
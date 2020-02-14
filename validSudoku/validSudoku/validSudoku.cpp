#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	for (int row = 0; row < board.size(); ++row) {
		for (int column = 0; column < board[row].size(); ++column) {
			char elem = board[row][column];

			if (elem == '.') continue;

			for (int i = 0; i < board[row].size(); ++i) {
				if (board[row][i] == elem && i != column) {
					return false;
				}
			}

			for (int j = 0; j < board.size(); ++j) {
				if (board[j][column] == elem && j != row) {
					return false;
				}
			}

			int x0 = (row / 3) * 3;
			int y0 = (column / 3) * 3;
			for (int x = x0; x < (x0 + 3); ++x) {
				for (int y = y0; y < (y0 + 3); ++y) {
					if (board[x][y] == elem && x != row && y != column) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main() {
	vector<vector<char>> board(9);
	vector<char> firstRow{ '5','3','.','.','7','.','.','.','.' };
	vector<char> secondRow{ '6','.','.','1','9','5','.','.','.' };
	vector<char> thirdRow{ '.','9','8','.','.','.','.','6','.' };
	vector<char> fourthRow{ '8','.','.','.','6','.','.','.','3' };
	vector<char> fifthRow{ '4','.','.','8','.','3','.','.','1' };
	vector<char> sixthRow{ '7','.','.','.','2','.','.','.','6' };
	vector<char> seventhRow{ '.','6','.','.','.','.','2','8','.' };
	vector<char> eighthRow{ '.','.','.','4','1','9','.','.','5' };
	vector<char> ninthRow{ '.','.','.','.','8','.','.','7','9' };
	board[0] = firstRow; board[1] = secondRow; board[2] = thirdRow; board[3] = fourthRow; board[4] = fifthRow; board[5] = sixthRow; board[6] = seventhRow; board[7] = eighthRow; board[8] = ninthRow;

	cout << isValidSudoku(board) << endl;

	return 0;
}
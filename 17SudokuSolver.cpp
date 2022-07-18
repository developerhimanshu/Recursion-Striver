#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>&board, int row, int col, int c) {
	for (int i = 0; i < 9; i++)
	{
		if (board[i][col] == c)
			return false;
		if (board[row][i] == c)
			return false;
		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
			return false;
	}
	return true;
}

bool solve(vector<vector<char>>&board) {
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == '.') {
				for (char c = '1'; c <= '9'; c++) {
					if (isValid(board, i, j, c)) {
						board[i][j] = c;
						if (solve(board))
							return true;
						else
							board[i][j] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}

void sudokuSolver(vector<vector<char>>&board) {
	solve(board);
}

int main()
{
	vector<vector<char>>board(9);
	for (int i = 0 ; i < 9; i++) {
		board[i] = vector<char>(9);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = '.';
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}
	sudokuSolver(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

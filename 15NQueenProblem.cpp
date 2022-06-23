class Solution {
public:
	bool isSafe(int row, int col, vector<string>board, int n) {
		int dupRow = row;
		int dupCol = col;

		while (row >= 0 && col >= 0) {
			if (board[row][col] == 'Q')return false;
			col--; row--;
		}

		col = dupCol;
		row = dupRow;

		while (col >= 0) {
			if (board[row][col] == 'Q')return false;
			col--;
		}

		col = dupCol;
		row = dupRow;

		while (row >= 0) {
			if (board[row][col] == 'Q')return false;
			row++;
			col--;
		}
		return true;
	}
public:
	void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n) {
		if (col >= n)
		{
			ans.push_back(board);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (isSafe(i, j, board, n)) {
				board[i][col] = 'Q'
				                solve(col + 1, board, ans, n);
				board[i][col] = '.';
			}
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string>board(n);
		string s(n, '.');
		for (int i = 0; i < n; i++) {
			board[i] = s;
		}
		vector<vector<string>>ans;
		solve(0, board, ans, n);
		return ans;
	}


}

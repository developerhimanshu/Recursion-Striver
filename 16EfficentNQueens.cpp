/*
 => We are using hasing for finding the safe position to place the queen.
 => For checking the left direction we will use simple n size hashed array and do the hash[row] is true or not
 => For checking to the lower diagonal we will use 2*n-1 sized hashed array and each element have row+col and check weather hash[row+col] is true or not
 => For checking to the upper diagonal we will use 2*n-1 sized hashed array and each element have (n-1)+col-row there we will check weather hash[n-1 + col-row] is true or not

*/


class Solution {
public:
    void nQueens(int col, vector<string>&board, vector<vector<string>>&ans, int n, vector<int>leftRow, vector<int>&lowerDiagonal, vector<int>&upperDiagonal) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + (col - row)] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + (col - row)] = 1;
                nQueens(col + 1, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + (col - row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n, '.');
        for (int i = 0; i < n ; i++) {
            board[i] = s;
        }
        vector<int>leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        nQueens(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

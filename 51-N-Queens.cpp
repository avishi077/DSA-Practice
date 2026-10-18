class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check left in the same row
        for (int j = col - 1; j >= 0; j--) {
            if (board[row][j] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check lower-left diagonal
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int col, int n,
               vector<vector<string>>& result) {
        // All columns have been processed
        if (col == n) {
            result.push_back(board);
            return;
        }

        // Try placing a queen in every row of this column
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';

                solve(board, col + 1, n, result);

                // Backtrack: remove the queen
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, n, result);

        return result;
    }
};
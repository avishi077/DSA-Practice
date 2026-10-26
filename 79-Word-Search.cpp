class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word,
               int r, int c, int index) {

        int rows = board.size();
        int cols = board[0].size();

        // Boundary check
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;

        // Character doesn't match, or cell already visited
        if (board[r][c] == '#' || board[r][c] != word[index])
            return false;

        // Entire word matched
        if (index == word.size() - 1)
            return true;

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all four directions
        bool found = solve(board, word, r - 1, c, index + 1) ||
                     solve(board, word, r + 1, c, index + 1) ||
                     solve(board, word, r, c - 1, index + 1) ||
                     solve(board, word, r, c + 1, index + 1);

        // Backtrack: restore the cell
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (solve(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
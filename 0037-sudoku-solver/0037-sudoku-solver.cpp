class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // ye last me lake return krega solution ko
    }

private:
    bool solve(vector<vector<char>>&board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d;
                            if (solve(board))
                                return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // if no digit fits here
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == d) return false;
            if (board[i][c] == d) return false;
        }
        int rowStart = (r / 3) * 3;
        int colStart = (c / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[rowStart + i][colStart + j] == d)
                    return false;
            }
        }
        return true;
    }
};

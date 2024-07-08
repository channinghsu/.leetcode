/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
    private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board) {

        for (int row = 0 ; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if(board[row][col] != '.') continue;
                for (char c = '1'; c <= '9'; ++c) {
                    if (!isValid(board,row,col,c)) continue;
                    board[row][col] = c;
                    if (dfs(board)) return true;
                    board[row][col] = '.';
                }
                return false;
            }
        }
    }

public:
        dfs(board);
        dfs(board,0,0);
        return;
    }
};
// @lc code=end


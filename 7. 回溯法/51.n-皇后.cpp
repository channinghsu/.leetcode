/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> res;
    bool isValid(vector<string>& board, int row, int col) {
        // col ok
        for (int i = 0;i < row; ++i) {
            if (board[i][col] == 'Q'){
                return false;
            }
        }
    // 判断左上方是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // 判断右上方是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
        return true;
    }
    void dfs(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); ++col) {
            if (isValid(board,row,col)) {
                board[row][col] = 'Q';
                dfs(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return res;
        // 初始化棋盘
        vector<string> board(n, string(n,'.'));
        // 从第一行还是递归
        dfs(board, 0);
        return res;
    }
};
// @lc code=end


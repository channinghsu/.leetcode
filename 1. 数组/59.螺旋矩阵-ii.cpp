/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    int left = 0;
    int right = n - 1;
    int top = 0;
    int down = n - 1;
    int num = 1;

    while (num <= n * n) {
      // left->right
      for (int i = left; i <= right ; i++) {
        res[top][i] = num++;
      }
      top++;

      // up->down
      for (int i = top; i <= down; i++) {
        res[i][right] = num++;
      }
      right--;

      // right->left
      for (int i = right; i >= left; i--) {
        res[down][i] = num++;
      }
      down--;

      // down->up
      for (int i = down; i >= top; i--) {
        res[i][left] = num++;
      }
      left++;
    }
    return res;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
 public:
  int uniquePaths(int m, int n) {
    // dp 数组代表第[i][j]的格子的路径和
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++) {
      dp[i][1] = 1;
    }
    for (int j = 1; j <= n; j++) {
      dp[1][j] = 1;
    }

    for (int i = 2; i <= m; ++i) {
      for (int j = 2; j <= n; ++j) {
        dp[i][i] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};
// @lc code=end

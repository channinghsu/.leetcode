/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n / 2; i++) {
      for (int j = i * i; j <= n; j++) {
        dp[j] = min(dp[j], dp[j - i * i] + 1);
      }
    }
    return dp[n] == INT_MAX ? 1 : dp[n];
  }
};
// @lc code=end

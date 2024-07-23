/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // dp[j] 的含义：可以凑成 j 的最少的硬币个数
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int coin : coins) {
      for (int j = coin; j <= amount; j++) {
        if (dp[j - coin] != INT_MAX) {
          dp[j] = min(dp[j], dp[j - coin] + 1);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
// @lc code=end

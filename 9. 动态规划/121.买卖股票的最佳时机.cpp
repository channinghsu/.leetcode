/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

 // @lc code=start
 // 版本一
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    // 持有股票
    dp[0][0] = -prices[0];
    // 不持有股票
    dp[0][1] = 0;

    for (int i = 1; i < n; i++) {
      // 注意不是：dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      //因为股票只能买一次
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
    }

    return dp[n - 1][1];
  }
};
// @lc code=end

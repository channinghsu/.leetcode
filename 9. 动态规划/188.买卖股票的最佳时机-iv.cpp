/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

 // @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, 0));

        for (int i = 0; i < 2 * k; i++) {
            if (i % 2 == 0) {
                dp[0][i] = -prices[0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2 * k; ++j) {
                if (j % 2 == 0) {
                    dp[i][j] = max(dp[i - 1][j], (j == 0 ? 0 : dp[i - 1][j - 1]) - prices[i]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
            }
        }
        return dp[n - 1][2 * k - 1];
    }
};
// @lc code=end
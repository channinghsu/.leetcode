/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int num = prices[i+1] - prices[i];
        if (num > 0) {
            res+= num;
        }
    }
    return res;
  }
};
// @lc code=end

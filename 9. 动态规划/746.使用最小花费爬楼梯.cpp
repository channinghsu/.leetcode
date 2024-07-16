/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    vector<int> dp(size + 1, 0);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= size; i++) {
      dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    return dp[size];
  }
};
// @lc code=end

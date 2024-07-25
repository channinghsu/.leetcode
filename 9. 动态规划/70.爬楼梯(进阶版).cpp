/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

 // @lc code=start
class Solution {
public:
  int climbStairs(int n) {
    // 转化为背包问题
    // dp[j]：总台阶为 j 的不同的方法和
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    // 排列问题:要先遍历背包，在遍历物品
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < 3; j++) {
        if (i - j >= 0) {
          dp[i] += dp[i - j];
        }
      }
    }

    return dp[n];
  }
};
// @lc code=end

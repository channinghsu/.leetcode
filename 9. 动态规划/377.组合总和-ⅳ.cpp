/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    // dp[j]: target 为 i 的 组合总数
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= target; j++) {
      for (int num : nums) {
        if (j - num >= 0 && dp[j] < INT_MAX - dp[j - num]) {
            dp[j] += dp[j - num];
        }
      }
    }
    return dp[target];
  }
};
// @lc code=end

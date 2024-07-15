/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // 第 i 个位置的最大子数组和
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = nums[0];

    int res = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      res = res < dp[i] ? dp[i] : res;
    }

    return res;
  }
};
// @lc code=end

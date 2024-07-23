/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    // dp[j] : 代表有 j 个房屋，能偷到的最多的钱
    vector<int> dp(nums.size() + 1, 0);

    if (nums.size() == 1) return nums[0];

    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);


    for (int j = 2; j < nums.size(); j++) {
      dp[j] = max(dp[j - 1], dp[j - 2] + nums[j]);
    }
    return dp[nums.size() - 1];
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    // p 正数的和
    // sum - p 负数的和
    // p - (sum - p) = target
    // 2p-sum = target
    // p = (target+sum)/2
    // 从数组里选出一些数的和恰好为 (target+sum)/2

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < S || (sum + S) % 2) return 0;
    int target = (sum + S) / 2;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num : nums) {
      for (int j = target; j >= num; j--) {
        dp[j] += dp[j - num];
      }
    }
    return dp[target];
  }
};
// @lc code=end

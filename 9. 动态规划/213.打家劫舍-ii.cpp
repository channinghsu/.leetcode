/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

 // @lc code=start
class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robb(0, n - 2, nums), robb(1, n - 1, nums));
  }

  int robb(int start, int end, vector<int>& nums) {
    if (start == end) return nums[start];
    vector<int> dp(nums.size(), 0);

    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);

    for (int i = start + 2; i <= end; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[end];
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& nums) {
    int res = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        res += nums[i] - nums[i - 1];
      }
    }
    return res;
  }
};
// @lc code=end

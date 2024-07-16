/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int res = INT_MAX;

    while (right < nums.size()) {
      sum += nums[right];
      while (sum >= target) {
        res = min(res, right - left + 1);
        sum -= nums[left];
        left++;
      }
      right++;
    }
    return res == INT_MAX ? 0 : res;
  }
  };
  // @lc code=end

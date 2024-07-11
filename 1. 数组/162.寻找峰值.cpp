/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int right = nums.size() - 1;
    int left = 0;
    while (left < right) {
      int mid = (left - right) / 2 + right;
      if (nums[mid] < nums[mid - 1]) {
        right = mid - 1;
      } else {
        left = mid;
      }
    }
    return right;
  }
};

// @lc code=end

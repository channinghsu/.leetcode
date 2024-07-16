/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    vector<int> res(nums.size());
    int pos = right;

    while (left <= right) {
      if (nums[left] * nums[left] > nums[right] * nums[right]) {
        res[pos--] = nums[left] * nums[left];
        left++;
      } else {
        res[pos--] = nums[right] * nums[right];
        right--;
      }
    }
    return res;
  }
};
// @lc code=end

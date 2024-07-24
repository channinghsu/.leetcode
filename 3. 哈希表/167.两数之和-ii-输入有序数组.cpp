/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int right = numbers.size() - 1;
    int left = 0;

    while (left < right) {
      int sum = numbers[right] + numbers[left];
      if (sum == target) {
        return {left + 1, right + 1};
      }
      sum > target ? right-- : left++;
    }
    return {};
  }
};
// @lc code=end

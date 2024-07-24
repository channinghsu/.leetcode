/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n; j++) {
        int left = j + 1;
        int right = n - 1;
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        while (left < right) {
          long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;
          } else if (sum > target) {
            right--;
          } else if (sum < target) {
            left++;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end

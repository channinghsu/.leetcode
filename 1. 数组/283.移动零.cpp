/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;

        int fast = 0;
        int slow = 0;

        while (fast < n) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
                fast++;
        }
        return;
    }
};
// @lc code=end




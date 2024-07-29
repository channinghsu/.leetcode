/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

 // @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();

        int res = 1;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            res = max(res, count);
        }
        return res;
    }
};
// @lc code=end


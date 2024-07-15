/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0]< b[0];
        });

        vector<vector<int>> res;
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (res.back()[1] >= nums[i][0]) {
                res.back()[1] = max(nums[i][1],res.back()[1]);
            }else {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end


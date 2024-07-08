/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used;
    void dfs(vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = 1;
            dfs(nums);
            path.pop_back();
            used[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        used = vector<int>(nums.size(),0);
        dfs(nums);
        return res;
    }
};
// @lc code=end

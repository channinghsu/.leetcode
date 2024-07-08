/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used;

    void dfs(vector<int> &nums) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (used[i] || i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        used = vector<int>(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }
};
// @lc code=end

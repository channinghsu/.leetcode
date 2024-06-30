/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void dfs(vector<int>& candidates, int target, int index) {

        if (sum > target)  return;
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] + sum <= target) {
                path.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, target, i);
                path.pop_back();
                sum -= candidates[i];
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        dfs(candidates, target, 0);
        return res;
    }
};
// @lc code=end


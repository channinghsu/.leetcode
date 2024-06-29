/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    private:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void dfs(int k, int n, int init) {
        if (path.size() == k && sum == n) {
            res.push_back(path);
            return;
        }

        for (int i = init; i <=9; ++i) {
            path.push_back(i);
            sum += i;
            dfs(k, n, i + 1);
            path.pop_back();
            sum -= i;
        }
        return;
    }
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};
// @lc code=end

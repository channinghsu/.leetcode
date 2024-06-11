/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracing(int n, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
                return;
            }
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtracing(n, k, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracing(n, k, 0, 1);
        return res;
    }
};
// @lc code=end

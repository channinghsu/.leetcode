/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        // unordered_set<int> uset;
        int used[201] = {0};//用数组来做哈希，提高效率。
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || /*uset.find(nums[i]) != uset.end()*/ used[nums[i]+100] == 1) {
                continue;
            }
            // uset.insert(nums[i]);
            used[nums[i]+100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

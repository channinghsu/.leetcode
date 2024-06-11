/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start

int startIndex;
class Solution {
    // 回溯三部曲
   public:
    vector<vector<<int>>> res;  // 返回结果的集合
    vector<int> path;         // 存放符合条件的结果
    [1,2,3,5,]
    void backtracing(int n, int k, int startIndex) {
        // 终止条件：符合结果
        if (path.size() == k) {
            res.push_back(path); // 存放到path
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { 
            path.push_back(i);
            backtracing(n, k, i + 1); // 递归
            path.pop_back(); // 回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracing(n,k,1);
        return res;
    }
};
// @lc code=end

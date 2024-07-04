/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;           // 存放当前递增子序列的路径
    vector<vector<int>> res;    // 存放所有符合条件的递增子序列

    void dfs(vector<int>& nums, int start) {
        int array[201]= {0};   // 使用数组做哈希表，范围是 [-100, 100]
        if (path.size() > 1)    // 当路径长度大于1时，将其加入结果集
            res.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            if (array[nums[i] + 100] || (!path.empty() && nums[i] < path.back())) {
                continue;       // 如果当前元素已经被使用过或者不满足递增条件，则跳过
            }
            array[nums[i] + 100]++; // 标记当前元素为已使用
            path.push_back(nums[i]); // 将当前元素加入路径
            dfs(nums, i + 1);        // 递归进入下一层
            path.pop_back();         // 回溯，撤销选择
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);   // 调用深度优先搜索函数开始查找递增子序列
        return res;     // 返回结果集
    }
};
// @lc code=end
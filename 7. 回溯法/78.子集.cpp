/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(const vector<int> &nums, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i){
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        res.clear();
        dfs(nums, 0);
        return res;
    }
};

// @lc code=end

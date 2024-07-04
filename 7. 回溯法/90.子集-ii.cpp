/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
  vector<int> path;
  // set<vector<int>> res;
  vector<vector<int>> res;

  void dfs(const vector<int>& nums, int start, vector<bool>& used) {
    // res.insert(path);
    res.push_back(path);
    for (int i = start; i < nums.size(); ++i)
    {
      // 不要加入之前已经递归的树，比如[1,2,3,3,3]
      // 当for 遍历到第 2 和第 3个 3 时，因为前面已经有过 3 了 ,之后就不用了
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }

      path.push_back(nums[i]);
      used[i] = true;
      dfs(nums, i + 1, used);
      used[i] = false;
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    dfs(nums, 0, used);
    // vector<vector<int>> resVec(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

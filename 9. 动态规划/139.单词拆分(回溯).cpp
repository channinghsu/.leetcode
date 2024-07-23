/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分 (time limit exceeded)
 */

// @lc code=start
class Solution {
 private:
  bool found = false;
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    dfs(s, wordDict, 0);
    return found;
  }
  void dfs(string s, vector<string>& wordDict, int start) {
    if (start == s.size()) {
      found = true;
      return;
    }

    for (int i = start; i < s.size(); i++) {
      string word = s.substr(start, i - start + 1);
      if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
        dfs(s, wordDict, i + 1);
      }
    }
  }
};
// @lc code=end

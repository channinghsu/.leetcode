/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<int> minCount(26, INT_MAX);

    for (string word : words) {
      vector<int> cur(26, 0);
      for (char c : word) {
        cur[c - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        minCount[i] = min(minCount[i], cur[i]);
      }
    }
    vector<string> res;

    for (int i = 0; i < 26; i++) {
      if (minCount[i] > 0) {
        res.insert(res.end(), minCount[i], string(1, i + 'a'));
      }
    }

    return res;
  }
};

/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> letter(26, 0);

    for (int i = 0; i < magazine.size(); i++) {
      letter[magazine[i] - 'a']++;
    }

    for (int i = 0; i < ransomNote.size(); i++) {
      if (--letter[ransomNote[i] - 'a'] < 0) return false;
    }

    return true;
  }
};
// @lc code=end

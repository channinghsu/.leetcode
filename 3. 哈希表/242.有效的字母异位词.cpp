/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> vec(26, 0);

    for (int i = 0; i < s.size(); i++) {
      vec[s[i] - 'a']++;
      vec[t[i] - 'a']--;
    }


    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
  public:
    bool isAnagram(string s, string t) {
        // 用数组记录s中各个字母出现的次数
        vector<int> record(26, 0);
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }

        // 计算t中各个字母出现的次数
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }

        // 看数组中各个元素是不是都为0
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0)
                return false; // 要注意是 !=
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> record(26, 0);

        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.size(); i++) {
            // 通过recode数据记录 magazine里各个字符出现次数
            record[magazine.at(i) - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote.at(i) - 'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if (record[ransomNote.at(i) - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

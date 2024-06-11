/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    // 计算next数组
    void getNext(int* next, string& s){
        int j = -1;
        next[0] = j;
        for (int  i = 1; i < s.size(); i++){
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j+1]){
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int next [s.size()];
        getNext(next, s); 

        // 整个s的最长相同前后缀
        int len = next[s.size() - 1]; 
        // 数组长度-最长相等前后缀的长度
        int subStr = s.size() - (len + 1);
        
        if (len != -1 && s.size() % subStr == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end


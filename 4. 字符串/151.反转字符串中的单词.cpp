/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    // 反转字符串，要注意传引用
    void reverse(string& s, int start, int end){
        for (int i = start, j = end ; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
    // 移除多余空格
    void removeSpace(string& s){
        int slow = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ') {
                // 在单词前面加空格
                if (slow != 0) s[slow++] = ' ';
                // 将单词复制到s[slow]开始的位置 
                while (i < s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        // 移除空格
        removeSpace(s);
        // 把整个字符串反转
        reverse(s, 0, s.size() - 1);

        int start = 0;
        for (int i = 0; i <= s.size(); i++){
            if (i == s.size() || s[i] == ' '){
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end

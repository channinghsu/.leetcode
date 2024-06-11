/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        if (words.size() == 0) return res;
        
        vector<int> hash(26,0);
        // 统计第一个字符串字符的出现频率
        for (int i = 0; i < words[0].size(); i++){
            hash[words[0][i] - 'a']++;
        }
        // 统计除第一个字符串外字符的出现频率
        int hashOtherStr[26] = {0};
        for (int i = 1; i < words.size(); i++)
        {
            memset(hashOtherStr, 0, 26 * sizeof(int));
            for (int j = 0; j < words[i].size(); j++){
                hashOtherStr[words[i][j] - 'a']++;
            }
            // 更新hash，保证hash里统计26个字符在所有字符串里出现的最小次数
            for (int k = 0; k < 26; k++){
                hash[k] = min(hash[k], hashOtherStr[k]);
            }
        }
        // 添加hash[i]个当前字母到结果中并返回
        for (int i = 0; i < 26; i++){
                while (hash[i] != 0){
                    string s(1, i + 'a');
                    res.push_back(s);
                    hash[i]--;
                }
        }
        return res;
    }
};
// @lc code=end


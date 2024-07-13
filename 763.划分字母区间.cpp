/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    // 算出各个字母的数量
    int hash[27] = {0};  // i为字符，hash[i]为字符出现的最后位置
    for (int i = 0; i < s.size(); i++) {  // 统计每一个字符最后出现的位置
      hash[s[i] - 'a'] = i;
    }

    vector<int> res;
    int maxPos = 0;
    int partitionSize = 0;
    for (int i = 0; i < s.size(); i++) {
      maxPos = max(maxPos, hash[s[i] - 'a']);
      partitionSize++;
      if (maxPos == i) {
        res.push_back(partitionSize);
        partitionSize = 0;
      }
    }
    return res;
  }
};
// @lc code=end

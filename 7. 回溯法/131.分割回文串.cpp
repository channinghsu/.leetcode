/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
    private:
    vector<vector<string>> res;
    vector<string> path;
    bool isHuiWen(const string& s,int start, int end) {
        for (int i = start, j = end;i < j; i++,j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void dfs(const string& s, int start) {
        if (start >= s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isHuiWen(s,start,i)) {
                string str = s.substr(start, i - start + 1);
                path.push_back(str);
            } else {
                continue;
            }
            dfs(s, i + 1);
            path.pop_back();
        }
    }

    public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) {
            return res;
        }
        dfs(s, 0);
        return res;
    }
};
// @lc code=end

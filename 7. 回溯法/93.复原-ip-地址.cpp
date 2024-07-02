class Solution {
private:
vector<string> res;
bool isValid(const string& s, int start, int end) {
    if (start > end) return false;
    if (s[start] == '0' && start != end) return false;
    int num = 0;
    for (int i = start; i <=end; i++) {
        num = num * 10 + (s[i] - '0');
        if (num > 255) return false;
    }
    return true;
}

void dfs(string& s, int start, int dotNums) {
    if (dotNums == 3) {
        if(isValid(s, start, s.size()-1)) {
            res.push_back(s);
            return;
        }
    }
    for (int i = start; i < s.size(); ++i) {
        if(isValid(s,start,i)){
            s.insert(s.begin() + 1 + i, '.');
            dotNums++;
            dfs(s, i + 2, dotNums);
            s.erase(s.begin() + 1 + i);
            dotNums--;
        } else {
            break;
        }
    }
}
public:
    vector<string> restoreIpAddresses(string s) {
        // 回溯：字符串 s, 起始位置，'s'的数量(判断最终结果)
        dfs(s, 0, 0);
        return res;
    }
};
// @lc code=end

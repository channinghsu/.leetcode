/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;

    void dfs(const string& from) {
        auto& dests = graph[from];
        while (!dests.empty()) {
            string to = dests.top();  // 按字典序选择最小的目的地
            dests.pop();
            dfs(to);  // 继续从目的地出发进行DFS
        }
        result.push_back(from);  // 将当前节点加入结果路径中
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建图的邻接表，用优先队列保证目的地字典序最小
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        // 从 JFK 开始进行 DFS 遍历
        dfs("JFK");

        // 结果是反向存储的，需要翻转一下得到正向路径
        reverse(result.begin(), result.end());
        return result;
    }
};;
// @lc code=end


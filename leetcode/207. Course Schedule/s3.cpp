// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(E + V)
// Space: O(E + V)
class Solution {
    unordered_map<int, vector<int>> G;
    vector<int> seen;
    bool hasCircle(int u) {
        if (seen[u]) return seen[u] == -1;
        seen[u] = -1;
        for (int v : G[u]) {
            if (hasCircle(v)) return true;
        }
        seen[u] = 1;
        return false;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        for (auto e : E) G[e[1]].push_back(e[0]);
        seen.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            if (hasCircle(i)) return false;
        }
        return true;
    }
};
// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    unordered_map<int, vector<int>> next;
    vector<bool> seen;
    bool hasCircle(int u) {
        if (seen[u]) return true;
        seen[u] = true;
        auto &n = next[u];
        for (int i = n.size() - 1; i >= 0; --i) {
            if (hasCircle(n[i])) return true;
            n.pop_back();
        }
        return seen[u] = false;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        for (auto e : E) next[e[1]].push_back(e[0]);
        seen.assign(N, false);
        for (int i = 0; i < N; ++i) {
            if (hasCircle(i)) return false;
        }
        return true;
    }
};
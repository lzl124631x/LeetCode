// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/lzl124631x
// Time: O(V^3)
// Space: O(V^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& A, vector<vector<int>>& Q) {
        vector<vector<bool>> m(n, vector<bool>(n));
        for (auto &e : A) m[e[0]][e[1]] = true;
        for (int i = 0; i < n; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    m[u][v] = m[u][v] || (m[u][i] && m[i][v]);
                }
            }
        }
        vector<bool> ans;
        for (auto &q : Q) ans.push_back(m[q[0]][q[1]]);
        return ans;
    }
};
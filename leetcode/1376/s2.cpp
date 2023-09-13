// OJ: https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> m; // manager => subordinates
    int dfs(int id, vector<int>& time) {
        int ans = 0;
        for (int n : m[id]) ans = max(ans, dfs(n, time));
        return time[id] + ans;
    } 
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        m.resize(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] == -1) continue;
            m[manager[i]].push_back(i);
        }
        return dfs(headID, informTime);
    }
};
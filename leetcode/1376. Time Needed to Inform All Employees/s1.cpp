// OJ: https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> m; // manager => subordinates
        for (int i = 0; i < n; ++i) m[manager[i]].push_back(i);
        queue<pair<int, int>> q;
        int ans = 0;
        q.emplace(headID, informTime[headID]);
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto p = q.front();
                q.pop();
                ans = max(ans, p.second);
                for (int sub : m[p.first]) q.push({ sub, p.second + informTime[sub] });
            }
        }
        return ans;
    }
};
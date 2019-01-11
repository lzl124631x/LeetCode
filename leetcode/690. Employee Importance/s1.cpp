// OJ: https://leetcode.com/problems/employee-importance/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    unordered_map<int, Employee*> m;
    int collect(int id) {
        auto e = m[id];
        int ans = e->importance;
        for (auto &s : e->subordinates) ans += collect(s);
        return ans;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto &e : employees) m[e->id] = e;
        return collect(id);
    }
};
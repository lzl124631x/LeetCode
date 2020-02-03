// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &c, int t, int start, vector<int> &v) {
        if (!t) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < c.size() && t >= c[i]; ++i) {
            v.push_back(c[i]);
            dfs(c, t - c[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(candidates, target, 0, v);
        return res;
    }
};
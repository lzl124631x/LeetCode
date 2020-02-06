// OJ: https://leetcode.com/problems/combination-sum-iii/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    vector<vector<int>> ans;
    void dfs(int k, int n, int start, vector<int> &tmp) {
        if (!k || !n) {
            if (!k && !n) ans.push_back(tmp);
            return;
        }
        for (int i = start; i <= min(9, n); ++i) {
            tmp.push_back(i);
            dfs(k - 1, n - i, i + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(k, n, 1, tmp);
        return ans;
    }
};
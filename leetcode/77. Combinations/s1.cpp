// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/lzl124631x
// Time: O(K!)
// Space: O(K)
class Solution {
    vector<vector<int>> ans;
    void dfs(int n, int k, int start, vector<int> &tmp) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start, end = n - k + tmp.size(); i <= end; ++i) {
            tmp.push_back(i + 1);
            dfs(n, k, i + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(n, k, 0, tmp);
        return ans;
    }
};